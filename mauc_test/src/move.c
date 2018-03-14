/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** move file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void move_camera(files_t *fi)
{
	fi->camera = fi->square2;
	sfView_setCenter(fi->view, fi->camera);
	sfRenderWindow_setView(fi->window, fi->view);
}

void move_up(files_t *fi)
{
	int a = fi->square2.y + fi->speed.y;
	int b = fi->square2.y;

	while (b != a) {
		fi->square2.y -= 1;
		b -= 1;
		move_ID_player(fi);
		if (collision(fi) == 1) {
			fi->square2.y += 1;
		}
		sfSprite_setPosition(fi->sprite, fi->square2);
	}
}

void move_down(files_t *fi)
{
	int a = fi->square2.y + fi->speed.y;
	int b = fi->square2.y;

	while (b != a) {
		fi->square2.y += 1;
		b += 1;
		move_ID_player(fi);
		if (collision(fi) == 1) {
			fi->square2.y -= 1;
		}
		sfSprite_setPosition(fi->sprite, fi->square2);
	}
}

void move_right(files_t *fi)
{
	int a = fi->square2.x + fi->speed.x;
	int b = fi->square2.x;

	while (b != a) {
		fi->square2.x += 1;
		b += 1;
		move_ID_player(fi);
		if (collision(fi) == 1) {
			fi->square2.x -= 1;
		}
		sfSprite_setPosition(fi->sprite, fi->square2);
	}
}

void move_left(files_t *fi)
{
	int a = fi->square2.x + fi->speed.x;
	int b = fi->square2.x;

	while (b != a) {
		fi->square2.x -= 1;
		b -= 1;
		move_ID_player(fi);
		if (collision(fi) == 1) {
			fi->square2.x += 1;
		}
		sfSprite_setPosition(fi->sprite, fi->square2);
	}
}
