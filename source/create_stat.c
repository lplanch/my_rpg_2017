/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

stat_t *create_first_stat(void)
{
	stat_t *stat = malloc(sizeof(stat_t));

	stat->pvm = 100;
	stat->pva = 100;
	stat->frc = 10;
	stat->def = 10;
	stat->prc = 10;
	stat->vit = 10;
	stat->cha = 5;
	stat->exp = 0;
	stat->lvl = 1;
	return (stat);
}

stat_t *load_stat(char *path)
{
	int fd = open(path, O_RDONLY);
	stat_t *stat = malloc(sizeof(stat_t));

	stat->pvm = str_to_int(get_next_line(fd));
	stat->pva = str_to_int(get_next_line(fd));
	stat->frc = str_to_int(get_next_line(fd));
	stat->def = str_to_int(get_next_line(fd));
	stat->prc = str_to_int(get_next_line(fd));
	stat->vit = str_to_int(get_next_line(fd));
	stat->cha = str_to_int(get_next_line(fd));
	stat->exp = str_to_int(get_next_line(fd));
	stat->lvl = str_to_int(get_next_line(fd));
	close(fd);
	return (stat);
}
