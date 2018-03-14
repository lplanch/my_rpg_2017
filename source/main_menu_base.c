/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

int get_max_buttons(st_rpg *s)
{
       if (s->mainm.menu > 2)
              return (3);
       return (2);
}

void destroy_main_menu(st_rpg *s)
{
       destroy_object(s->mainm.first);
       destroy_object(s->mainm.rope);
       destroy_object(s->mainm.cursor);
       for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
              destroy_button(s->mainm.button[i]);
       for (int i = 0; i != 2; i += 1) {
              destroy_object(s->mainm.rockback[i]);
              destroy_object(s->mainm.rock2[i]);
              destroy_object(s->mainm.abyss[i]);
       }
       sfClock_destroy(s->mainm.t.clock);
}

void initialize_menu_interface(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       s->mainm.menu = 0;
       s->mainm.sens = 1;
       s->mainm.option = 0;
       s->mainm.cursor = create_object("images/cursor.png",
       create_vector2f(700, 500), create_rect(0, 0, 100, 116), 2);
       s->mainm.button[0] = create_vbutton("Play", create_vector2f(800, 500),
       grey, 100);
       s->mainm.button[1] = create_vbutton("Options",
       create_vector2f(800, 620), grey, 100);
       s->mainm.button[2] = create_vbutton("Quit", create_vector2f(800, 740),
       grey, 100);
}

void initialize_menu(st_rpg *s)
{
       s->returnv = 0;
       s->mainm.first = create_object("images/menu/first.png",
       create_vector2f(0, 0), create_rect(0, 0, 1920, 1080), 6);
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
       initialize_menu_interface(s);
}

int left_clicked_on_buttons(st_rpg *s, sfEvent event)
{
       int max = 3;

       if (s->mainm.menu > 2)
              max += 1;
       for (int i = 0; i != max; i += 1) {
              if (event.type == sfEvtMouseButtonPressed &&
              sfMouse_isButtonPressed(sfMouseLeft) &&
              mouse_in_object(s->mainm.button[i]->obj, s->window))
                     return (1);
       }
       return (0);
}
