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
	proc->gman->camera_pos.x += px;
	proc->gman->camera_pos.y += py;
	sfView_setCenter(proc->gman->camera, proc->gman->camera_pos);
	sfRenderWindow_setView(proc->gman->window, proc->gman->camera);
}
