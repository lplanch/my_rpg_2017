/*
** EPITECH PROJECT, 2018
** map_creation.c
** File description:
** map creation
*/

#include "my.h"
#include "../include/procedural.h"

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

void make_hole(proc_t *proc)
{
	for (int i = 0; proc->proc_room[i] != NULL; i++) {
		proc->proc_room[i]->pos[0] = rand() % ((proc->width / 8) * 6) + (proc->width / 8);
		proc->proc_room[i]->pos[1] = rand() % ((proc->height / 6) * 4) + (proc->height / 6);
		printf("proc_room[%d][0] = %d, proc_room[%d][1] = %d\n", i, proc->proc_room[i]->pos[0], i, proc->proc_room[i]->pos[1]);
	}
}

void increment_proc_struct(proc_t *proc, int width, int height, int nbr_room)
{
	proc->map = (char **)my_calloc(sizeof(char *) * (height));
	proc->width = width;
	proc->height = height;
	proc->nbr_room = nbr_room;
	proc->proc_room = malloc(sizeof(proom_t *) * (nbr_room));
	for (int i = 0; i < nbr_room; i++) {
		proc->proc_room[i] = malloc(sizeof(proom_t));
	}
	proc->proc_room[nbr_room] = NULL;
	for (int y = 0; y < height; y++) {
		proc->map[y] = (char *)my_calloc(sizeof(char) * (width));
		for (int x = 0; x < width; x++) {
			proc->map[y][x] = '#';
		}
	}
}

int map_creation(int width, int height, int nbr_room)
{
	proc_t *proc = malloc(sizeof(proc_t));

	srand((long)&proc);
	increment_proc_struct(proc, width, height, nbr_room);
	make_hole(proc);
	print_map(proc->map);
}
