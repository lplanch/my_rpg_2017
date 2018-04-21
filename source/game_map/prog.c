/*
** EPITECH PROJECT, 2018
** prog.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void create(st_rpg *s)
{
	character_setup(s);
	pnj_setup(s);
	setup_variable(s);
	setup_loading(s);
}

int prog(st_rpg *s)
{
	struct stat a;

	if (stat("TestMap/parsing", &a) == -1)
		return (0);
	create(s);
	parsing(a, s);
	create_map(s);
	while (sfRenderWindow_isOpen(s->window)) {
		game(s);
		sfRenderWindow_close(s->window);
	}
	destroy(s);
	return (0);
}
