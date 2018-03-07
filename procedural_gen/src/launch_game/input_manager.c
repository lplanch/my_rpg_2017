/*
** EPITECH PROJECT, 2018
** input_manager.c
** File description:
** main input file
*/

#include "my.h"
#include "../../include/procedural.h"

void verify_other_input(sfEvent event, proc_t *proc)
{
	 if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP) {
		sfView_zoom(proc->gman->camera, 0.9);
		sfRenderWindow_setView(proc->gman->window, proc->gman->camera);
	} if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM) {
		proc->gman->zoom += 1;
		sfView_zoom(proc->gman->camera, 1.1);
		sfRenderWindow_setView(proc->gman->window, proc->gman->camera);
	} if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue)
		my_putchar('a');

}

void verif_movement_input(proc_t *proc)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		move_camera_position(proc, 0, -1);
	} if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		move_camera_position(proc, 0, 1);
	} if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		move_camera_position(proc, -1, 0);
	} if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		move_camera_position(proc, 1, 0);
	}
}

int verif_input_map(proc_t *proc)
{
	sfEvent event;

	verif_movement_input(proc);
	while (sfRenderWindow_pollEvent(proc->gman->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(proc->gman->window);
		verify_other_input(event, proc);
	}
}
