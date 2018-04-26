/*
** EPITECH PROJECT, 2018
** check_quests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

void update_quests_box_des(st_rpg *s)
{
	int file = open(s->fi->quests[s->fi->quests_box.nb_quests]->path,
	O_RDONLY);
	char buffer[51] = {'\0'};
	char *str = NULL;
	char *temp = NULL;
	int toto = 50;

	while (toto == 50) {
		toto = read(file, buffer, 50);
		buffer[toto] = '\0';
		temp = my_strcat(str, buffer);
		free(str);
		str = temp;
	}
	sfText_setString(s->fi->quests_box.quests_des->text->text, str);
	close(file);
}

void check_quests(st_rpg *s)
{
	s->fi->quests[0]->status = 1;
	for (int i = 0; s->fi->quests[i] != NULL; i++) {
		if (s->fi->quests[i]->status == 1) {
			s->fi->quests_box.nb_quests = i;
			sfText_setString(s->fi->quests_box.quests_box
			->text->text, s->fi->quests[i]->title);
		}
	}
}
