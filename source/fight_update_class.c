/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_archer(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1)
		update_projectile(s->f.arc.arrow[i]);
	update_kalash(s);
	update_axe(s);
	update_aoe(s->f.arc.barrage);
	update_aoe(s->f.arc.heal);
}

void update_gunner(st_rpg *s)
{
	gunner_update_auto_attack(s);
	gunner_update_grenade(s);
	for (int i = 0; i != 10; i += 1)
		update_projectile(s->f.gun.bullet[i]);
	gunner_update_blitz(s);
}

void update_rogue(st_rpg *s)
{

}

void update_warrior(st_rpg *s)
{

}

void update_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {update_archer, update_gunner,
		update_rogue, update_warrior};

	(list[s->cust.cdata.classe])(s);
}
