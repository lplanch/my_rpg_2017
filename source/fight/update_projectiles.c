/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_projectile_archer(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1)
		apply_projectile(s, s->f.arc.arrow[i], s->f.mob);
}

void update_projectile_gunner(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1) {
		apply_projectile(s, s->f.gun.bullet[i], s->f.mob);
		apply_projectile(s, s->f.gun.ultb[i], s->f.mob);
	}
	apply_projectile(s, s->f.gun.blitz, s->f.mob);
}

void update_projectile_rogue(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		apply_projectile(s, s->f.rog.dagger[i], s->f.mob);
	apply_projectile(s, s->f.rog.dance, s->f.mob);
}

void update_projectiles(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {update_projectile_archer,
	update_projectile_gunner, update_projectile_rogue};

	if (s->player.cdata.classe != 3)
		(list[s->player.cdata.classe])(s);
}