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
	if ((fi->characters->pos.x <= 960 && fi->characters->pos.x >= 136 && fi->characters->pos.y >= 24 && fi->characters->pos.y <= 3167) || (fi->characters->pos.x <= 6719 && fi->characters->pos.x >= 6216 && fi->characters->pos.y >= 3709 && fi->characters->pos.y <= 5970))
		fi->camera_pos = 2;
	if ((fi->characters->pos.x >= 8634 && fi->characters->pos.x <= 9378 && fi->characters->pos.y >= 24 && fi->characters->pos.y <= 3167) || (fi->characters->pos.x <= 8708 && fi->characters->pos.x >= 7840 && fi->characters->pos.y >= 3709 && fi->characters->pos.y <= 5970))
		fi->camera_pos = 2;
	if ((fi->characters->pos.y <= 532 && fi->characters->pos.y >= 24 && fi->characters->pos.x >= 136 && fi->characters->pos.x <= 9378) || (fi->characters->pos.y <= 5970 && fi->characters->pos.y >= 5597 && fi->characters->pos.x >= 6270 && fi->characters->pos.x <= 8708))
		fi->camera_pos = 3;
	if ((fi->characters->pos.y >= 2740 && fi->characters->pos.y <= 3167 && fi->characters->pos.x >= 136 && fi->characters->pos.x <= 9378) || (fi->characters->pos.y <= 3915 && fi->characters->pos.y >= 3709 && fi->characters->pos.x >= 6270 && fi->characters->pos.x <= 8708))
		fi->camera_pos = 3;
	if ((fi->characters->pos.y >= 4255 && fi->characters->pos.y <= 4617 && fi->characters->pos.x >= 746 && fi->characters->pos.x <= 923))
		fi->camera_pos = 1;
	switch (fi->camera_pos) {
		case 0:
			fi->camera = fi->characters->pos;
			fi->camera_prec = fi->camera;
			break;
		case 1:
			fi->camera.x = 870;
			fi->camera.y = 4862;
			break;
		case 2:
			fi->camera.x = fi->camera_prec.x;
			fi->camera.y = fi->characters->pos.y;
			fi->camera_prec.y = fi->camera.y;
			break;
		case 3:
			fi->camera.y = fi->camera_prec.y;
			fi->camera.x = fi->characters->pos.x;
			fi->camera_prec.x = fi->camera.x;
			break;
	}
	sfView_setCenter(fi->view, fi->camera);
	sfRenderWindow_setView(fi->window, fi->view);
}

void move_up(files_t *fi)
{
	int a = fi->characters->pos.y + fi->speed.y;
	int b = fi->characters->pos.y;

	while (b != a) {
		fi->characters->pos.y -= 1;
		b -= 1;
		move_ID_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.y += 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite, fi->characters->pos);
	}
}

void move_down(files_t *fi)
{
	int a = fi->characters->pos.y + fi->speed.y;
	int b = fi->characters->pos.y;

	while (b != a) {
		fi->characters->pos.y += 1;
		b += 1;
		move_ID_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.y -= 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite, fi->characters->pos);
	}
}

void move_right(files_t *fi)
{
	int a = fi->characters->pos.x + fi->speed.x;
	int b = fi->characters->pos.x;

	while (b != a) {
		fi->characters->pos.x += 1;
		b += 1;
		move_ID_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.x -= 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite, fi->characters->pos);
	}
}

void move_left(files_t *fi)
{
	int a = fi->characters->pos.x + fi->speed.x;
	int b = fi->characters->pos.x;

	while (b != a) {
		fi->characters->pos.x -= 1;
		b -= 1;
		move_ID_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.x += 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite, fi->characters->pos);
	}
}
