/*
** EPITECH PROJECT, 2018
** delete.c
** File description:
** delete file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void destroy_pnj(files_t *fi)
{
	int i = 0;

	while (i != fi->max_pnj) {
		destroy_object(fi->pnj[i].pnj);
		free(fi->pnj[i].name);
		i++;
	}
}

void destroy_sprite(files_t *fi)
{
	sfSprite_destroy(fi->map.sprite);
	sfSprite_destroy(fi->map.sprite2);
	sfSprite_destroy(fi->map.sprite3);
	sfSprite_destroy(fi->map.sprite4);
	sfSprite_destroy(fi->map.sprite5);
}

void destroy_texture(files_t *fi)
{
	sfTexture_destroy(fi->map.texture);
	sfTexture_destroy(fi->map.texture2);
	sfTexture_destroy(fi->map.texture3);
	sfTexture_destroy(fi->map.texture4);
	sfTexture_destroy(fi->map.texture5);
}

void destroy(files_t *fi)
{
	sfImage_destroy(fi->map.image);
	sfImage_destroy(fi->map.map_backgound);
	sfImage_destroy(fi->map.map_relief);
	sfImage_destroy(fi->map.map_col);
	sfImage_destroy(fi->map.map_colID);
	sfImage_destroy(fi->map.map_prof);
	destroy_sprite(fi);
	destroy_texture(fi);
	destroy_pnj(fi);
	destroy_object(fi->characters);
	destroy_object(fi->ID_characters);
	destroy_object(fi->loading);
	sfClock_destroy(fi->time.clock);
	sfClock_destroy(fi->clock);
	free_all(fi);
	sfRenderWindow_destroy(fi->window);
}
