/*
** EPITECH PROJECT, 2018
** check_pnj.c
** File description:
** check_pnj file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void check_pnj(files_t *fi)
{
	int i = 0;
	int j = 0;

	while (i != fi->max_pnj) {
		j = 0;
		while (j != 10) {
			if (fi->pos[j].x < (fi->pnj[i].pnj->pos.x + fi->ID_characters->rect.width + 14)
			&& (fi->pos[j].x > fi->pnj[i].pnj->pos.x + 14)
			&& (fi->pos[j].y < fi->pnj[i].pnj->pos.y + fi->ID_characters->rect.height + 66)
			&& (fi->pos[j].y > fi->pnj[i].pnj->pos.y + 66)) {
				fi->dialog_box_isopen = 1;
				fi->nb_pnj = i;
			}
			j++;
		}
		i++;
	}
}
