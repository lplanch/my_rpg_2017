/*
** EPITECH PROJECT, 2018
** map_creation.c
** File description:
** map creation
*/

#include "my.h"
#include "../../include/procedural.h"

void increment_proc_struct(proc_t *proc)
{
	proc->map = my_calloc(sizeof(char *) * (map_height + 1));
	proc->proom = my_calloc(sizeof(proom_t *) * (nbr_rooms + 1));
	for (int y = 0; y < map_height; y++) {
		proc->map[y] = my_calloc(sizeof(char) * (map_width + 1));
		for (int x = 0; x < map_width; x++) {
			proc->map[y][x] = '#';
		}
	}
}

proc_t *map_creation(void)
{
	proc_t *proc = malloc(sizeof(proc_t));

	srand((long)&proc);
	increment_proc_struct(proc);
	make_positions_proom(proc);
	for (int i = 0; proc->proom[i] != NULL; i++) {
		make_holes(proc->proom[i], proc->map, i);
	}
	create_entry(proc);
	create_leave(proc);
	make_map_better(proc->map);
	return (proc);
}
