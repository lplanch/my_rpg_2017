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
		if (rpg->player.nbr_frame.y > -10)
			rpg->player.nbr_frame.y -= 1;
	} else if (sfKeyboard_isKeyPressed(key_down) == sfTrue) {
		if (rpg->player.nbr_frame.y < 10)
			rpg->player.nbr_frame.y += 1;
	} else {
		if (rpg->player.nbr_frame.y > 0)
			rpg->player.nbr_frame.y -= 1;
		else if (rpg->player.nbr_frame.y < 0)
			rpg->player.nbr_frame.y += 1;
	}
}

void verify_x_movement(st_rpg *rpg)
{
	if (sfKeyboard_isKeyPressed(key_left) == sfTrue) {
		if (rpg->player.nbr_frame.x > -10)
			rpg->player.nbr_frame.x -= 1;
	} else if (sfKeyboard_isKeyPressed(key_right) == sfTrue) {
		if (rpg->player.nbr_frame.x < 10)
			rpg->player.nbr_frame.x += 1;
	} else {
		if (rpg->player.nbr_frame.x > 0)
			rpg->player.nbr_frame.x -= 1;
		else if (rpg->player.nbr_frame.x < 0)
			rpg->player.nbr_frame.x += 1;
	}
}

void verify_collide_map(st_rpg *rpg)
{
	int tempy[2] = {(rpg->player.obj->pos.y +
		(rpg->player.acceleration.y * rpg->proc.gman.dt)) / 48,
		(rpg->player.obj->pos.x) / 48};
	int tempx[2] = {(rpg->player.obj->pos.y) / 48,
		(rpg->player.obj->pos.x +
		(rpg->player.acceleration.x * rpg->proc.gman.dt)) / 48};

	if (verify_collide(rpg->proc.map[tempy[0]][tempy[1]])) {
		rpg->player.obj->pos.y +=
		rpg->player.acceleration.y * rpg->proc.gman.dt;
	} if (verify_collide(rpg->proc.map[tempx[0]][tempx[1]])) {
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
