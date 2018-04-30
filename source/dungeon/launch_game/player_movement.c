/*
** EPITECH PROJECT, 2018
** player_movement.c
** File description:
** make player move
*/

#include "my.h"
#include "my_rpg.h"

void verify_y_movement(st_rpg *rpg)
{
	if (sfKeyboard_isKeyPressed(key_up) == sfTrue) {
		if (rpg->player.nbr_frame.y > -20)
			rpg->player.nbr_frame.y -= 2;
	} else if (sfKeyboard_isKeyPressed(key_down) == sfTrue) {
		if (rpg->player.nbr_frame.y < 20)
			rpg->player.nbr_frame.y += 2;
	} else {
		if (rpg->player.nbr_frame.y > 0)
			rpg->player.nbr_frame.y -= 2;
		else if (rpg->player.nbr_frame.y < 0)
			rpg->player.nbr_frame.y += 2;
	}
}

void verify_x_movement(st_rpg *rpg)
{
	if (sfKeyboard_isKeyPressed(key_left) == sfTrue) {
		if (rpg->player.nbr_frame.x > -20)
			rpg->player.nbr_frame.x -= 2;
	} else if (sfKeyboard_isKeyPressed(key_right) == sfTrue) {
		if (rpg->player.nbr_frame.x < 20)
			rpg->player.nbr_frame.x += 2;
	} else {
		if (rpg->player.nbr_frame.x > 0)
			rpg->player.nbr_frame.x -= 2;
		else if (rpg->player.nbr_frame.x < 0)
			rpg->player.nbr_frame.x += 2;
	}
}

void verify_collide_map(st_rpg *rpg)
{
	int py = (rpg->player.obj->pos.y + 36 +
		(rpg->player.acceleration.y * rpg->proc.gman.dt)) / 96;
	int my = (rpg->player.obj->pos.y +
		(rpg->player.acceleration.y * rpg->proc.gman.dt)) / 96;
	int yx = (rpg->player.obj->pos.x) / 96;
	int px = (rpg->player.obj->pos.x + 24 +
	(rpg->player.acceleration.x * rpg->proc.gman.dt)) / 96;
	int mx = (rpg->player.obj->pos.x - 24 +
	(rpg->player.acceleration.x * rpg->proc.gman.dt)) / 96;
	int xy = (rpg->player.obj->pos.y) / 96;

	if (verify_collide(rpg->proc.map[py][yx]) &&
		verify_collide(rpg->proc.map[my][yx])) {
		rpg->player.obj->pos.y +=
		rpg->player.acceleration.y * rpg->proc.gman.dt;
	} if (verify_collide(rpg->proc.map[xy][mx]) &&
		verify_collide(rpg->proc.map[xy][px])) {
		rpg->player.obj->pos.x +=
		rpg->player.acceleration.x * rpg->proc.gman.dt;
	}
}

int choose_orientation(st_rpg *s)
{
	if (abs(s->player.nbr_frame.x) > abs(s->player.nbr_frame.y)) {
		if (s->player.nbr_frame.x > 0)
			return (2);
		else
			return (1);
	} else {
		if (s->player.nbr_frame.y > 0)
			return (0);
		else
			return (3);
	}
}

int orientation_from_mouse(st_rpg *s)
{
	float angle = get_angle(s);

	if (angle > -33 && angle < 33)
		return (2);
	if (angle < -33 && angle > -145)
		return (3);
	if (angle > 33 && angle < 145)
		return (0);
	return (1);
}

void walk_animation(st_rpg *s)
{
	s->player.t.time = sfClock_getElapsedTime(s->player.t.clock);
	s->player.t.sec = s->player.t.time.microseconds / 1000000.0;
	if (s->player.t.sec > s->player.animspeed) {
		if (s->player.animcol == 2 || s->player.animcol == 0)
		s->player.animsens = -s->player.animsens;
		s->player.animcol += s->player.animsens;
		sfClock_restart(s->player.t.clock);
		s->player.obj->rect.left = s->player.animcol * 48
		+ 144 * s->player.cdata.sex;
	}
}

void player_animation(st_rpg *s)
{
	if (abs(s->player.nbr_frame.x) != 0 || abs(s->player.nbr_frame.y) != 0)
		walk_animation(s);
	s->player.obj->rect.top = orientation_from_mouse(s) * 48;
	sfSprite_setTextureRect(s->player.obj->sprite,
	s->player.obj->rect);
}

void update_player_position(st_rpg *rpg)
{
	rpg->player.acceleration.y =
	rpg->player.max_speed * (rpg->player.nbr_frame.y / 10.);
	rpg->player.acceleration.x =
	rpg->player.max_speed * (rpg->player.nbr_frame.x / 10.);
	verify_collide_map(rpg);
}
