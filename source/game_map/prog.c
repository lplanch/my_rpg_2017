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
	characters_setup(s);
	pnj_setup(s);
	setup_variable(s);
	setup_loading(s);
}

int prog(st_rpg *s)
{
	struct stat a;

	create(s);
	parsing(a, s);
	create_map(s);
	while (sfRenderWindow_isOpen(fi.window)) {
		game(s);
		sfRenderWindow_close(fi.window);
	}
	destroy(s);
	return (0);
}
