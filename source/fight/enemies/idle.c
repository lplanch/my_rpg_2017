/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void enemy_idle(st_rpg *s, int i)
{
	if (s->f.mob[i]->alive && !s->f.mob[i]->aggro && s->f.idlecount < 0) {
		s->f.mob[i]->idle = rand() % 2;
		if (s->f.mob[i]->idle)
			s->f.mob[i]->ratios = get_ratios(rand() % 360);
		else
			s->f.mob[i]->ratios = (sfVector2f{0, 0});
	}
}
