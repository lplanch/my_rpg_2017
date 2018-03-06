/*
** EPITECH PROJECT, 2018
** input_manager.c
** File description:
** main input file
*/

#include "my.h"
#include "../../include/procedural.h"

void verify_movement_input(sfEvent event, proc_t *proc)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
		move_camera_position(proc, 0, -5);
	} if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
		move_camera_position(proc, 0, 5);
	} if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
		move_camera_position(proc, -5, 0);
	} if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
		move_camera_position(proc, 5, 0);
	}

}

int verif_input_map(proc_t *proc)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(proc->gman->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(proc->gman->window);
		verify_movement_input(event, proc);
	}
}
