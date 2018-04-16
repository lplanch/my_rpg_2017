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
	s->player.tree.passive = 0;
	s->player.tree.spell1 = 0;
	s->player.tree.spell2 = 0;
	s->player.tree.spell3 = 0;
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

void save_tree_2(int fd, tree_t tree)
{
	char value = tree.locke2 + 48;

	write_a_value(fd, &value, 1);
	value = tree.lockr1 + 48;
	write_a_value(fd, &value, 1);
	value = tree.lockr2 + 48;
	write_a_value(fd, &value, 1);
	value = tree.passive + 48;
	write_a_value(fd, &value, 1);
	value = tree.spell1 + 48;
	write_a_value(fd, &value, 1);
	value = tree.spell2 + 48;
	write_a_value(fd, &value, 1);
	value = tree.spell3 + 48;
	write_a_value(fd, &value, 1);
	value = tree.spellp + 48;
	write_a_value(fd, &value, 1);
}

void save_tree(tree_t tree, char *path)
{
	char *path_tree = my_strcat(path, "tree");
	int fd = open(path, O_WRONLY | O_TRUNC | O_CREAT);
	char value = tree.lockp1 + 48;

	write_a_value(fd, &value, 1);
	value = tree.lockp2 + 48;
	write_a_value(fd, &value, 1);
	value = tree.lockp3 + 48;
	write_a_value(fd, &value, 1);
	value = tree.lockm1 + 48;
	write_a_value(fd, &value, 1);
	value = tree.lockm2 + 48;
	write_a_value(fd, &value, 1);
	value = tree.lockm3 + 48;
	write_a_value(fd, &value, 1);
	value = tree.locke1 + 48;
	write_a_value(fd, &value, 1);
	save_tree_2(fd, tree);
	close(fd);
	free(path_tree);
}
