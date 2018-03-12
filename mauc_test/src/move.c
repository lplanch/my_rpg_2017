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

void move(files_t *fi)
{
	fi->square.left += 48;
	if (fi->square.left >= 192)
		fi->square.left = 0;
}

void move_up(files_t *fi)
{
	int a = 0;

	while (a != 4) {
		if (a == 1)
			move(fi);
		fi->square2.y -= 5;
		move_ID_player(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.y += 5;
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
		fi->square2.y += 5;
		move_ID_player(fi);
		draw(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.y -= 5;
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
		fi->square2.x += 5;
		move_ID_player(fi);
		draw(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.x -= 5;
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
		fi->square2.x -= 5;
		move_ID_player(fi);
		draw(fi);
		if (collision(fi) == 0)
			draw(fi);
		else
			fi->square2.x += 5;
		a++;
		move_camera(fi);
	}
}

void move_ok(files_t *fi)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		fi->square.top = 144;
		fi->direction = 1;
		move_up(fi);
	} if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		fi->square.top = 0;
		fi->direction = 3;
		move_down(fi);
	} if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		fi->square.top = 96;
		fi->direction = 2;
		move_right(fi);
	} if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		fi->square.top = 48;
		fi->direction = 4;
		move_left(fi);
	}
}
