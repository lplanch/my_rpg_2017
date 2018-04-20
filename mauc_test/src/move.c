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
	check_pos_camera_x(fi);
	check_pos_camera_y(fi);
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
		move_id_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.y += 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
	}
}

void move_down(files_t *fi)
{
	int a = fi->characters->pos.y + fi->speed.y;
	int b = fi->characters->pos.y;

	while (b != a) {
		fi->characters->pos.y += 1;
		b += 1;
		move_id_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.y -= 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
	}
}

void move_right(files_t *fi)
{
	int a = fi->characters->pos.x + fi->speed.x;
	int b = fi->characters->pos.x;

	while (b != a) {
		fi->characters->pos.x += 1;
		b += 1;
		move_id_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.x -= 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
	}
}

void move_left(files_t *fi)
{
	int a = fi->characters->pos.x + fi->speed.x;
	int b = fi->characters->pos.x;

	while (b != a) {
		fi->characters->pos.x -= 1;
		b -= 1;
		move_id_player(fi);
		move_allpts(fi);
		if (collision(fi) == 1) {
			fi->characters->pos.x += 1;
		}
		move(fi);
		usleep(500);
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
	}
}
