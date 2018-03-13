/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void display_main_menu_interface(st_rpg *s)
{
       sfRenderWindow_drawText(s->window, s->mainm.button[0]->text->text, NULL);
       sfRenderWindow_drawText(s->window, s->mainm.button[1]->text->text, NULL);
       sfRenderWindow_drawText(s->window, s->mainm.button[2]->text->text, NULL);
       sfRenderWindow_drawSprite(s->window, s->mainm.cursor->sprite, NULL);
       if (s->mainm.menu > 2) {
              sfRenderWindow_drawText(s->window,
              s->mainm.button[3]->text->text, NULL);
      }
}

void main_menu_interface_animation(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
              sfText_setColor(s->mainm.button[i]->text->text, grey);
       sfText_setColor(s->mainm.button[s->mainm.option]->text->text, sfWhite);
}

void cursor_animation(st_rpg *s, int min, int max)
{
       s->mainm.cursor->pos.x += s->mainm.sens;
       if (s->mainm.cursor->pos.x > max || s->mainm.cursor->pos.x < min)
              s->mainm.sens = -s->mainm.sens;
       sfSprite_setPosition(s->mainm.cursor->sprite, s->mainm.cursor->pos);
}

int main_menu(st_rpg *s)
{
       initialize_menu(s);
       if (main_menu_cutscene(s) == 1)
              return (0);
       while (sfRenderWindow_isOpen(s->window)) {
              if (event_main_menu(s))
                     break;
              movement_mainm(s);
              cursor_animation(s, 890, 910);
              main_menu_interface_animation(s);
              display_menu_background(s);
              display_main_menu_interface(s);
              sfRenderWindow_display(s->window);
       }
       return (s->returnv);
}
