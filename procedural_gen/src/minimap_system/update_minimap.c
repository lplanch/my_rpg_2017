/*
** EPITECH PROJECT, 2018
** update_minimap.c
** File description:
** update minimap on screen
*/

#include "my.h"
#include "procedural.h"

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
	}
}

void draw_room_minimap(proc_t *proc, proom_t *proom)
{
	proom->drawed = 1;
	for (int y = proom->pos1[1] + 1; y < proom->pos2[1] + 3; y++) {
		for (int x = proom->pos1[0] + 1; x < proom->pos2[0] + 3; x++) {
			draw_rect_room(proc, proom, x, y);
		}
	}
}

void make_corridors_minimap(proc_t *proc)
{
	sfColor white_trans = {255, 255, 255, 128};
	int p_pos[2] =
	{proc->gman->player.pos.x / 48, proc->gman->player.pos.y / 48};

	for (int y = p_pos[1] - 1; y < p_pos[1] + 2; y++) {
		for (int x = p_pos[0] - 1; x < p_pos[0] + 2; x++) {
			draw_rect_corridor(proc, x, y);
		}
	}
}

void update_minimap(proc_t *proc)
{
	sfVector2f text_center =
	{proc->gman->player.pos.x - (12 * 2),
	proc->gman->player.pos.y - HEIGHT / 5.5};

	increment_visited(proc);
	make_corridors_minimap(proc);
	sfText_setPosition(proc->minimap->current_level_text, text_center);
	for (int i = 0; proc->proom[i] != NULL; i++) {
		if (proc->proom[i]->visited && !proc->proom[i]->drawed)
			draw_room_minimap(proc, proc->proom[i]);
	}
	draw_rect_player(proc);
}
