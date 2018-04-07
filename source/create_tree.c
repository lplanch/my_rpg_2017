/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_first_tree(st_rpg *s)
{
	s->player.tree.lockp1 = 0;
	s->player.tree.lockp2 = 0;
	s->player.tree.lockp3 = 0;
	s->player.tree.lockm1 = 0;
	s->player.tree.lockm2 = 0;
	s->player.tree.lockm3 = 0;
	s->player.tree.locke1 = 0;
	s->player.tree.locke2 = 0;
	s->player.tree.lockr1 = 0;
	s->player.tree.lockr2 = 0;
	s->player.tree.passive = 3;
	s->player.tree.spell1 = 3;
	s->player.tree.spell2 = 3;
	s->player.tree.spell3 = 3;
	s->player.tree.skillp = 0;
}

void load_tree(st_rpg *s, char *path)
{
	int fd = open(path, O_RDONLY);

	s->player.tree.lockp1 = str_to_int(get_next_line(fd));
	s->player.tree.lockp2 = str_to_int(get_next_line(fd));
	s->player.tree.lockp3 = str_to_int(get_next_line(fd));
	s->player.tree.lockm1 = str_to_int(get_next_line(fd));
	s->player.tree.lockm2 = str_to_int(get_next_line(fd));
	s->player.tree.lockm3 = str_to_int(get_next_line(fd));
	s->player.tree.locke1 = str_to_int(get_next_line(fd));
	s->player.tree.locke2 = str_to_int(get_next_line(fd));
	s->player.tree.lockr1 = str_to_int(get_next_line(fd));
	s->player.tree.lockr2 = str_to_int(get_next_line(fd));
	s->player.tree.passive = str_to_int(get_next_line(fd));
	s->player.tree.spell1 = str_to_int(get_next_line(fd));
	s->player.tree.spell2 = str_to_int(get_next_line(fd));
	s->player.tree.spell3 = str_to_int(get_next_line(fd));
	s->player.tree.skillp = str_to_int(get_next_line(fd));
	close(fd);
}
