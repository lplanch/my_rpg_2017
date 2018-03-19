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
		if (proc->proom[i]->visited == 0 &&
		interval(posx, proc->proom[i]->pos1[0] + 1,
		proc->proom[i]->pos2[0] + 2) &&
		interval(posy, proc->proom[i]->pos1[1] + 1,
		proc->proom[i]->pos2[1] + 2)) {
			proc->proom[i]->visited = 1;
		}
		printf("visited[%d] : %d\n", i, proc->proom[i]->visited);
	}
}

void draw_room_minimap(proc_t *proc, proom_t *proom)
{
	int size[2] = {proom->width * 6, proom->height * 6};
	int pos[2] = {proom->pos1[0] * 6, proom->pos1[1] * 6};

	proom->drawed = 1;
	my_draw_rect(proc->minimap->f_minimap, pos, size, sfBlue);
}

void update_minimap(proc_t *proc)
{
	increment_visited(proc);
	for (int i = 0; proc->proom[i] != NULL; i++) {
		if (proc->proom[i]->visited && !proc->proom[i]->drawed)
			draw_room_minimap(proc, proc->proom[i]);
	}
}
