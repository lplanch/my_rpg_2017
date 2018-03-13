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
	int a = 0;

	while (a != 4) {
		if (a == 1)
			move(fi);
		fi->square2.y -= 15;
		move_ID_player(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.y += 15;
		a++;
		move_camera(fi);
	}
}

void move_down(files_t *fi)
{
	int a = 0;

	while (a != 4) {
		if (a == 1)
			move(fi);
		fi->square2.y += 15;
		move_ID_player(fi);
		draw(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.y -= 15;
		a++;
		move_camera(fi);
	}
}

void move_right(files_t *fi)
{
	int a = 0;

	while (a != 4) {
		if (a == 1)
			move(fi);
		fi->square2.x += 15;
		move_ID_player(fi);
		draw(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.x -= 15;
		a++;
		move_camera(fi);
	}
}

void move_left(files_t *fi)
{
	int a = 0;

	while (a != 4) {
		if (a == 1)
			move(fi);
		fi->square2.x -= 15;
		move_ID_player(fi);
		draw(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.x += 15;
		a++;
		move_camera(fi);
	}
}
