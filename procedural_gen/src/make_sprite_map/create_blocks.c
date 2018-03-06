/*
** EPITECH PROJECT, 2018
** create_blocks.c
** File description:
** make individual blocks
*/

#include "my.h"
#include "../../include/procedural.h"

void make_ground_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 16;
	smap->rect.top = 32;
	smap->rect.width = 16;
	smap->rect.height = 16;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}
