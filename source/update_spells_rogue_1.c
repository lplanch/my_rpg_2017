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
	if (s->f.rog.ultcount > 100) {
		s->f.rog.ulting = 0;
		s->f.rog.ultcount = 0;
	} if (s->f.rog.current > 29)
		s->f.rog.current = 0;
}

void rogue_update_storm(st_rpg *s)
{
	s->f.rog.ultt.time = sfClock_getElapsedTime(s->f.rog.ultt.clock);
	s->f.rog.ultt.sec = s->f.rog.ultt.time.microseconds / 1000000.0;
	if (s->f.rog.ultt.sec > s->f.rog.ultspeed && s->f.rog.ulting) {
		for (int i = 0; i != 2; i += 1) {
			s->f.rog.dagger[s->f.rog.current]->angle = i * 180 +
			s->f.rog.ultangle + s->f.rog.side % 2 * 90;
			launch_projectile(s->f.rog.dagger[s->f.rog.current],
			s->f.rog.dagger[s->f.rog.current]->angle);
			s->f.rog.current += 1;
			s->f.rog.ultcount += 1;
			update_current_dagger(s);
		}
		s->f.rog.side += 3;
		s->f.rog.ultangle += s->f.rog.side;
		sfClock_restart(s->f.rog.ultt.clock);
	}
}
