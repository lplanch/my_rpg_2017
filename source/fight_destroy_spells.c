/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_spells_archer(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1) {
		destroy_projectile(s->f.arc.arrow[i]);
	}
	destroy_projectile(s->f.arc.axe);
	sfClock_destroy(s->f.arc.kal.clock);
	destroy_aoe(s->f.arc.barrage);
	destroy_aoe(s->f.arc.heal);
	destroy_effect(s->f.arc.leaf);
}

void destroy_spells_gunner(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1) {
		destroy_projectile(s->f.gun.bullet[i]);
		destroy_projectile(s->f.gun.ultb[i]);
		destroy_object(s->f.gun.trait[i]);
	}
	sfClock_destroy(s->f.gun.t.clock);
	sfClock_destroy(s->f.gun.blitzt.clock);
	destroy_projectile(s->f.gun.blitz);
	destroy_projectile(s->f.gun.grenade);
	destroy_anim(s->f.gun.explosion);
	sfCircleShape_destroy(s->f.gun.explo);
}

void destroy_spells_rogue(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		destroy_projectile(s->f.rog.dagger[i]);
	sfClock_destroy(s->f.rog.ultt.clock);
	destroy_projectile(s->f.rog.dance);
	destroy_swing(s->f.rog.auto_a[0]);
	destroy_swing(s->f.rog.auto_a[1]);
}

void destroy_spells_warrior(st_rpg *s)
{
	destroy_aoe(s->f.war.shield);
	destroy_swing(s->f.war.auto_a);
	destroy_projectile(s->f.war.hasagi);
}

void destroy_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {destroy_spells_archer,
	destroy_spells_gunner, destroy_spells_rogue, destroy_spells_warrior};

	(list[s->player.cdata.classe])(s);
}
