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
       if (s->mainm.menu > 2)
              sfRenderWindow_drawText(s->window,
              s->mainm.button[3]->text->text, NULL);

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

int which_main_menu(st_rpg *s)
{
       if (s->mainm.menu == 0)
              return (launch_main_menu_main(s));
       if (s->mainm.menu == 1)
              return (launch_main_menu_saves(s));
       if (s->mainm.menu == 2)
              return (launch_main_menu_options(s));
       if (s->mainm.menu == 3 || s->mainm.menu == 4)
              return (launch_main_menu_create_slots(s));
//       if (s->mainm.menu == 4)
//              return (launch_main_menu_load_slots(s));
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
