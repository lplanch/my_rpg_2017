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
	sfRenderWindow_setFramerateLimit(fi->window, 120);
	return (0);
}

void destroy_sprite(files_t *fi)
{
	sfSprite_destroy(fi->testmap.sprite);
	sfSprite_destroy(fi->testmap.sprite2);
	sfSprite_destroy(fi->testmap.sprite3);
	sfSprite_destroy(fi->testmap.sprite4);
	sfSprite_destroy(fi->testmap.sprite5);
}

void destroy_texture(files_t *fi)
{
	sfTexture_destroy(fi->testmap.texture);
	sfTexture_destroy(fi->testmap.texture2);
	sfTexture_destroy(fi->testmap.texture3);
	sfTexture_destroy(fi->testmap.texture4);
	sfTexture_destroy(fi->testmap.texture5);
}

void destroy(files_t *fi)
{
	sfImage_destroy(fi->testmap.image);
	sfImage_destroy(fi->testmap.testmap_backgound);
	sfImage_destroy(fi->testmap.testmap_relief);
	sfImage_destroy(fi->testmap.testmap_col);
	sfImage_destroy(fi->testmap.testmap_colID);
	sfImage_destroy(fi->testmap.testmap_prof);
	destroy_sprite(fi);
	destroy_texture(fi);
	destroy_object(fi->characters);
	destroy_object(fi->ID_characters);
	free_all(fi);
	sfRenderWindow_destroy(fi->window);
}

void create2(files_t *fi)
{
	characters_setup(fi);
	pnj_setup(fi);
	setup_variable(fi);
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
