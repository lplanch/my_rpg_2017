/*
** EPITECH PROJECT, 2018
** player_movement.c
** File description:
** make player move
*/

#include "my.h"
#include "my_rpg.h"

int interval(float value, float less, float max)
{
	if (value > less && value < max)
		return (1);
	return (0);
}

void set_speed_zero(files_t *fi)
{
	if (interval(fi->speed.x, 0, speed * 2.2) == 1) {
		fi->speed.x = 0;
	} if (interval(fi->speed.x, -speed * 2.2, 0) == 1) {
		fi->speed.x = 0;
	} if (interval(fi->speed.y, 0, speed * 2.2) == 1) {
		fi->speed.y = 0;
	} if (interval(fi->speed.y, -speed * 2.2, 0) == 1) {
		fi->speed.y = 0;
	}
}

void decrement_speed(files_t *fi)
{
	if (fi->speed.x > 0) {
		fi->speed.x -= speed;
	} else if (fi->speed.x < 0) {
		fi->speed.x += speed;
	} if (fi->speed.y < 0) {
		fi->speed.y += speed;
	} else if (fi->speed.y > 0) {
		fi->speed.y -= speed;
	}
	set_speed_zero(fi);
}

void make_player_position(files_t *fi)
{
	switch (fi->direction) {
		case 1:
			move_up(fi);
			break;
		case 2:
			move_right(fi);
			break;
		case 3:
			move_down(fi);
			break;
		case 4:
			move_left(fi);
			break;
	}
}

void update_player_position(files_t *fi)
{
	fi->speed.y += fi->velocity.y;
	fi->speed.x += fi->velocity.x;
	if (fi->speed.x > fi->maxspeed.x)
		fi->speed.x = fi->maxspeed.x;
	else if (fi->speed.x < -fi->maxspeed.x)
		fi->speed.x = -fi->maxspeed.x;
	if (fi->speed.y > fi->maxspeed.y)
		fi->speed.y = fi->maxspeed.y;
	else if (fi->speed.y < -fi->maxspeed.y)
		fi->speed.y = -fi->maxspeed.y;
	make_player_position(fi);
	move_camera(fi);
	decrement_speed(fi);
}
