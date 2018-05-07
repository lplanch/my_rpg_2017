/*
** EPITECH PROJECT, 2018
** create_fast_inventory.c
** File description:
** file to stock all functions about creating fast inv
*/

#include "my.h"
#include "my_rpg.h"

void create_fast_inventory_screen(ing_finv_t *finv)
{
	finv->rect.width = 230;
	finv->rect.height = 230;
	finv->rect.left = 0;
	finv->rect.top = 0;
	finv->sprite = sfSprite_create();
	finv->texture =
	sfTexture_createFromFile("ressources/fast_inv.png", NULL);
	sfSprite_setTextureRect(finv->sprite, finv->rect);
	sfSprite_setTexture(finv->sprite, finv->texture, sfTrue);
}
