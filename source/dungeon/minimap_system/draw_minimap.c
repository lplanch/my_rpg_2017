/*
** EPITECH PROJECT, 2018
** draw_minimap.c
** File description:
** file to stock all functions about drawing minimap
*/

#include "my.h"
#include "procedural.h"

void draw_rect_room(proc_t *proc, proom_t *proom, int x, int y)
{
	sfColor white_trans = {255, 255, 255, 128};
	sfColor red_trans = {183, 0, 0, 128};
	int size[2] = {6, 6};
	int pos[2];

	pos[0] = x * 6;
	pos[1] = y * 6;
	if (is_wall(proc->map[y][x])) {
		my_draw_rect(proc->minimap->f_minimap,
		pos, size, white_trans);
	} if (proc->map[y][x] == 'S' || proc->map[y][x] == 'B') {
		my_draw_rect(proc->minimap->f_minimap,
		pos, size, red_trans);
	}
}

void draw_rect_corridor(proc_t *proc, int x, int y)
{
	sfColor white_trans = {255, 255, 255, 128};
	int size[2] = {6, 6};
	int pos[2] = {x * 6, y * 6};

	if (is_wall(proc->map[y][x])) {
		my_draw_rect(proc->minimap->f_minimap, pos, size, white_trans);
	}
}

void draw_rect_player(proc_t *proc)
{
	sfColor green_trans = {0, 183, 0, 128};
	sfColor trans = {0, 0, 0, 0};
	int size[2] = {6, 6};
	int last_posx = proc->gman->player.last_pos.x / 48;
	int last_posy = proc->gman->player.last_pos.y / 48;
	int posx = proc->gman->player.pos.x / 48;
	int posy = proc->gman->player.pos.y / 48;

	my_draw_rect(proc->minimap->f_minimap,
	(int[2]){last_posx * 6, last_posy * 6}, size, trans);
	my_draw_rect(proc->minimap->f_minimap,
	(int[2]){posx * 6, posy * 6}, size, green_trans);
}
