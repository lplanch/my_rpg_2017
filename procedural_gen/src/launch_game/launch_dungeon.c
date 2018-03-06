/*
** EPITECH PROJECT, 2018
** launch_dungeon.c
** File description:
** launch the dungeon game
*/

#include "my.h"
#include "../../include/procedural.h"

gmanager_t *init_dungeon_game(proc_t *proc)
{
	gmanager_t *gman = malloc(sizeof(gmanager_t));

	gman->mode.width = WIDTH;
	gman->mode.height = HEIGHT;
	gman->mode.bitsPerPixel = 32;
	gman->window = sfRenderWindow_create(gman->mode, window_name, sfClose, NULL);
	gman->camera_pos = get_entry_pos(proc);
	gman->zoom = 0.2;
	gman->camera = sfRenderWindow_getDefaultView(gman->window);
	sfView_zoom(gman->camera, gman->zoom);
	sfView_setCenter(gman->camera, gman->camera_pos);
	sfRenderWindow_setView(gman->window, gman->camera);
	return (gman);
}

int draw_sprites_map(proc_t *proc)
{
	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++) {
			if (proc->smap[y][x] != NULL) {
				sfRenderWindow_drawSprite(proc->gman->window, proc->smap[y][x]->sprite, NULL);
			}
		}
	}
}

int update_sprite(proc_t *proc)
{
}

int launch_dungeon_game(proc_t *proc)
{
	proc->gman = init_dungeon_game(proc);
	while (sfRenderWindow_isOpen(proc->gman->window)) {
		verif_input_map(proc);
		update_sprite(proc);
		sfRenderWindow_clear(proc->gman->window, sfBlack);
		draw_sprites_map(proc);
		sfRenderWindow_display(proc->gman->window);
	}
}
