/*
** EPITECH PROJECT, 2018
** free_dungeon.c
** File description:
** free dungeon and everythings
*/

#include "my.h"
#include "../../include/procedural.h"

void free_sprite_map(smap_t *smap)
{
	if (smap != NULL) {
		sfSprite_destroy(smap->sprite);
		free(smap);
	}
}

void free_map_tbl(proc_t *proc)
{
	free_tbl(proc->map);
	for (int y = 0; proc->proom[y] != NULL; y++)
		free(proc->proom[y]);
	free(proc->proom);
	sfTexture_destroy(proc->blocks_texture);
}

void free_minimap(proc_t *proc)
{
	free(proc->minimap->f_background->pixels);
	free(proc->minimap->f_minimap->pixels);
	free(proc->minimap->f_background);
	free(proc->minimap->f_minimap);
	sfTexture_destroy(proc->minimap->fb_texture);
	sfTexture_destroy(proc->minimap->fm_texture);
	sfSprite_destroy(proc->minimap->fb_sprite);
	sfSprite_destroy(proc->minimap->fm_sprite);
	free(proc->minimap);
}

void free_dungeon(proc_t *proc)
{
	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++)
			free_sprite_map(proc->smap[y][x]);
		free(proc->smap[y]);
	}
	free(proc->smap);
	free_map_tbl(proc);
	//free_minimap(proc);
}

void free_gage_game(gage_t *gage)
{
	sfTexture_destroy(gage->proc->gman->player.texture);
	sfSprite_destroy(gage->proc->gman->player.sprite);
	sfRenderWindow_destroy(gage->proc->gman->window);
	sfClock_destroy(gage->proc->gman->clock);
	free(gage->proc->gman);
	free(gage->proc);
}
