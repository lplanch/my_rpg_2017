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

void display_main_menu_interface(st_rpg *s)
{
       sfRenderWindow_drawText(s->window, s->mainm.button[0]->text->text, NULL);
       sfRenderWindow_drawText(s->window, s->mainm.button[1]->text->text, NULL);
       sfRenderWindow_drawText(s->window, s->mainm.button[2]->text->text, NULL);
       sfRenderWindow_drawSprite(s->window, s->mainm.cursor->sprite, NULL);
       if (s->mainm.menu > 2)
              sfRenderWindow_drawText(s->window,
              s->mainm.button[3]->text->text, NULL);

}

void initialize_menu_interface(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       s->mainm.menu = 0;
       s->mainm.sens = 1;
       s->mainm.option = 0;
       s->mainm.cursor = create_object("images/cursor.png",
       create_vector2f(900, 500), create_rect(0, 0, 100, 116), 2);
       s->mainm.button[0] = create_button("Play", create_vector2f(1000, 500),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.button[1] = create_button("Options", create_vector2f(1000, 620),
       create_rect(0, 0, 400, 100), grey);
       s->mainm.button[2] = create_button("Quit", create_vector2f(1000, 740),
       create_rect(0, 0, 400, 100), grey);
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

void main_menu_manage_cursor_events(st_rpg *s, sfEvent event)
{
       int max = get_max_buttons(s);

       if (event.type == sfEvtKeyPressed) {
              if (((sfKeyboard_isKeyPressed(sfKeyS) ||
              sfKeyboard_isKeyPressed(sfKeyDown)) && s->mainm.option < max)) {
                     s->mainm.cursor->pos.y += 120;
                     s->mainm.option += 1;
              } else if ((sfKeyboard_isKeyPressed(sfKeyZ) ||
              sfKeyboard_isKeyPressed(sfKeyUp)) && s->mainm.option > 0) {
                     s->mainm.cursor->pos.y -= 120;
                     s->mainm.option -= 1;
              }
       }
       for (int i = 0; i != max + 1; i += 1) {
              if (mouse_in_object(s->mainm.button[i]->obj, s->window)) {
                     s->mainm.cursor->pos.y = s->mainm.button[i]->obj->pos.y;
                     s->mainm.option = i;
              }
       }
}

int launch_main_menu_saves(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       if (s->mainm.option == 2) {
              s->mainm.menu = 0;
              for (int i = 0; i != 3; i += 1)
                     destroy_button(s->mainm.button[i]);
              s->mainm.button[0] = create_button("Play", create_vector2f(1000, 500),
              create_rect(0, 0, 400, 100), grey);
              s->mainm.button[1] = create_button("Options", create_vector2f(1000, 620),
              create_rect(0, 0, 400, 100), grey);
              s->mainm.button[2] = create_button("Quit", create_vector2f(1000, 740),
              create_rect(0, 0, 400, 100), grey);
       } else {
              s->mainm.menu = 3 + s->mainm.option;
              for (int i = 0; i != 3; i += 1)
                     destroy_button(s->mainm.button[i]);
              s->mainm.button[0] = create_button("Slot 1", create_vector2f(1000, 500),
              create_rect(0, 0, 400, 100), grey);
              s->mainm.button[1] = create_button("Slot 2", create_vector2f(1000, 620),
              create_rect(0, 0, 400, 100), grey);
              s->mainm.button[2] = create_button("Slot 3", create_vector2f(1000, 740),
              create_rect(0, 0, 400, 100), grey);
              s->mainm.button[3] = create_button("Back", create_vector2f(1000, 860),
              create_rect(0, 0, 400, 100), grey);
       }
       return (0);
}

int launch_main_menu_options(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       if (s->mainm.option == 0 || s->mainm.option == 1 || s->mainm.option == 2) {
              s->mainm.menu = 0;
              for (int i = 0; i != 3; i += 1)
                     destroy_button(s->mainm.button[i]);
              s->mainm.button[0] = create_button("Play", create_vector2f(1000, 500),
              create_rect(0, 0, 400, 100), grey);
              s->mainm.button[1] = create_button("Options", create_vector2f(1000, 620),
              create_rect(0, 0, 400, 100), grey);
              s->mainm.button[2] = create_button("Quit", create_vector2f(1000, 740),
              create_rect(0, 0, 400, 100), grey);
       }
       return (0);
}

int launch_main_menu_main(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       if (s->mainm.option == 0) {
              for (int i = 0; i != 3; i += 1)
                     destroy_button(s->mainm.button[i]);
              s->mainm.button[0] = create_button("Load save",
              create_vector2f(1000, 500), create_rect(0, 0, 600, 100), grey);
              s->mainm.button[1] = create_button("New game",
              create_vector2f(1000, 620), create_rect(0, 0, 600, 100), grey);
              s->mainm.button[2] = create_button("Back",
              create_vector2f(1000, 740), create_rect(0, 0, 400, 100), grey);
              s->mainm.menu = 1;
       } if (s->mainm.option == 1) {
              for (int i = 0; i != 3; i += 1)
                     destroy_button(s->mainm.button[i]);
              s->mainm.button[0] = create_button("C'etait",
              create_vector2f(1000, 500), create_rect(0, 0, 600, 100), grey);
              s->mainm.button[1] = create_button("Un",
              create_vector2f(1000, 620), create_rect(0, 0, 600, 100), grey);
              s->mainm.button[2] = create_button("Prank",
              create_vector2f(1000, 740), create_rect(0, 0, 400, 100), grey);
              s->mainm.menu = 2;
       } else if (s->mainm.option == 2)
              return (1);
       return (0);
}

int launch_main_menu_create_slots(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       if (s->mainm.option == 3) {
              s->mainm.option = 2;
              s->mainm.menu = 1;
              for (int i = 0; i != 4; i += 1)
                     destroy_button(s->mainm.button[i]);
              s->mainm.button[0] = create_button("Load save",
              create_vector2f(1000, 500), create_rect(0, 0, 600, 100), grey);
              s->mainm.button[1] = create_button("New game",
              create_vector2f(1000, 620), create_rect(0, 0, 600, 100), grey);
              s->mainm.button[2] = create_button("Back",
              create_vector2f(1000, 740), create_rect(0, 0, 400, 100), grey);
              s->mainm.cursor->pos.y = 740;
              sfSprite_setPosition(s->mainm.cursor->sprite, s->mainm.cursor->pos);
       }
       return (0);
}

int which_main_menu(st_rpg *s)
{
       if (s->mainm.menu == 0)
              return (launch_main_menu_main(s));
       if (s->mainm.menu == 1)
              return (launch_main_menu_saves(s));
       if (s->mainm.menu == 2)
              return (launch_main_menu_options(s));
       if (s->mainm.menu == 3)
              return (launch_main_menu_create_slots(s));
//       if (s->mainm.menu == 4)
//              return (launch_main_menu_load_slots(s));
       return (0);
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

int launch_main_menu(st_rpg *s, sfEvent event)
{
       if ((event.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyE)
       || sfKeyboard_isKeyPressed(sfKeyReturn)))
       || left_clicked_on_buttons(s, event)) {
              if (which_main_menu(s))
                     return (1);
       }
       return (0);
}

int event_main_menu(st_rpg *s)
{
       sfEvent event;

       while (sfRenderWindow_pollEvent(s->window, &event)) {
              if (event.type == sfEvtClosed || launch_main_menu(s, event)) {
                     destroy_main_menu(s);
                     return (1);
              }
              main_menu_manage_cursor_events(s, event);
       }
       return (0);
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
              // printf("Menu : %d \t Option : %d\n", s->mainm.menu, s->mainm.option);
              cursor_animation(s, 890, 910);
              main_menu_interface_animation(s);
              display_menu_background(s);
              display_main_menu_interface(s);
              sfRenderWindow_display(s->window);
       }
       return (0);
}
