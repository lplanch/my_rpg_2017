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
       destroy_button(s->mainm.button[0]);
       destroy_button(s->mainm.button[1]);
       for (int i = 0; i != 2; i += 1) {
              destroy_object(s->mainm.rockback[i]);
              destroy_object(s->mainm.rock2[i]);
              destroy_object(s->mainm.abyss[i]);
       }
       sfClock_destroy(s->mainm.t.clock);
}

void display_main_menu_interface(st_rpg *s)
{
       sfRenderWindow_drawText(s->window, s->mainm.button[0]->text->text, NULL);
       sfRenderWindow_drawText(s->window, s->mainm.button[1]->text->text, NULL);
       sfRenderWindow_drawSprite(s->window, s->mainm.cursor->sprite, NULL);
}

void initialize_menu_interface(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       s->mainm.sens = 1;
       s->mainm.option = 0;
       s->mainm.cursor = create_object("images/cursor.png",
       create_vector2f(900, 600), create_rect(0, 0, 100, 116), 2);
       s->mainm.button[1] = create_button("Quit", create_vector2f(1000, 750),
       create_rect(0, 0, 400, 400), grey);
       s->mainm.button[0] = create_button("Play", create_vector2f(1000, 600),
       create_rect(0, 0, 400, 400), grey);
}

void initialize_menu(st_rpg *s)
{
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

void main_menu_manage_cursor_events(st_rpg *s)
{
       if ((sfKeyboard_isKeyPressed(sfKeyDown) ||
       sfKeyboard_isKeyPressed(sfKeyS)) && s->mainm.option < 1) {
              s->mainm.cursor->pos.y += 150;
              s->mainm.option += 1;
       } else if ((sfKeyboard_isKeyPressed(sfKeyUp) ||
       sfKeyboard_isKeyPressed(sfKeyZ)) && s->mainm.option > 0) {
              s->mainm.cursor->pos.y -= 150;
              s->mainm.option -= 1;
       }
}

int event_main_menu(st_rpg *s)
{
       sfEvent event;

       while (sfRenderWindow_pollEvent(s->window, &event)) {
              if (event.type == sfEvtClosed) {
                     destroy_main_menu(s);
                     return (1);
              }
              main_menu_manage_cursor_events(s);
       }
       return (0);
}

void main_menu_interface_animation(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       sfText_setColor(s->mainm.button[0]->text->text, grey);
       sfText_setColor(s->mainm.button[1]->text->text, grey);
       sfText_setColor(s->mainm.button[s->mainm.option]->text->text, sfWhite);
}

void cursor_animation(st_rpg *s, int min, int max)
{
       int middle = min + ((min - max) / 2);

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
       return (0);
}
