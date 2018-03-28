/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_effects(st_rpg *s)
{
	s->f.proc.time = sfClock_getElapsedTime(s->f.proc.clock);
	s->f.proc.sec = s->f.proc.time.microseconds / 1000000.0;
	if (s->f.proc.sec > 0.1) {
		proc_aoes(s);
		sfClock_restart(s->f.proc.clock);
	}
}
