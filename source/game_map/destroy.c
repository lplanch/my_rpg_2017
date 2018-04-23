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

	while (i != s->fi->max_pnj) {
		destroy_object(s->fi->pnj[i].pnj);
		free(s->fi->pnj[i].name);
		i++;
	}
}

void destroy_sprite(st_rpg *s)
{
	sfSprite_destroy(s->fi->map.sprite);
	sfSprite_destroy(s->fi->map.sprite2);
	sfSprite_destroy(s->fi->map.sprite3);
	sfSprite_destroy(s->fi->map.sprite4);
	sfSprite_destroy(s->fi->map.sprite5);
}

void destroy_texture(st_rpg *s)
{
	sfTexture_destroy(s->fi->map.texture);
	sfTexture_destroy(s->fi->map.texture2);
	sfTexture_destroy(s->fi->map.texture3);
	sfTexture_destroy(s->fi->map.texture4);
	sfTexture_destroy(s->fi->map.texture5);
}

void destroy(st_rpg *s)
{
	sfImage_destroy(s->fi->map.image);
	sfImage_destroy(s->fi->map.map_backgound);
	sfImage_destroy(s->fi->map.map_relief);
	sfImage_destroy(s->fi->map.map_col);
	sfImage_destroy(s->fi->map.map_colID);
	sfImage_destroy(s->fi->map.map_prof);
	destroy_sprite(s);
	destroy_texture(s);
	destroy_pnj(s);
	destroy_object(s->fi->character);
	destroy_object(s->fi->ID_character);
	destroy_object(s->fi->loading);
	sfClock_destroy(s->fi->time.clock);
	sfClock_destroy(s->fi->clock);
	free_all(s);
}
