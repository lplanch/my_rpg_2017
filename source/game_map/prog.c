/*
** EPITECH PROJECT, 2018
** prog.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "game_map.h"

sfRenderWindow* window_create(files_t *fi, char *name)
{
	sfVideoMode window2 = {1920, 1080, 32};
	fi->window = sfRenderWindow_create(window2, name, sfClose, NULL);
	sfRenderWindow_setFramerateLimit(fi->window, 120);
	return (0);
}

void create2(files_t *fi)
{
	characters_setup(fi);
	pnj_setup(fi);
	setup_variable(fi);
	setup_loading(fi);
}

void create(files_t *fi)
{
	window_create(fi, "my_rpg");
	create2(fi);
}

int prog(void)
{
	files_t fi;
	struct stat a;

	if (stat("TestMap/parsing", &a) == -1) {
		return (0);
	}
	create(&fi);
	parsing(a, &fi);
	create_map(&fi);
	while (sfRenderWindow_isOpen(fi.window)) {
		game(&fi);
		sfRenderWindow_close(fi.window);
	}
	destroy(&fi);
	return (0);
}
