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
	characters_setup(fi);
	pnj_setup(fi);
	setup_variable(fi);
	setup_loading(fi);
}

int prog(st_rpg *s)
{
	struct stat a;

	create(s);
	parsing(a, &fi);
	create_map(&fi);
	while (sfRenderWindow_isOpen(fi.window)) {
		game(&fi);
		sfRenderWindow_close(fi.window);
	}
	destroy(&fi);
	return (0);
}
