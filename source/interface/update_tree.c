/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my_rpg.h"
#include "my.h"

char **get_spinfo(st_rpg *s)
{
	char *tmp = int_to_str(s->player.cdata.classe);
	char **tab = malloc(sizeof(char *) * 21);
	char *str = my_strcat("spells/", tmp);
	int fd;

	free(tmp);
	tmp = my_strcat(str, "/names");
	free(str);
	fd = open(tmp, O_RDONLY);
	for (int i = 0; i != 20; i += 1)
		tab[i] = get_next_line(fd);
	tab[20] = NULL;
	return (tab);
}


void tree_set_rects(st_rpg *s)
{
	for (int i = 0; i != 3; i += 1) {
		s->treem.pas[i]->rect = create_rect(0, 0, 64, 64);
		s->treem.m2[i]->rect = create_rect(0, 0, 64, 64);
		if (i != 2) {
			s->treem.e[i]->rect = create_rect(0, 0, 64, 64);
			s->treem.r[i]->rect = create_rect(0, 0, 64, 64);
		}
	}
}


void update_tree_pos(st_rpg *s)
{
	sfSprite_setPosition(s->treem.select[0]->sprite,
	create_vector2f(1535 + s->player.tree.passive * 125, 90));
	sfSprite_setPosition(s->treem.select[1]->sprite,
	create_vector2f(1535 + s->player.tree.spell1 * 125, 180));
	sfSprite_setPosition(s->treem.select[2]->sprite,
	create_vector2f(1596 + s->player.tree.spell2 * 124, 270));
	sfSprite_setPosition(s->treem.select[3]->sprite,
	create_vector2f(1596 + s->player.tree.spell3 * 124, 360));
	for (int i = 0, dec = 0, m = 3, d = 0; i != 10; i += 1) {
		if (i > 5) {
			d = 61;
			m = 2;
			dec = -90;
		}
		sfSprite_setPosition(s->treem.lock[i]->sprite,
		create_vector2f(1535 + d + (i % m) * 125 + 13,
		90 + (i / m) * 90 + dec + 13));
	}
}

void update_tree_mouse(st_rpg *s, int i)
{
	if (mouse_in_object(s->treem.pas[i], s->window))
		tree_proceed(s, i);
	if (mouse_in_object(s->treem.m2[i], s->window))
		tree_proceed(s, i + 3);
	if (i != 2) {
		if (mouse_in_object(s->treem.e[i], s->window))
			tree_proceed(s, i + 6);
		if (mouse_in_object(s->treem.r[i], s->window))
			tree_proceed(s, i + 8);
	}
}

void update_tree_menu(st_rpg *s)
{
	if (s->treem.shot == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
		for (int i = 0; i != 3; i += 1) {
			update_tree_mouse(s, i);
		}
		update_tree_pos(s);
	}
}
