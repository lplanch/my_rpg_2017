/*
** EPITECH PROJECT, 2018
** create_fast_inventory.c
** File description:
** file to stock all functions about creating fast inv
*/

#include "my.h"
#include "procedural.h"

void create_fast_inventory_screen(ingame_t *ing)
{
	ing->finv.rect.width = 160;
	ing->finv.rect.height = 160;
	ing->finv.rect.left = 0;
	ing->finv.rect.top = 0;
	ing->finv.sprite = sfSprite_create();
	ing->finv.texture =
	sfTexture_createFromFile("ressources/fast_inv.png", NULL);
	sfSprite_setTextureRect(ing->finv.sprite, ing->finv.rect);
	sfSprite_setTexture(ing->finv.sprite, ing->finv.texture, sfTrue);
}
