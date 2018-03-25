/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_current_dagger(st_rpg *s)
{
	if (s->f.rog.current > 9)
		s->f.rog.current = 0;
}

void rogue_update_storm(st_rpg *s)
{
	s->f.rog.ultt.time = sfClock_getElapsedTime(s->f.rog.ultt.clock);
	s->f.rog.ultt.sec = s->f.rog.ultt.time.microseconds / 1000000.0;
	if (s->f.rog.ultt.sec > s->f.rog.ultspeed && s->f.rog.ulting) {
		s->f.rog.dagger[s->f.rog.current]->angle = rand() % 360;
		launch_projectile(s->f.rog.dagger[s->f.rog.current],
		s->f.rog.dagger[s->f.rog.current]->angle);
		s->f.rog.current += 1;
		s->f.rog.ultcount += 1;
		if (s->f.rog.ultcount > 39) {
			s->f.rog.ulting = 0;
			s->f.rog.ultcount = 0;
		}
		update_current_dagger(s);
		sfClock_restart(s->f.rog.ultt.clock);
	}
}
