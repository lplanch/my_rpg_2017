/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_blitz(st_rpg *s)
{
	launch_projectile(s->f.gun.blitz, get_angle(s->window));
}

void gunner_medikit(st_rpg *s)
{
	heal(s, s->player.stat->pvm / 3);
}

void gunner_grenade(st_rpg *s)
{
	launch_projectile(s->f.gun.grenade, get_angle(s->window));
	sfClock_restart(s->f.gun.explosion->t.clock);
}

void choose_spell1_gunner(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {gunner_blitz, gunner_medikit,
		gunner_grenade};

	(list[s->player.tree.spell1])(s);
}
