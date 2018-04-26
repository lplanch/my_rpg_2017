/*
** EPITECH PROJECT, 2018
** player_movement.c
** File description:
** make player move
*/

#include "my.h"
#include "game_map.h"

int interval_float(float value, float less, float max)
{
	if (value > less && value < max)
		return (1);
	return (0);
}

void set_speed_zero(st_rpg *s)
{
	if (interval_float(s->fi->speed.x, 0, speed * 2.2) == 1) {
		s->fi->speed.x = 0;
	} if (interval_float(s->fi->speed.x, -speed * 2.2, 0) == 1) {
		s->fi->speed.x = 0;
	} if (interval_float(s->fi->speed.y, 0, speed * 2.2) == 1) {
		s->fi->speed.y = 0;
	} if (interval_float(s->fi->speed.y, -speed * 2.2, 0) == 1) {
		s->fi->speed.y = 0;
	}
}

void decrement_speed(st_rpg *s)
{
	if (s->fi->speed.x > 0) {
		s->fi->speed.x -= speed;
	} else if (s->fi->speed.x < 0) {
		s->fi->speed.x += speed;
	} if (s->fi->speed.y < 0) {
		s->fi->speed.y += speed;
	} else if (s->fi->speed.y > 0) {
		s->fi->speed.y -= speed;
	}
	set_speed_zero(s);
}

void make_player_position(st_rpg *s)
{
	switch (s->fi->direction) {
	case 1:
		move_up(s);
		break;
	case 2:
		move_right(s);
		break;
	case 3:
		move_down(s);
		break;
	case 4:
		move_left(s);
		break;
	}
}

void update_player_position_village(st_rpg *s)
{
	s->fi->speed.y += s->fi->velocity.y;
	s->fi->speed.x += s->fi->velocity.x;
	if (s->fi->speed.x > s->fi->maxspeed.x)
		s->fi->speed.x = s->fi->maxspeed.x;
	else if (s->fi->speed.x < -s->fi->maxspeed.x)
		s->fi->speed.x = -s->fi->maxspeed.x;
	if (s->fi->speed.y > s->fi->maxspeed.y)
		s->fi->speed.y = s->fi->maxspeed.y;
	else if (s->fi->speed.y < -s->fi->maxspeed.y)
		s->fi->speed.y = -s->fi->maxspeed.y;
	make_player_position(s);
	move_camera(s);
	decrement_speed(s);
}
