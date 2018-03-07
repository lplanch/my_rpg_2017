/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void draw(files_t *fi)
{
	sfSprite_setTextureRect(fi->sprite, fi->square);
	sfSprite_setPosition(fi->gsprite, fi->gsquare2);
	sfRenderWindow_clear(fi->window, sfBlack);
	sfRenderWindow_drawSprite(fi->window, fi->gsprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->sprite, NULL);
	sfRenderWindow_display(fi->window);
	usleep(10000);
}

int game(files_t *fi)
{
	int a = 0;
	sfEvent event;

	while (a == 0) {
		while (sfRenderWindow_pollEvent(fi->window, &event)) {
			if (event.type == sfEvtClosed)
				a = 1;
		}
		move_ok(fi);
		draw(fi);
		usleep(50000);
	}
}
