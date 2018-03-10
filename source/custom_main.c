/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"

void destroy_cust_buttons(st_rpg *s)
{
       int i = cust_minx_buttons(s->cust.menu);

       while (i != cust_maxx_buttons(s->cust.menu) + 1) {
              destroy_button(s->cust.bt[i][1]);
              i += 1;
       }
}

void custom_destroy(st_rpg *s)
{
       destroy_object(s->cust.back);
       destroy_object(s->cust.cursor);
       destroy_object(s->cust.circle);
       destroy_cust_buttons(s);
}

void cust_cursor_animation(st_rpg *s)
{
       s->cust.cursor->pos.y += s->cust.sens;
       if (s->cust.cursor->pos.y > s->cust.cmax ||
              s->cust.cursor->pos.y < s->cust.cmin)
              s->cust.sens = -s->cust.sens;
       sfSprite_setPosition(s->cust.cursor->sprite, s->cust.cursor->pos);
}

void cust_menu_interface_animation(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       for (int i = 0; i != cust_get_buttons(s->cust.menu); i += 1)
              sfText_setColor(s->cust.bt[i][1]->text->text, grey);
       sfText_setColor(s->cust.bt[s->cust.optionx][1]->text->text, sfWhite);
}

void create_st_custom(st_rpg *s)
{
       sfColor grey = {96, 96, 96, 255};

       s->cust.sens = 0.25;
       s->cust.menu = 1;
       s->cust.optionx = 1;
       s->cust.optiony = 1;
       s->cust.cmin = 710;
       s->cust.cmax = 715;
       s->cust.circle = create_object("images/cust/circle.png",
       create_vector2f(300, 600), create_rect(0, 0, 520, 170), 0);
       s->cust.back = create_object("images/cust/bg.png",
       create_vector2f(0, 0), create_rect(0, 0, 1920, 1080), 0);
       s->cust.bt[0][1] = create_vbutton("Back to menu",
       create_vector2f(25, 880), grey, 70);
       s->cust.bt[1][1] = create_button("Male", create_object("images/void.png",
       create_vector2f(1100, 600), create_rect(0, 0, 300, 70), 0), grey, 70);
       s->cust.bt[2][1] = create_button("Female", create_object("images/void.png",
       create_vector2f(1400, 600), create_rect(0, 0, 400, 70), 0), grey, 70);
       s->cust.cursor = create_object("images/cursor.png",
       create_vector2f(1180, 710), create_rect(0, 0, 150, 150), 0);
       sfSprite_setScale(s->cust.cursor->sprite, create_vector2f(0.5, 0.5));
       sfSprite_setRotation(s->cust.cursor->sprite, -90);
}

void display_cust(st_rpg *s)
{
       sfRenderWindow_drawSprite(s->window, s->cust.back->sprite, NULL);
       sfRenderWindow_drawSprite(s->window, s->cust.circle->sprite, NULL);
       for (int i = 0; i != cust_get_buttons(s->cust.menu); i += 1)
              sfRenderWindow_drawText(s->window,
                     s->cust.bt[i][1]->text->text, NULL);
       sfRenderWindow_drawSprite(s->window, s->cust.cursor->sprite, NULL);
}

int cust_left_clicked(st_rpg *s, sfEvent event)
{
       for (int i = 0; i != cust_maxx_buttons(s->cust.menu); i += 1) {
              if (event.type == sfEvtMouseButtonPressed &&
              sfMouse_isButtonPressed(sfMouseLeft) &&
              mouse_in_object(s->cust.bt[i][1]->obj, s->window))
                     return (1);
       }
       return (0);
}

int cust_menu_backto_main(st_rpg *s)
{
       custom_destroy(s);
       s->mainm.option = 0;
       s->mainm.menu = 0;
       return (main_menu(s));
}

int launch_cust_menu_sex(st_rpg *s)
{
       if (s->cust.optionx == 0)
              return (cust_menu_backto_main(s));
       else {
              if (s->cust.optionx == 1)
                     s->cust.cdata.sex = 'M';
              else
                     s->cust.cdata.sex = 'F';
//              cust_menu_goto_name(s);
       }
       return (0);
}

int which_cust_menu(st_rpg *s)
{
       if (s->cust.menu == 1)
              return (launch_cust_menu_sex(s));
       return (0);
}

int custom_launch(st_rpg *s, sfEvent event)
{       if ((event.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyE)
       || sfKeyboard_isKeyPressed(sfKeyReturn)))
       || cust_left_clicked(s, event)) {
              if (which_cust_menu(s))
                     return (1);
       }
       return (0);
}

void get_cursor_pos(st_rpg *s)
{
       if (s->cust.menu == 1) {
              if (s->cust.optionx == 0) {
                     s->cust.cursor->pos.x = 330;
                     s->cust.cursor->pos.y = 850;
                     s->cust.rot = 90;
              } else {
                     s->cust.cursor->pos.x = 1180 + 330 * (s->cust.optionx - 1);
                     s->cust.cursor->pos.y = 710;
                     s->cust.rot = -90;
              }
              s->cust.cmin = s->cust.cursor->pos.y;
              s->cust.cmax = s->cust.cmin + 5;
       }
       sfSprite_setPosition(s->cust.cursor->sprite, s->cust.cursor->pos);
       sfSprite_setRotation(s->cust.cursor->sprite, s->cust.rot);
}

void custom_manage_cursor_events_key(st_rpg *s, sfEvent event)
{
       int maxx = cust_maxx_buttons(s->cust.menu);
       int minx = cust_minx_buttons(s->cust.menu);
       int maxy = cust_maxy_buttons(s->cust.menu);
       int miny = cust_miny_buttons(s->cust.menu);

//       printf("minx = %d, maxx = %d, miny = %d, maxy = %d\n", minx, maxx, miny, maxy);
//       printf("menu = %d, optionx = %d, optiony = %d\n", s->cust.menu, s->cust.optionx, s->cust.optiony);
       if (event.type == sfEvtKeyPressed) {
              if ((sfKeyboard_isKeyPressed(sfKeyS) ||
              sfKeyboard_isKeyPressed(sfKeyDown)) && s->cust.optiony < maxy)
                     s->cust.optiony += 1;
              if ((sfKeyboard_isKeyPressed(sfKeyZ) ||
              sfKeyboard_isKeyPressed(sfKeyUp)) && s->cust.optiony > miny)
                     s->cust.optiony -= 1;
              if ((sfKeyboard_isKeyPressed(sfKeyQ) ||
              sfKeyboard_isKeyPressed(sfKeyLeft)) && s->cust.optionx > minx)
                     s->cust.optionx -= 1;
              if ((sfKeyboard_isKeyPressed(sfKeyD) ||
              sfKeyboard_isKeyPressed(sfKeyRight)) && s->cust.optionx < maxx)
                     s->cust.optionx += 1;
              get_cursor_pos(s);
       }
}

void custom_manage_cursor_events_mouse(st_rpg *s)
{
       for (int i = 0; i != cust_get_buttons(s->cust.menu); i += 1) {
              if (mouse_in_object(s->cust.bt[i][1]->obj, s->window) &&
       s->mainm.option != i) {
                     s->mainm.option = i;
                     get_cursor_pos(s);
              }
       }
}

int custom_event(st_rpg *s)
{
       sfEvent event;

       while (sfRenderWindow_pollEvent(s->window, &event)) {
              if (event.type == sfEvtClosed) {
                     s->returnv = 1;
                     custom_destroy(s);
                     return (1);
              } if (custom_launch(s, event)) {
                     s->returnv = 1;
                     return (1);
              }
              custom_manage_cursor_events_key(s, event);
              custom_manage_cursor_events_mouse(s);
       }
       return (0);
}

int custom_main(st_rpg *s)
{
       create_st_custom(s);
       while (sfRenderWindow_isOpen(s->window)) {
              if (custom_event(s))
                     break;
              cust_cursor_animation(s);
              cust_menu_interface_animation(s);
              display_cust(s);
              sfRenderWindow_display(s->window);
       }
       return (s->returnv);
}
