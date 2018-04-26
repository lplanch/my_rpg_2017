/*
** EPITECH PROJECT, 2018
** map_creation.c
** File description:
** map creation
*/

#include "my.h"
#include "procedural.h"

void increment_proc_struct(proc_var_t *pvar, proc_t *proc)
{
	proc->map = my_calloc(sizeof(char *) * (pvar->map_height + 1));
	proc->proom = my_calloc(sizeof(proom_t *) * (pvar->nbr_rooms + 1));
	for (unsigned int y = 0; y < pvar->map_height; y++) {
		proc->map[y] = my_calloc(sizeof(char) * (pvar->map_width + 1));
		for (unsigned int x = 0; x < pvar->map_width; x++)
			proc->map[y][x] = '#';
	}
}

void map_creation(gage_t *gage)
{
	increment_proc_struct(&gage->pvar, &gage->proc);
	make_positions_proom(gage, &gage->proc);
	for (int i = 0; gage->proc.proom[i] != NULL; i++) {
		make_holes(gage->proc.proom[i], gage->proc.map);
	}
	gage->proc.map = border_map(&gage->pvar, gage->proc.map);
	create_entry(&gage->proc);
	create_leave(&gage->proc);
	make_map_better(gage->proc.map);
	print_map(gage->proc.map);
}
