/*
** EPITECH PROJECT, 2018
** prog.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void create(st_rpg *s)
{
	character_setup(s);
	get_all_pnj(s, "images/dialog_box/pnj/");
	setup_variable(s);
	setup_loading(s);
	get_all_quest(s, "source/quests/quests_info/");
}

int prog(st_rpg *s)
{
	struct stat a;

	if (stat("map_preset/parsing", &a) == -1)
		return (0);
	create(s);
	parsing(a, s);
	create_map(s);
	while (sfRenderWindow_isOpen(s->window)) {
		if (event_game(s))
			return (1);
		game_update(s);
	}
	return (0);
}
