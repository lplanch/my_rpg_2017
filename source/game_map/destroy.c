/*
** EPITECH PROJECT, 2018
** delete.c
** File description:
** delete file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void destroy_pnj(st_rpg *s)
{
	int i = 0;

	while (i != fi->max_pnj) {
		destroy_object(fi->pnj[i].pnj);
		free(fi->pnj[i].name);
		i++;
	}
}

void destroy_sprite(st_rpg *s)
{
	sfSprite_destroy(fi->map.sprite);
	sfSprite_destroy(fi->map.sprite2);
	sfSprite_destroy(fi->map.sprite3);
	sfSprite_destroy(fi->map.sprite4);
	sfSprite_destroy(fi->map.sprite5);
}

void destroy_texture(st_rpg *s)
{
	sfTexture_destroy(fi->map.texture);
	sfTexture_destroy(fi->map.texture2);
	sfTexture_destroy(fi->map.texture3);
	sfTexture_destroy(fi->map.texture4);
	sfTexture_destroy(fi->map.texture5);
}

void destroy(st_rpg *s)
{
	sfImage_destroy(fi->map.image);
	sfImage_destroy(fi->map.map_backgound);
	sfImage_destroy(fi->map.map_relief);
	sfImage_destroy(fi->map.map_col);
	sfImage_destroy(fi->map.map_colID);
	sfImage_destroy(fi->map.map_prof);
	destroy_sprite(s);
	destroy_texture(s);
	destroy_pnj(s);
	destroy_object(fi->characters);
	destroy_object(fi->ID_characters);
	destroy_object(fi->loading);
	sfClock_destroy(fi->time.clock);
	sfClock_destroy(fi->clock);
	free_all(s);
	sfRenderWindow_destroy(fi->window);
}
