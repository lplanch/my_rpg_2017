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

int event_game(st_rpg *s)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtClosed) {
			destroy(s);
			return (1);
		} if (event.type == sfEvtKeyPressed && event.key.code ==
		sfKeyReturn) {
			check_pnj(s);
		} if (event.type == sfEvtKeyPressed && event.key.code ==
		sfKeyD) {
			check_quests(s);
		}
	}
	return (0);
}
