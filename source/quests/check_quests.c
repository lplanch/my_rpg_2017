/*
** EPITECH PROJECT, 2018
** check_quests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

void check_quests(st_rpg *s)
{
	for (int i = 0; s->fi->quests[i] != NULL; i++) {
		if (s->fi->quests[i]->status == 1) {
			printf("Title= %s\n", s->fi->quests[i]->title);
		}
	}
}
