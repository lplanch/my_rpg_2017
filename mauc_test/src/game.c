/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

int game(files_t *fi)
{
	int a = 0;
	sfEvent event;

	while (a == 0) {
		while (sfRenderWindow_pollEvent(fi->window, &event)) {
			if (event.type == sfEvtClosed)
				a = 1;
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) {
				check_pnj(fi);
			}
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD) {
				fi->dialog_box_isopen = 1;
				fi->nb_pnj = rand() % 5 + 0;
			}
		}
		//printf("x= %i\n", fi->pos[0].x);
		//printf("y= %i\n", fi->pos[0].y);
		if (fi->dialog_box_isopen == 1)
			dialog_box(fi);
		move_ok(fi);
		update_player_position(fi);
		move_ID_player(fi);
		draw(fi);
	}
}
