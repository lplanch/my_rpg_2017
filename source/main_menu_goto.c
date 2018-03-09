/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void main_menu_goto_main(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       s->mainm.menu = 0;
       for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
              destroy_button(s->mainm.button[i]);
       s->mainm.button[0] = create_button("Play", create_vector2f(1000, 500),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.button[1] = create_button("Options", create_vector2f(1000, 620),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.button[2] = create_button("Quit", create_vector2f(1000, 740),
       create_rect(0, 0, 400, 100), grey);
}

void main_menu_goto_slots(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
              destroy_button(s->mainm.button[i]);
       s->mainm.button[0] = create_button("Slot 1", create_vector2f(1000, 500),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.button[1] = create_button("Slot 2", create_vector2f(1000, 620),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.button[2] = create_button("Slot 3", create_vector2f(1000, 740),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.button[3] = create_button("Back", create_vector2f(1000, 860),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.menu = 3 + s->mainm.option;
}

void main_menu_goto_saves(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
              destroy_button(s->mainm.button[i]);
       s->mainm.button[0] = create_button("Load save",
       create_vector2f(1000, 500), create_rect(0, 0, 600, 100), grey);
       s->mainm.button[1] = create_button("New game",
       create_vector2f(1000, 620), create_rect(0, 0, 600, 100), grey);
       s->mainm.button[2] = create_button("Back",
       create_vector2f(1000, 740), create_rect(0, 0, 400, 100), grey);
       s->mainm.menu = 1;
       if (s->mainm.option == 3) {
              s->mainm.cursor->pos.y = 740;
              sfSprite_setPosition(s->mainm.cursor->sprite,
              s->mainm.cursor->pos);
              s->mainm.option = 2;
       }
}

void main_menu_goto_options(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
              destroy_button(s->mainm.button[i]);
       s->mainm.button[0] = create_button("Sound",
       create_vector2f(1000, 500), create_rect(0, 0, 600, 100), grey);
       s->mainm.button[1] = create_button("Music",
       create_vector2f(1000, 620), create_rect(0, 0, 600, 100), grey);
       s->mainm.button[2] = create_button("Back",
       create_vector2f(1000, 740), create_rect(0, 0, 400, 100), grey);
       s->mainm.menu = 2;
}
