/*
** EPITECH PROJECT, 2018
** player_movement.c
** File description:
** make player move
*/

#include "my.h"
#include "../../include/procedural.h"

void verify_y_movement(proc_t *proc)
{
	if (sfKeyboard_isKeyPressed(key_up) == sfTrue) {
		if (proc->gman->player.nbr_frame.y > -10)
			proc->gman->player.nbr_frame.y -= 1;
	} else if (sfKeyboard_isKeyPressed(key_down) == sfTrue) {
		if (proc->gman->player.nbr_frame.y < 10)
			proc->gman->player.nbr_frame.y += 1;
	} else {
		if (proc->gman->player.nbr_frame.y > 0)
			proc->gman->player.nbr_frame.y -= 1;
		else if (proc->gman->player.nbr_frame.y < 0)
			proc->gman->player.nbr_frame.y += 1;
	}
}

void verify_x_movement(proc_t *proc)
{
	if (sfKeyboard_isKeyPressed(key_left) == sfTrue) {
		if (proc->gman->player.nbr_frame.x > -10)
			proc->gman->player.nbr_frame.x -= 1;
	} else if (sfKeyboard_isKeyPressed(key_right) == sfTrue) {
		if (proc->gman->player.nbr_frame.x < 10)
			proc->gman->player.nbr_frame.x += 1;
	} else {
		if (proc->gman->player.nbr_frame.x > 0)
			proc->gman->player.nbr_frame.x -= 1;
		else if (proc->gman->player.nbr_frame.x < 0)
			proc->gman->player.nbr_frame.x += 1;
	}
}

void verify_collide_map(proc_t *proc)
{
	int tempy[2];
	int tempx[2];

	tempy[0] = (proc->gman->player.pos.y +
	(proc->gman->player.acceleration.y * proc->gman->dt)) / 48;
	tempy[1] = (proc->gman->player.pos.x) / 48;
	tempx[0] = (proc->gman->player.pos.y) / 48;
	tempx[1] = (proc->gman->player.pos.x +
	(proc->gman->player.acceleration.x * proc->gman->dt)) / 48;
	if (verify_collide(proc->map[tempy[0]][tempy[1]])) {
		proc->gman->player.pos.y +=
		proc->gman->player.acceleration.y * proc->gman->dt;
	} if (verify_collide(proc->map[tempx[0]][tempx[1]])) {
		proc->gman->player.pos.x +=
		proc->gman->player.acceleration.x * proc->gman->dt;
	}
}

void update_player_position(proc_t *proc)
{
	proc->gman->player.acceleration.y =
	proc->gman->player.max_speed * (proc->gman->player.nbr_frame.y / 10.);
	proc->gman->player.acceleration.x =
	proc->gman->player.max_speed * (proc->gman->player.nbr_frame.x / 10.);
	verify_collide_map(proc);
}
