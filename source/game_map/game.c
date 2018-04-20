/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void game_update(st_rpg *s)
{
	if (s->fi->dialog_box_isopen == 1)
		dialog_box(s);
	move_ok(s);
	update_player_position(s);
	move_id_player(s);
	draw(s);
}

int event_game(sfEvent event, int a, st_rpg *s)
{
	if (event.type == sfEvtClosed)
		a = 1;
	if (event.type == sfEvtKeyPressed && event.key.code ==
	sfKeyReturn) {
		check_pnj(s);
	}
	if (event.type == sfEvtKeyPressed && event.key.code ==
	sfKeyD) {
		s->fi->dialog_box_isopen = 1;
		s->fi->nb_pnj = rand() % 5 + 0;
	}
	return (a);
}

int game(st_rpg *s)
{
	int a = 0;
	sfEvent event;

	while (a == 0) {
		while (sfRenderWindow_pollEvent(s->fi->window, &event)) {
			a = event_game(event, a, s);
		}
		game_update(s);
	}
	return (0);
}
