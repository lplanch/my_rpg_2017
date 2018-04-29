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

void update_player_position(st_rpg *rpg)
{
	rpg->player.acceleration.y =
	rpg->player.max_speed * (rpg->player.nbr_frame.y / 10.);
	rpg->player.acceleration.x =
	rpg->player.max_speed * (rpg->player.nbr_frame.x / 10.);
	verify_collide_map(rpg);
}
