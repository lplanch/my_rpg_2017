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
	sfSprite_setPosition(fi->ID_sprite, fi->vect_ID_player);
	sfSprite_setPosition(fi->sprite, fi->square2);
	sfRenderWindow_clear(fi->window, sfBlack);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite5, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite3, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite2, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->ID_sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite4, NULL);
	sfRenderWindow_display(fi->window);
	usleep(1);
}

int game(files_t *fi)
{
	int b = 0;
	int a = 0;
	sfEvent event;

	while (a == 0) {
		while (sfRenderWindow_pollEvent(fi->window, &event)) {
			if (event.type == sfEvtClosed)
				a = 1;
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD) {
				fi->dialog_box_isopen = 1;
				b = rand() % 3 + 0;
				fi->nb_pnj = b;
			}
		}
		if (fi->dialog_box_isopen == 1)
			dialog_box(fi);
		move_ok(fi);
		update_player_position(fi);
		move_ID_player(fi);
		draw(fi);
	}
}
