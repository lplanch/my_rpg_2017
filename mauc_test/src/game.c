/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void game_update(files_t *fi)
{
	if (fi->dialog_box_isopen == 1)
		dialog_box(fi);
	move_ok(fi);
	update_player_position(fi);
	move_id_player(fi);
	draw(fi);
}

int event_game(sfEvent event, int a, files_t *fi)
{
	if (event.type == sfEvtClosed)
		a = 1;
	if (event.type == sfEvtKeyPressed && event.key.code ==
	sfKeyReturn) {
		check_pnj(fi);
	}
	if (event.type == sfEvtKeyPressed && event.key.code ==
	sfKeyD) {
		fi->dialog_box_isopen = 1;
		fi->nb_pnj = rand() % 5 + 0;
	}
	return (a);
}

int game(files_t *fi)
{
	int a = 0;
	sfEvent event;

	while (a == 0) {
		while (sfRenderWindow_pollEvent(fi->window, &event)) {
			a = event_game(event, a, fi);
		}
		game_update(fi);
	}
}
