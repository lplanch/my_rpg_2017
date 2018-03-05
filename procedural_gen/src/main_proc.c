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
	my_putstr("         ./proc [WIDTH] [HEIGHT] [NBR_ROOM]\n\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("         WIDTH HEIGHT    size of the map.\n");
	my_putstr("         NBR_ROOM        number of rooms in the map");
	my_putstr(" (max 9).\n");
}

int main(int ac, char **av)
{
	if (ac == 2 && !my_strcmp(av[1], "-h")) {
		print_help();
	} else if (ac == 4 && is_nbr(av[1]) && is_nbr(av[2]) && is_nbr(av[3])) {
		map_creation(str_to_int(av[1]), str_to_int(av[2]), str_to_int(av[3]));
	}
}
