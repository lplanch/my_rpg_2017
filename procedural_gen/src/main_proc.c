/*
** EPITECH PROJECT, 2018
** main_proc.c
** File description:
** main_proc file for procedural gen
*/

#include "my.h"
#include "../include/procedural.h"

void print_help(void)
{
	my_putstr("USAGE\n");
	my_putstr("         ./proc\n\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("         Generate random custom map for a future RPG\n");
}

int main(int ac, char **av)
{
	gage_t *gage = malloc(sizeof(gage_t));

	if (ac == 2 && !my_strcmp(av[1], "-h")) {
		print_help();
	} else if (ac == 1) {
		gage->current_floor = 0;
		gage->max_floor = 10;
		gage->proc = map_creation();
		draw_map(gage);
	}
}
