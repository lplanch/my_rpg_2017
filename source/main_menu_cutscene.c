/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void display_menu_background(st_rpg *s)
{
       sfRenderWindow_clear(s->window, sfBlack);
       for (int i = 1; i != -1; i -= 1) {
              sfRenderWindow_drawSprite(s->window,
              s->mainm.rockback[i]->sprite, NULL);
//              sfRenderWindow_drawSprite(s->window,
//              s->mainm.hole[i]->sprite, NULL);
       }
       sfRenderWindow_drawSprite(s->window, s->mainm.first->sprite, NULL);
       sfRenderWindow_drawSprite(s->window, s->mainm.rope->sprite, NULL);
       sfRenderWindow_display(s->window);
}

int event_main_menu_cutscene(st_rpg *s)
{
       sfEvent event;

       while (sfRenderWindow_pollEvent(s->window, &event)) {
              if (event.type == sfEvtClosed) {
                     destroy_main_menu(s);
                     return (1);
              }
       }
       return (0);
}

void rope_animation(st_rpg *s)
{
       s->mainm.t.time = sfClock_getElapsedTime(s->mainm.t.clock);
       s->mainm.t.sec = s->mainm.t.time.microseconds / 1000000.0;
       if (s->mainm.t.sec > 0.1 && s->mainm.rope->rect.left < 950) {
              s->mainm.rope->rect.left += 70;
              sfSprite_setTextureRect(s->mainm.rope->sprite,
              s->mainm.rope->rect);
              sfClock_restart(s->mainm.t.clock);
       }
}

int main_menu_cutscene(st_rpg *s)
{
       while (sfRenderWindow_isOpen(s->window)) {
              if (event_main_menu_cutscene(s))
                     return (1);
              rope_animation(s);
              if (s->mainm.rope->rect.left > 950)
                     break;
              display_menu_background(s);
       }
       return (0);
}
