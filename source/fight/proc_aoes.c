/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void proc_aoe_archer(st_rpg *s)
{
	proc_aoe(s, s->f.arc.heal);
	proc_aoe(s, s->f.arc.barrage);
	apply_projectile(s, s->f.arc.axe, s->f.mob);
}

void proc_aoe_rogue(st_rpg *s)
{
	proc_aoe(s, s->f.rog.zone);
	proc_aoe(s, s->f.rog.flash);
}

void proc_aoe_warrior(st_rpg *s)
{
	proc_aoe(s, s->f.war.crack);
	proc_aoe(s, s->f.war.shield);
	apply_projectile(s, s->f.war.hasagi, s->f.mob);
}

void proc_aoes(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {proc_aoe_archer,
		proc_aoe_rogue, proc_aoe_rogue, proc_aoe_warrior};

	if (s->player.cdata.classe != 1)
		(list[s->player.cdata.classe])(s);
}
