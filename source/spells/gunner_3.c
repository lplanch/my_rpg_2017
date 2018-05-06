/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_ult(st_rpg *s)
{
	float angle = get_angle(s);

	s->f.gun.ultrat = get_ratios(angle);
	s->f.gun.ult = 1;
	s->f.cast = 2;
	stop_player(s);
	for (int i = 0; i != 10; i += 1) {
		s->f.gun.ultb[i]->dmg = s->f.gun.origin;
		s->f.gun.ultb[i]->angle = angle + 30 - i * 6;
		sfSprite_setRotation(s->f.gun.trait[i]->sprite,
		s->f.gun.ultb[i]->angle);
		sfSprite_setPosition(s->f.gun.trait[i]->sprite,
		create_vector2f(s->origin.x + 960 + 10 * s->f.gun.ultrat.x,
			s->origin.y + 540 +
		10 * s->f.gun.ultrat.y));
		s->f.gun.trait[i]->rect.width = 0;
		s->f.gun.trait[i]->rect.height = 10;
		sfSprite_setTextureRect(s->f.gun.trait[i]->sprite,
		s->f.gun.trait[i]->rect);
	}
}

void gunner_flamethrower(st_rpg *s)
{
	s->f.gun.cflame = 0;
	s->f.gun.flamet = 1;
	s->f.cast = 1;
	s->f.gun.flamestay = 4;
	for (int i = 0; i != 100; i += 1)
		s->f.gun.flame[i]->obj->speed = s->f.gun.cdiminution;
	sfClock_restart(s->f.gun.t.clock);
	launch_particle(s->f.gun.partf, s->player.obj->pos, get_angle(s));
}

void choose_spell3_gunner(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {gunner_ult, gunner_flamethrower};

	(list[s->player.tree.spell3])(s);
}
