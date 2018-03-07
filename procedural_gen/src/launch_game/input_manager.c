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
		sfView_zoom(proc->gman->camera, 1.1);
		sfRenderWindow_setView(proc->gman->window, proc->gman->camera);
	}
}

void verif_movement_input(proc_t *proc)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		proc->gman->player.velocity.y = -speed * 5;
	} else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		proc->gman->player.velocity.y = speed * 5;
	} else {
		proc->gman->player.velocity.y = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		proc->gman->player.velocity.x = -speed * 5;
	} else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		proc->gman->player.velocity.x = speed * 5;
	} else {
		proc->gman->player.velocity.x = 0;
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
