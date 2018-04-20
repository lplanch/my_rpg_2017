/*
** EPITECH PROJECT, 2018
** check_pnj.c
** File description:
** check_pnj file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void check_pnj_withpos(st_rpg *s, int j, int i)
{
	if (s->fi->pos[j].x < (s->fi->pnj[i].pnj->pos.x +
	s->fi->ID_characters->rect.width + 14)
	&& (s->fi->pos[j].x > s->fi->pnj[i].pnj->pos.x + 14)
	&& (s->fi->pos[j].y < s->fi->pnj[i].pnj->pos.y +
	s->fi->ID_characters->rect.height + 66)
	&& (s->fi->pos[j].y > s->fi->pnj[i].pnj->pos.y + 66)) {
		s->fi->dialog_box_isopen = 1;
		s->fi->nb_pnj = i;
	}
}

void check_pnj(st_rpg *s)
{
	int i = 0;
	int j = 0;

	while (i != s->fi->max_pnj) {
		j = 0;
		while (j != 10) {
			check_pnj_withpos(s, j, i);
			j++;
		}
		i++;
	}
}
