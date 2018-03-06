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
//              destroy_object(s->mainm.hole[i]);
       }
}

void initialize_menu(st_rpg *s)
{
       s->mainm.first = create_object("images/menu/first.png",
       create_vector2f(0, 0), create_rect(0, 0, 1920, 1080), 5);
       s->mainm.rope = create_object("images/menu/ropesheet.png",
       create_vector2f(200, 0), create_rect(0, 0, 72, 1080), 0);
       for (int i = 0; i != 2; i += 1) {
              s->mainm.rockback[i] = create_object("images/menu/RockCave.png",
       create_vector2f(0, 2936 * i), create_rect(0, 0, 1920, 2936), 5);
//              s->mainm.hole[i] = create_object("images/menu/holes.png",
//       create_vector2f(rand() % 1920 - 50, y + y * -i + rand() % 200),
//       create_rect(0, rand() % 3 * 50, 50, 100), 0);
//       sfSprite_setScale(s->mainm.hole[i]->sprite,
//       create_vector2f(2 + rand() % 6, 2 + rand() % 6));
       }
       s->mainm.t.sec = 0.0;
       s->mainm.t.clock = sfClock_create();
}

void vertical_movement_mainm(st_rpg *s)
{
       s->mainm.first->pos.y -= s->mainm.first->speed;
       sfSprite_setPosition(s->mainm.first->sprite, s->mainm.first->pos);
       for (int i = 0; i != 2; i += 1) {
              s->mainm.rockback[i]->pos.y -= s->mainm.rockback[i]->speed;
              if (s->mainm.rockback[i]->pos.y < -2936)
                     s->mainm.rockback[i]->pos.y = 2936;
              sfSprite_setPosition(s->mainm.rockback[i]->sprite,
              s->mainm.rockback[i]->pos);
       }
}

int main_menu(st_rpg *s)
{
       initialize_menu(s);
       if (main_menu_cutscene(s))
              return (0);
       while (sfRenderWindow_isOpen(s->window)) {
              if (event_main_menu(s))
                     break;
              vertical_movement_mainm(s);
              display_menu_background(s);
       }
       return (0);
}
