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

void destroy(files_t *fi)
{
	sfImage_destroy(fi->testmap.image);
	sfImage_destroy(fi->testmap.testmap_backgound);
	sfImage_destroy(fi->testmap.testmap_col);
	sfImage_destroy(fi->testmap.testmap_tile3);
	sfSprite_destroy(fi->testmap.sprite);
	sfSprite_destroy(fi->testmap.sprite2);
	sfSprite_destroy(fi->testmap.sprite3);
	sfTexture_destroy(fi->testmap.texture);
	sfTexture_destroy(fi->testmap.texture2);
	sfTexture_destroy(fi->testmap.texture3);
	sfSprite_destroy(fi->sprite);
	sfSprite_destroy(fi->ID_sprite);
	sfTexture_destroy(fi->texture);
	sfTexture_destroy(fi->ID_text);
	sfRenderWindow_destroy(fi->window);
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
	struct stat a;

	if (stat("TestMap/parsing", &a) == -1) {
		return (0);
	}
	parsing(a, &fi);
	create(&fi);
	create_map(&fi);
	while (sfRenderWindow_isOpen(fi.window)) {
		game(&fi);
		sfRenderWindow_close(fi.window);
	}
	destroy(&fi);
	return (0);
}
