/*
** EPITECH PROJECT, 2018
** camera_manager.c
** File description:
** camera main file to move camera
*/

#include "my.h"
#include "../../include/procedural.h"

void increment_camera(smap_t *smap, int x, int y)
{
	if (smap != NULL) {
		smap->pos.x += x;
		smap->pos.y += y;
		sfSprite_setPosition(smap->sprite, smap->pos);
	}
}

void move_camera_position(proc_t *proc, int px, int py)
{
	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++) {
			increment_camera(proc->smap[y][x], px, py);
		}
	}
}
