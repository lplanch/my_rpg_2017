/*
** EPITECH PROJECT, 2018
** camera_manager.c
** File description:
** camera main file to move camera
*/

#include "my.h"
#include "../../include/procedural.h"

void move_camera_position(proc_t *proc, int px, int py)
{
	int temp[2];

	temp[0] = (proc->gman->camera_pos.x + px) / 16;
	temp[1] = (proc->gman->camera_pos.y + py) / 16;
	if (proc->map[temp[0]][temp[1]] != '#') {
		proc->gman->camera_pos.x += px;
		proc->gman->camera_pos.y += py;
		sfView_setCenter(proc->gman->camera, proc->gman->camera_pos);
		sfRenderWindow_setView(proc->gman->window, proc->gman->camera);
	}
}
