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
		s->f.panim = 0;
		s->f.rog.ulting = 0;
		s->f.rog.ultcount = 0;
	} if (s->f.rog.current > 29)
		s->f.rog.current = 0;
}

void change_side_player(st_rpg *s)
{
	switch (s->f.rog.ultr.top)
	{
		case 0 :
			s->f.rog.ultr.top = 48;
			break;
		case 48 :
			s->f.rog.ultr.top = 144;
			break;
		case 144 :
			s->f.rog.ultr.top = 96;
			break;
		case 96 :
			s->f.rog.ultr.top = 0;
			break;
	}
	s->player.obj->rect = s->f.rog.ultr;
	sfSprite_setTextureRect(s->player.obj->sprite, s->player.obj->rect);
}

void rogue_update_storm(st_rpg *s)
{
	s->f.rog.ultt.time = sfClock_getElapsedTime(s->f.rog.ultt.clock);
	s->f.rog.ultt.sec = s->f.rog.ultt.time.microseconds / 1000000.0;
	if (s->f.rog.ultt.sec > s->f.rog.ultspeed && s->f.rog.ulting) {
		for (int i = 0; i != 2; i += 1) {
			s->f.rog.dagger[s->f.rog.current]->angle = i * 180 +
			s->f.rog.ultangle + s->f.rog.side % 2 * 90;
			launch_projectile(s, s->f.rog.dagger[s->f.rog.current],
			s->f.rog.dagger[s->f.rog.current]->angle);
			s->f.rog.current += 1;
			s->f.rog.ultcount += 1;
			update_current_dagger(s);
		}
		change_side_player(s);
		s->f.rog.side += 3;
		s->f.rog.ultangle += s->f.rog.side;
		sfClock_restart(s->f.rog.ultt.clock);
	}
}

void rogue_update_backstab(st_rpg *s)
{
	s->f.rog.bcount += 14;
	s->f.rog.bpos[0].x += s->f.rog.brat.x * 10;
	s->f.rog.bpos[0].y += s->f.rog.brat.y * 10;
	sfSprite_setPosition(s->player.weapon[0]->sprite,
	s->f.rog.bpos[0]);
	sfSprite_setScale(s->player.weapon[0]->sprite,
	create_vector2f(1, 1));
	s->f.rog.bpos[1].x += s->f.rog.brat.x * 10;
	s->f.rog.bpos[1].y += s->f.rog.brat.y * 10;
	sfSprite_setPosition(s->player.weapon[1]->sprite, s->f.rog.bpos[1]);
	sfSprite_setScale(s->player.weapon[1]->sprite,
	create_vector2f(1, 1));
	s->player.weapon[0]->pos = s->f.rog.bpos[0];
	s->player.weapon[1]->pos = s->f.rog.bpos[1];
	if (hitbox(s->player.weapon[0], s->f.mob->obj)) {
		s->f.mob->stat->pva -= s->f.rog.bdmg;
	} if (s->f.rog.bcount >= 100) {
		s->f.cast = 0;
		s->f.rog.bstab = 0;
	}
}

void rogue_update_auto_attack(st_rpg *s)
{
	if (s->f.rog.bstab == 1) {
		rogue_update_backstab(s);
		return;
	}
	update_swing(s, s->f.rog.auto_a[0], s->player.weapon[0]);
	update_swing(s, s->f.rog.auto_a[1], s->player.weapon[1]);
	if (s->f.rog.auto_bool == 1 && s->f.rog.auto_a[0]->shot == 0) {
		launch_swing(s, s->f.rog.auto_a[1],
		s->player.weapon[1]);
		s->f.rog.auto_bool = 2;
		s->f.cast = 1;
	} if (s->f.rog.auto_bool == 2 && s->f.rog.auto_a[1]->shot == 0) {
		s->f.rog.auto_bool = 0;
	}
}
