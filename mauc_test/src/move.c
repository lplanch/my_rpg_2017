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
	if ((fi->square2.x <= 960 && fi->square2.x >= 136 && fi->square2.y >= 24 && fi->square2.y <= 3100) || (fi->square2.x <= 6719 && fi->square2.x >= 6216 && fi->square2.y >= 3709 && fi->square2.y <= 5970))
		fi->camera_pos = 2;
	if ((fi->square2.x >= 8931 && fi->square2.x <= 9378 && fi->square2.y >= 24 && fi->square2.y <= 3100) || (fi->square2.x <= 8708 && fi->square2.x >= 7840 && fi->square2.y >= 3709 && fi->square2.y <= 5970))
		fi->camera_pos = 2;
	if ((fi->square2.y <= 532 && fi->square2.y >= 24 && fi->square2.x >= 136 && fi->square2.x <= 9378) || (fi->square2.y <= 5970 && fi->square2.y >= 5597 && fi->square2.x >= 6270 && fi->square2.x <= 8708))
		fi->camera_pos = 3;
	if ((fi->square2.y >= 2740 && fi->square2.y <= 3100 && fi->square2.x >= 136 && fi->square2.x <= 9378) || (fi->square2.y <= 3915 && fi->square2.y >= 3709 && fi->square2.x >= 6270 && fi->square2.x <= 8708))
		fi->camera_pos = 3;
	if ((fi->square2.y >= 4255 && fi->square2.y <= 4617 && fi->square2.x >= 746 && fi->square2.x <= 923))
		fi->camera_pos = 1;
	switch (fi->camera_pos) {
		case 0:
			fi->camera = fi->square2;
			fi->camera_prec = fi->camera;
			break;
		case 1:
			fi->camera.x = 870;
			fi->camera.y = 4862;
			break;
		case 2:
			fi->camera.x = fi->camera_prec.x;
			fi->camera.y = fi->square2.y;
			fi->camera_prec.y = fi->camera.y;
			break;
		case 3:
			fi->camera.y = fi->camera_prec.y;
			fi->camera.x = fi->square2.x;
			fi->camera_prec.x = fi->camera.x;
			break;
	}
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
		move(fi);
		usleep(500);
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
		move(fi);
		usleep(500);
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
		move(fi);
		usleep(500);
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
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->sprite, fi->square2);
	}
}
