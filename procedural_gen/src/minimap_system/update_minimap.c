/*
** EPITECH PROJECT, 2018
** update_minimap.c
** File description:
** update minimap on screen
*/

#include "my.h"
#include "../../include/procedural.h"

void increment_visited(proc_t *proc)
{
	int posx = proc->gman->player.pos.x / 48;
	int posy = proc->gman->player.pos.y / 48;

	for (int i = 0; proc->proom[i] != NULL; i++) {
		if (interval(posx, proc->proom[i]->pos1[0] + 1, proc->proom[i]->pos2[0] + 2) &&
		interval(posy, proc->proom[i]->pos1[1] + 1, proc->proom[i]->pos2[1] + 2)) {
			proc->proom[i]->visited = 1;
		}
	}
}

void draw_room_minimap(proc_t *proc, proom_t *proom)
{
	proom->drawed = 1;
}

void update_minimap(proc_t *proc)
{
	increment_visited(proc);
	for (int i = 0; proc->proom[i] != NULL; i++) {
		if (proc->proom[i]->visited == 1)
			draw_room_minimap(proc, proc->proom[i]);
	}
}
