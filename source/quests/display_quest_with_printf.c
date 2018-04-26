/*
** EPITECH PROJECT, 2018
** display_quest.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

void display_list(quests_list_t *quests_list, int size, int d)
{
	printf("type= %i\n", quests_list->type);
	if (quests_list->type == 1) {
		printf("name_item= %s\n", quests_list->farm_quests.name_item);
		printf("nbr_item= %d\n", quests_list->farm_quests.nbr_item);
	} if (quests_list->type == 2) {
		printf("name_kill= %s\n", quests_list->kill_quests.name_kill);
		printf("nbr_kill= %d\n", quests_list->kill_quests.nbr_kill);
	} if (quests_list->type == 3) {
		printf("name_place= %s\n", quests_list->go_quests.name_place);
	} if (quests_list->type == 4) {
		printf("name_place= %s\n", quests_list->speak_quests.name_character);
	} if (d != size) {
		d += 1;
		display_list(quests_list->next, size, d);
	}
}

void display_all(st_rpg *s, int size)
{
	int d = 1;

	for (int i = 0; i != size; i++) {
		printf("title= %s\n", s->fi->quests[i]->title);
		printf("nbr_quests= %d\n", s->fi->quests[i]->nbr_quests);
		for (int p = 0; s->fi->quests[i]->rewards.objects[p] != NULL; p++) {
			printf("objects= %s\n", s->fi->quests[i]->rewards.objects[p]);
		}
		printf("money= %i\n", s->fi->quests[i]->rewards.money);
		printf("xp= %i\n", s->fi->quests[i]->rewards.xp);
		if (s->fi->quests[0]->quests_list != NULL)
			display_list(s->fi->quests[i]->quests_list, s->fi->quests[i]->nbr_quests, d);
		my_putchar('\n');
	}
}
