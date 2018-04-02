/*
** EPITECH PROJECT, 2018
** get_pnj.c
** File description:
** description
*/

#include "my.h"
#include "my_rpg.h"

sfIntRect get_pnj_rect(int fd)
{
	sfIntRect rect;
	int i = 0;
	char *buffer = get_next_line(fd);

	rect.left = my_getnbr_i(buffer, 0);
	for (i = 0; buffer[i] != ' '; i++);
	i++;
	rect.top = my_getnbr_i(buffer, i);
	for (i = 0; buffer[i] != ' '; i++);
	i++;
	rect.width = my_getnbr_i(buffer, i);
	for (i = 0; buffer[i] != ' '; i++);
	i++;
	rect.height = my_getnbr_i(buffer, i);
	free(buffer);
	return (rect);
}

sfVector2f get_pnj_pos(int fd)
{
	sfVector2f pos;
	int i = 0;
	char *buffer = get_next_line(fd);

	pos.x = my_getnbr_i(buffer, 0);
	for (i = 0; buffer[i] != ' '; i++);
	pos.y = my_getnbr_i(buffer, i + 1);
	free(buffer);
	return (pos);
}

pnj_t get_pnj(char *name)
{
	char *path;
	int sp;
	sfVector2f pos;
	sfIntRect rect;
	pnj_t pnj;
	int fd = open(name, O_RDONLY);

	pnj.name = get_next_line(fd);
	path = get_next_line(fd);
	pos = get_pnj_pos(fd);
	rect = get_pnj_rect(fd);
	sp = my_getnbr_i(get_next_line(fd), 0);
	pnj.pnj = create_object(path, pos, rect, sp);
	sfSprite_scale(pnj.pnj->sprite, create_vector2f(2, 2));
	return (pnj);
}

void get_all_pnj(files_t *fi, char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;
	char *name;
	int i = 0;

	while ((entry = readdir(dir)) != 0) {
		if (entry->d_name[0] != '.') {
			name = my_strcat_dup(path, entry->d_name);
			fi->pnj[i] = get_pnj(name);
			free(name);
			i++;
		}
	}
	free(path);
	closedir(dir);
}
