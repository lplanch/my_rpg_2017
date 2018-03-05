/*
** EPITECH PROJECT, 2018
** verify_collide.c
** File description:
** verify if a rect is not too close from another
*/

#include "my.h"
#include "../include/procedural.h"

int verify_collide_room(proc_t *proc, proom_t *proc_room, int nbr)
{
	for (int i = 0; i < nbr; i++) {
		if ((proc_room->pos[0] < proc->proc_room[i]->pos[0] ||
		proc->proc_room[i]->pos[0] + proc->proc_room[i]->height < proc_room->pos[0]) &&
		(proc_room->pos[1] < proc->proc_room[i]->pos[1] ||
		proc->proc_room[i]->pos[1] + proc->proc_room[i]->width < proc_room->pos[1])) {
			my_putstr("ok");
		} else {
			my_putchar('\n');
			return (0);
		}
	}
	my_putchar('\n');
	return (1);
}
