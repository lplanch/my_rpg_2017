/*
** EPITECH PROJECT, 2018
** prog.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

sfRenderWindow* window_create(files_t *fi, char *name)
{
	sfVideoMode window2 = {1920, 1080, 32};
	fi->window = sfRenderWindow_create(window2, name, sfClose, NULL);
	return (0);
}

void create2(files_t *fi)
{
	characters_setup(fi);
}

void create(files_t *fi)
{
	window_create(fi, "my_rpg");
	create2(fi);
}

int prog(void)
{
	int o = 0;
	files_t fi;

	create(&fi);
	while (sfRenderWindow_isOpen(fi.window)) {
		game(&fi);
		sfRenderWindow_close(fi.window);
	}
	//destroy(&fi);
	return (0);
}
