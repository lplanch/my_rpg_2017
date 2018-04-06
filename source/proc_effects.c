/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void proc_effect_archer(st_rpg *s)
{
	proc_effect(s->f.arc.leaf);
	if (s->f.arc.leaf->count <= 0) {
		s->f.player.stat->frc -= s->f.arc.leaf.amount;
	}
}

void proc_effect_gunner(st_rpg *s)
{

}

void proc_effect_rogue(st_rpg *s)
{

}

void proc_effect_warrior(st_rpg *s)
{
	//proc_effect(s, s->f.war.shield);
	//apply_projectile(s->f.war.hasagi, s->f.mob);
}

void proc_effects(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {proc_effect_archer,
	proc_effect_gunner, proc_effect_rogue, proc_effect_warrior};

	(list[s->player.cdata.classe])(s);
}
