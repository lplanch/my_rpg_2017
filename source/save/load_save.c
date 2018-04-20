/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

char *get_save_path(st_rpg *s)
{
	char *tmp;
	char *str;

	tmp = my_strcat("saves/", int_to_str(s->save));
	str = my_strcat(tmp, "/");
	free(tmp);
	return (str);
}

st_cdata load_cdata(char *path)
{
	st_cdata cdata;
	int fd = open(path, O_RDONLY);

	cdata.sex = str_to_int(get_next_line(fd));
	cdata.classe = str_to_int(get_next_line(fd));
	cdata.name = get_next_line(fd);
	close(fd);
	return (cdata);
}

void load_save(st_rpg *s)
{
	char *path = get_save_path(s);
	char *tmp = my_strcat(path, "stat");

	s->player.stat = load_stat(tmp);
	free(tmp);
	tmp = my_strcat(path, "cust");
	s->player.cdata = load_cdata(tmp);
	free(tmp);
	tmp = my_strcat(path, "tree");
	load_tree(s, tmp);
	free(tmp);
	free(path);
	s->player.obj = create_object("images/hero.png", create_vector2f(960,
	540), create_rect(0, 0, 48 + 144 * s->player.cdata.sex, 48), 0);
	create_weapon(s);
}