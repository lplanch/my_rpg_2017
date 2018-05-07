/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_current_bullet(st_rpg *s)
{
	s->f.gun.current += 1;
	if (s->f.gun.current > 9) {
		s->f.gun.ult = 0;
		s->f.gun.auto_a = 0;
		s->f.gun.current = 0;
	}
}

void gunner_update_blitz(st_rpg *s)
{
	update_projectile(s->f.gun.blitz);
	s->f.gun.blitzt.time = sfClock_getElapsedTime(s->f.gun.blitzt.clock);
	s->f.gun.blitzt.sec = s->f.gun.blitzt.time.microseconds / 1000000.0;
	if (s->f.gun.blitzt.sec > 0.1 && s->f.gun.blitz->shot) {
		s->f.gun.blitz->obj->rect.left += 40;
		if (s->f.gun.blitz->obj->rect.left >= 80) {
			s->f.gun.blitz->obj->rect.left = 0;
			s->f.gun.blitz->obj->rect.top += 15;
		} if (s->f.gun.blitz->obj->rect.top >= 60)
			s->f.gun.blitz->obj->rect.top = 0;
		sfSprite_setTextureRect(s->f.gun.blitz->obj->sprite,
		s->f.gun.blitz->obj->rect);
		sfClock_restart(s->f.gun.blitzt.clock);
	}
}

void gunner_update_grenade_speed(st_rpg *s)
{
	if (s->f.gun.grenade->shot == 2) {
		clocked_animation(s->f.gun.explosion);
		if (s->f.gun.explosion->li >= s->f.gun.explosion->ver) {
			s->f.gun.grenade->obj->speed = s->f.gun.grenadespeed;
			s->f.gun.grenade->shot = 0;
		}
	} else if (s->f.gun.grenade->shot == 1) {
		if (s->f.gun.explosion->t.sec > s->f.gun.explosion->speed &&
		s->f.gun.grenade->obj->speed > 0) {
			s->f.gun.grenade->obj->speed -= s->f.gun.grenade
			->range / 4800;
			sfClock_restart(s->f.gun.explosion->t.clock);
		}
		update_projectile(s->f.gun.grenade);
	}
}

void proc_grenade(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		launch_particle(s->f.gun.partf, s->f.gun.grenade->obj->pos,
		get_angle(s));
		if (circle_hitbox(s->f.gun.explo, s->f.mob[i]->obj) &&
		s->f.mob[i]->alive)
			s->f.mob[i]->stat->pva -= 70 + 15 * s->player.stat->lvl;
	}
}

void gunner_update_grenade(st_rpg *s)
{
	s->f.gun.explosion->t.time = sfClock_getElapsedTime(s->f.gun.explosion
	->t.clock);
	s->f.gun.explosion->t.sec = s->f.gun.explosion->t.time.microseconds /
	1000000.0;
	if (s->f.gun.explosion->t.sec >= s->f.gun.delay &&
	s->f.gun.grenade->shot == 1) {
		s->f.gun.explosion->obj->pos = create_vector2f(s->f.gun.grenade
		->obj->pos.x - 50 * 1.8,
		s->f.gun.grenade->obj->pos.y - 50 * 1.8);
		sfSprite_setPosition(s->f.gun.explosion->obj->sprite,
		s->f.gun.explosion->obj->pos);
		sfCircleShape_setPosition(s->f.gun.explo,
		s->f.gun.explosion->obj->pos);
		s->f.gun.grenade->shot = 2;
		s->f.gun.explosion->li = 0;
		s->f.gun.explosion->c = 0;
		proc_grenade(s);
	}
	gunner_update_grenade_speed(s);
}

void gunner_update_ultimate(st_rpg *s)
{
	s->f.gun.t.time = sfClock_getElapsedTime(s->f.gun.t.clock);
	s->f.gun.t.sec = s->f.gun.t.time.microseconds / 1000000.0;
	if (s->f.gun.t.sec > 0.1 && s->f.gun.ult == 1) {
		for (int i = 0; i != 10; i += 1) {
			s->f.gun.ultb[i]->dmg += s->f.gun.ultb[i]->dmgratio;
		}
		if (s->f.gun.ultb[0]->dmg > s->f.gun.origin * 5 ||
			sfMouse_isButtonPressed(sfMouseLeft))
			s->f.gun.ult = 2;
		sfClock_restart(s->f.gun.t.clock);
	} if (s->f.gun.t.sec > 0.1 && s->f.gun.ult == 2) {
		launch_projectile(s, s->f.gun.ultb[s->f.gun.current],
		s->f.gun.ultb[s->f.gun.current]->angle);
		update_current_bullet(s);
		sfClock_restart(s->f.gun.t.clock);
		if (s->f.gun.current == 0) {
			s->f.gun.ult = 0;
			s->f.cast = 0;
		}
	}
}

void gunner_update_auto_attack(st_rpg *s)
{
	s->f.gun.t.time = sfClock_getElapsedTime(s->f.gun.t.clock);
	s->f.gun.t.sec = s->f.gun.t.time.microseconds / 1000000.0;
	if (s->f.gun.t.sec > s->f.gun.autospeed && s->f.gun.auto_a == 1) {
		s->f.gun.bullet[s->f.gun.current]->angle = get_angle(s);
		launch_projectile(s, s->f.gun.bullet[s->f.gun.current],
		s->f.gun.bullet[s->f.gun.current]->angle);
		launch_particle(s->f.gun.partg,
		s->player.weapon[rand() % 2]->pos, get_angle(s));
		update_current_bullet(s);
		sfClock_restart(s->f.gun.t.clock);
	} if (s->f.gun.bullet[9]->shot == 2) {
		clocked_animation(s->f.gun.expbullet);
		if (s->f.gun.expbullet->li >= s->f.gun.expbullet->ver)
			s->f.gun.bullet[9]->shot = 0;
	}
}

void gunner_update_flamet_animation(st_rpg *s)
{
	for (int i = 0; i != 100; i += 1) {
		if (s->f.gun.flame[i]->shot) {
			s->f.gun.flame[i]->obj->rect.top += 30;
			if (s->f.gun.flame[i]->obj->rect.top > 180)
				s->f.gun.flame[i]->obj->rect.top = 0;
			sfSprite_setTextureRect(s->f.gun.flame[i]->obj->sprite,
			s->f.gun.flame[i]->obj->rect);
		} if (s->f.gun.flame[i]->obj->speed > 0 &&
			s->f.gun.flame[i]->shot)
			s->f.gun.flame[i]->obj->speed -= s->f.gun.cdiminution
			/ 100;
	}
}

void update_flame(st_rpg *s)
{
	if (s->f.gun.cflame > 99) {
		s->f.gun.cflame = 0;
		for (int i = 0; i != 100; i += 1)
			s->f.gun.flame[i]->obj->speed = s->f.gun.cdiminution;
	}
}

void gunner_update_flamet(st_rpg *s)
{
	s->f.gun.t.time = sfClock_getElapsedTime(s->f.gun.t.clock);
	s->f.gun.t.sec = s->f.gun.t.time.microseconds / 1000000.0;
	if (s->f.gun.t.sec > 0.01 && s->f.gun.flamet == 1) {
		s->f.gun.flame[s->f.gun.cflame]->angle = get_angle(s);
		launch_projectile(s, s->f.gun.flame[s->f.gun.cflame],
		s->f.gun.flame[s->f.gun.cflame]->angle);
		s->f.gun.cflame += 1;
		s->f.gun.flamestay -= s->f.gun.t.sec;
		s->f.gun.t.sec = 0;
		update_flame(s);
		sfClock_restart(s->f.gun.t.clock);
		gunner_update_flamet_animation(s);
		if (s->f.gun.flamestay < 0) {
			s->f.gun.flamet = 0;
			s->f.cast = 0;
		}
	}
}
