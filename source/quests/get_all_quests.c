/*
** EPITECH PROJECT, 2018
** get_all_quests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

int take_nbr_quests(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;
	int size = 0;

	while ((entry = readdir(dir)) != 0) {
		if (entry->d_name[0] != '.')
			size++;
	}
	closedir(dir);
	return (size);
}

void get_all_quests(st_rpg *s, char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;
	char *name;
	int i = 0;
	int size = take_nbr_quests(path);

	s->fi->quests = malloc(sizeof(quests_t) * size + 1);
	for (int i = 0; i != size; i++) {
		s->fi->quests[i] = malloc(sizeof(quests_t));
	} while ((entry = readdir(dir)) != 0) {
		if (entry->d_name[0] != '.') {
			name = my_strcat_dup(path, entry->d_name);
			s->fi->quests[i] = get_quests(name);
			free(name);
			i++;
		}
	}
	s->fi->quests[i] = NULL;
	//display_all(s, size);
	closedir(dir);
}
