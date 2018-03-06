/*
** EPITECH PROJECT, 2018
** map_creation.c
** File description:
** map creation
*/

#include "my.h"
#include "../../include/procedural.h"

void print_map(char **map)
{
	for (int y = 0; map[y] != NULL; y++) {
		for (int x = 0; map[y][x] != '\0'; x++) {
			my_putchar(map[y][x]);
			my_putchar(' ');
		}
		my_putchar('\n');
	}
}

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

void free_proc(proc_t *proc)
{
	free_tbl(proc->map);
	for (int y = 0; proc->proom[y] != NULL; y++)
		free(proc->proom[y]);
	free(proc->proom);
	free(proc);
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
	print_map(proc->map);
	free_proc(proc);
	return (proc);
}
