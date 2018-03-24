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
	for (int i = 0; i != 20; i += 1)
		destroy_projectile(s->f.arc.arrow[i]);
	destroy_projectile(s->f.arc.axe);
	sfClock_destroy(s->f.arc.kal.clock);
	sfClock_destroy(s->f.arc.barrage.t.clock);
	sfCircleShape_destroy(s->f.arc.barrage.circle);
}

void destroy_spells_gunner(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1)
		destroy_projectile(s->f.gun.bullet[i]);
	sfClock_destroy(s->f.gun.t.clock);
	sfClock_destroy(s->f.gun.blitzt.clock);
	destroy_projectile(s->f.gun.blitz);
	destroy_projectile(s->f.gun.grenade);
	destroy_anim(s->f.gun.explosion);
}

void destroy_spells_rogue(st_rpg *s)
{

}

void destroy_spells_warrior(st_rpg *s)
{

}

void destroy_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {destroy_spells_archer,
	destroy_spells_gunner, destroy_spells_rogue, destroy_spells_warrior};

	(list[s->cust.cdata.classe])(s);
}
