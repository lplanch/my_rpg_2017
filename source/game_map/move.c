/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** move file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void move_camera(st_rpg *s)
{
	check_pos_camera_x(s);
	check_pos_camera_y(s);
	switch (s->fi->camera_pos) {
	case 0:
		s->fi->camera = s->fi->characters->pos;
		s->fi->camera_prec = s->fi->camera;
		break;
	case 1:
		s->fi->camera.x = 870;
		s->fi->camera.y = 4862;
		break;
	case 2:
		s->fi->camera.x = s->fi->camera_prec.x;
		s->fi->camera.y = s->fi->characters->pos.y;
		s->fi->camera_prec.y = s->fi->camera.y;
		break;
	case 3:
		s->fi->camera.y = s->fi->camera_prec.y;
		s->fi->camera.x = s->fi->characters->pos.x;
		s->fi->camera_prec.x = s->fi->camera.x;
		break;
	}
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->fi->window, s->fi->view);
}

void move_up(st_rpg *s)
{
	int a = s->fi->characters->pos.y + s->fi->speed.y;
	int b = s->fi->characters->pos.y;

	while (b != a) {
		s->fi->characters->pos.y -= 1;
		b -= 1;
		move_id_player(s);
		move_allpts(s);
		if (collision(s) == 1) {
			s->fi->characters->pos.y += 1;
		}
		move(s);
		usleep(500);
		sfSprite_setPosition(s->fi->characters->sprite,
		s->fi->characters->pos);
	}
}

void move_down(st_rpg *s)
{
	int a = s->fi->characters->pos.y + s->fi->speed.y;
	int b = s->fi->characters->pos.y;

	while (b != a) {
		s->fi->characters->pos.y += 1;
		b += 1;
		move_id_player(s);
		move_allpts(s);
		if (collision(fi) == 1) {
			s->fi->characters->pos.y -= 1;
		}
		move(s);
		usleep(500);
		sfSprite_setPosition(s->fi->characters->sprite,
		s->fi->characters->pos);
	}
}

void move_right(st_rpg *s)
{
	int a = s->fi->characters->pos.x + s->fi->speed.x;
	int b = s->fi->characters->pos.x;

	while (b != a) {
		s->fi->characters->pos.x += 1;
		b += 1;
		move_id_player(s);
		move_allpts(s);
		if (collision(s) == 1) {
			s->fi->characters->pos.x -= 1;
		}
		move(s);
		usleep(500);
		sfSprite_setPosition(s->fi->characters->sprite,
		s->fi->characters->pos);
	}
}

void move_left(st_rpg *s)
{
	int a = s->fi->characters->pos.x + s->fi->speed.x;
	int b = s->fi->characters->pos.x;

	while (b != a) {
		s->fi->characters->pos.x -= 1;
		b -= 1;
		move_id_player(s);
		move_allpts(s);
		if (collision(s) == 1) {
			s->fi->characters->pos.x += 1;
		}
		move(s);
		usleep(500);
		sfSprite_setPosition(s->fi->characters->sprite,
		s->fi->characters->pos);
	}
}
