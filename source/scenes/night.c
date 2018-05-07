/*
** EPITECH PROJECT, 2018
** night.c
** File description:
** night.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void night_scene(st_rpg *s)
{
	float posx = s->fi->camera.x - 960;
 	float posy = s->fi->camera.y - 540;
	g_object *background;
	g_object *moon;

	background = create_object("ressources/images/scenes/background_night2.png",
	create_vector2f(posx, posy), create_rect(0, 0, 1920, 1080), 0);
	moon = create_object("ressources/images/scenes/moon.png",
	create_vector2f(posx + 1000, posy), create_rect(0, 0, 315, 310), 0);
	for (int i = 0; i != 300; i++) {
		moon->pos.y += 2.5;
		moon->pos.x += 3;
		sfSprite_setPosition(moon->sprite, moon->pos);
		sfRenderWindow_drawSprite(s->window, background->sprite, NULL);
		sfRenderWindow_drawSprite(s->window, moon->sprite, NULL);
		sfRenderWindow_display(s->window);
	}
	destroy_object(background);
	destroy_object(moon);
}
