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
		apply_projectile(s->f.arc.arrow[i], s->f.mob);
}

void update_projectile_gunner(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1)
		apply_projectile(s->f.gun.bullet[i], s->f.mob);
	apply_projectile(s->f.gun.blitz, s->f.mob);
}

void update_projectile_rogue(st_rpg *s)
{

}

void update_projectile_warrior(st_rpg *s)
{

}

void update_projectiles(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {update_projectile_archer,
	update_projectile_gunner, update_projectile_rogue,
	update_projectile_warrior};

	(list[s->player.cdata.classe])(s);
}
