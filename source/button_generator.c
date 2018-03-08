/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

st_button *create_button(char *str, sfVector2f pos, sfIntRect rect, sfColor c)
{
       st_button *button = malloc(sizeof(st_button));

       button->text = create_text(str, pos, "images/button.ttf");
       button->obj = create_object("images/void.png", pos, rect, 0);
	sfText_setColor(button->text->text, c);
       sfText_setCharacterSize(button->text->text, 100);
       return (button);
}

void destroy_button(st_button *button)
{
       destroy_text(button->text);
       destroy_object(button->obj);
       free(button);
}
