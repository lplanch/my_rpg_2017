/*
** EPITECH PROJECT, 2018
** get_quests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

int take_size(char *objects_buffer)
{
	int nbr_object = 1;

	for (int i = 0; objects_buffer[i] != '\0'; i++) {
		if (objects_buffer[i] == '|')
			nbr_object++;
	}
	return (nbr_object);
}

int take_big_size(char *objects_buffer)
{
	int size_word = 0;
	int presize = 0;

	for (int i = 0; objects_buffer[i] != '\0'; i++, size_word++) {
		if (objects_buffer[i] == '|' && size_word > presize)
			presize = size_word;
		if (objects_buffer[i] == '|')
			size_word = 0;
	}
	return (presize);
}

char **get_objects(char *objects_buffer, int x, int y)
{
	char **objects;
	int nbr_object = take_size(objects_buffer);
	int presize = take_big_size(objects_buffer);

	objects = malloc(sizeof(char *) * nbr_object + 8);
	objects[0] = malloc(sizeof(char) * presize + 10);
	for (int i = 0; objects_buffer[i] != '\0'; i++) {
		if (objects_buffer[i] != '|') {
			objects[y][x] = objects_buffer[i];
			x++;
		} else {
			objects[y][x] = '\0';
			x = 0;
			y++;
			objects[y] = malloc(sizeof(char) * presize + 10);
		}
	}
	objects[y][x] = '\0';
	objects[y + 1] = NULL;
	return (objects);
}

void get_money_xp(int size, char *buffer, int i, quests_t *quests)
{
	int x = 0;
	char *buf_money = malloc(sizeof(char) * size);
	char *buf_xp = malloc(sizeof(char) * size);

	for (; buffer[i] != '|'; i++, x++) {
		buf_money[x] = buffer[i];
	}
	buf_money[x] = '\0';
	quests->rewards.money = str_to_int(buf_money);
	i++;
	for (x = 0; buffer[i] != '\0'; i++, x++) {
		buf_xp[x] = buffer[i];
	}
	buf_xp[x] = '\0';
	quests->rewards.xp = str_to_int(buf_xp);
	free(buf_money);
	free(buf_xp);
}

void get_rewards(char *buffer, quests_t *quests)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int size = my_strlen(buffer);
	char *buf = malloc(sizeof(char) * size);

	for (i = 0; buffer[i + 1] < 48 || buffer[i + 1] > 57; i++) {
		buf[i] = buffer[i];
	}
	buf[i++] = '\0';
	quests->rewards.objects = get_objects(buf, x, y);
	get_money_xp(size, buffer, i, quests);
	free(buf);
}

int *get_all_type(char *buffer)
{
	int size = 0;
	int j = 0;
	int i = 0;
	int *type;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] != ' ')
			size++;
	}
	type = malloc(sizeof(int *) * size + 1);
	for (i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] != ' ') {
			type[j] = buffer[i] - 48;
			j++;
		}
	}
	type[j] = 666;
	return (type);
}

void get_type_and_create_quests(char *buffer, quests_list_t *quests_list)
{
	quests_list->type = buffer[0] - 48;
	if (quests_list->type == 1)
		create_farm_quests(buffer, quests_list);
	if (quests_list->type == 2)
		create_kill_quests(buffer, quests_list);
	if (quests_list->type == 3)
		create_go_quests(buffer, quests_list);
	if (quests_list->type == 4)
		create_speak_quests(buffer, quests_list);
}

quests_list_t *get_next_quests(quests_list_t *quests_list, int fd, int i, int size)
{
	char *buffer = NULL;

	quests_list->next = NULL;
	if (i != size) {
		i += 1;
		buffer = get_next_line(fd);
		get_type_and_create_quests(buffer, quests_list);
		quests_list->next = malloc(sizeof(quests_list_t));
		get_next_quests(quests_list->next, fd, i, size);
	}
	return (quests_list);
}

quests_t *get_quests(char *name)
{
	int fd = open(name, O_RDONLY);
	int i = 0;
	char *buffer = NULL;
	quests_t *quests = malloc(sizeof(quests_t));

	quests->title = get_next_line(fd);
	buffer = get_next_line(fd);
	get_rewards(buffer, quests);
	quests->nbr_quests = str_to_int(get_next_line(fd));
	quests->quests_list = malloc(sizeof(quests_list_t));
	quests->quests_list = get_next_quests(quests->quests_list, fd, i, quests->nbr_quests);
	return (quests);
}

/*quests_t *get_quests(char *name)
{
	quests_t *quests = malloc(sizeof(quests_t));
	int fd = open(name, O_RDONLY);
	char *buffer = NULL;

	quests->title = get_next_line(fd);
	quests->nbr_quests = str_to_int(get_next_line(fd));
	for (int i = 0; i != quests->nbr_quests; i++) {
		buffer = get_next_line(fd);
		get_type_and_create_quests(buffer, quests->next);
	}
	//quests->rewards = get_rewards(fd);
	return (quests);
}*/

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

void get_all_quest(st_rpg *s, char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;
	char *name;
	int i = 0;
	int size = take_nbr_quests(path);

	s->fi->quests = malloc(sizeof(quests_t) * size);
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
	//display_all(s, size);
	closedir(dir);
}
