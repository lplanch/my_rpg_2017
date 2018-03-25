/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_projectile(sfRenderWindow *window, proj_t *proj)
{
	if (proj->shot) {
		sfRenderWindow_drawSprite(window, proj->obj->sprite, NULL);
	}
}
