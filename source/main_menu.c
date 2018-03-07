/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_main_menu(st_rpg *s)
{
       destroy_object(s->mainm.first);
       destroy_object(s->mainm.rope);
       for (int i = 0; i != 2; i += 1) {
              destroy_object(s->mainm.rockback[i]);
              destroy_object(s->mainm.rock2[i]);
              destroy_object(s->mainm.abyss[i]);
       }
}

void initialize_menu(st_rpg *s)
{
       s->mainm.first = create_object("images/menu/first.png",
       create_vector2f(0, 0), create_rect(0, 0, 1920, 1080), 5);
       s->mainm.rope = create_object("images/menu/ropesheet.png",
       create_vector2f(200, 0), create_rect(0, 0, 72, 1080), 0);
       for (int i = 0; i != 2; i += 1) {
              s->mainm.abyss[i] = create_object("images/menu/abyss2.png",
       create_vector2f(300 + 1400 * i , 5712 * i),
       create_rect(0, 0, 1920, 5712), 2);
              s->mainm.rockback[i] = create_object("images/menu/RockCave.png",
       create_vector2f(0, 2936 * i), create_rect(0, 0, 1920, 2936), 6);
              s->mainm.rock2[i] = create_object("images/menu/rock3.png",
       create_vector2f(110, 2236 * i), create_rect(0, 0, 1920, 2236), 4);
       }
       sfSprite_setScale(s->mainm.abyss[1]->sprite, create_vector2f(-1, 1));
       s->mainm.t.sec = 0.0;
       s->mainm.t.clock = sfClock_create();
}

int event_main_menu(st_rpg *s)
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

int main_menu(st_rpg *s)
{
       initialize_menu(s);
       if (main_menu_cutscene(s) == 1)
              return (0);
       while (sfRenderWindow_isOpen(s->window)) {
              if (event_main_menu(s))
                     break;
              vertical_movement_mainm(s);
              display_menu_background(s);
       }
       return (0);
}
