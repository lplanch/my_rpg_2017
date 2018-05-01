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
	if (s->f.arc.leaf->count <= 0 && s->f.arc.leaf->amount != 0) {
		s->player.stat->frc -= s->f.arc.leaf->amount;
		s->f.arc.leaf->amount = 0;
	}
}

void proc_effect_gunner(st_rpg *s)
{

}

void proc_effect_rogue(st_rpg *s)
{
	if (s->f.rog.vanish > 0)
		s->f.rog.vanish -= 0.1;
}

void proc_effect_warrior(st_rpg *s)
{
	proc_effect(s->f.war.endure);
	proc_effect(s->f.war.lifesteal);
	if (s->f.war.endure->count <= 0 && s->f.war.endure->amount != 0) {
		s->player.stat->def -= s->f.war.endure->amount;
		s->f.war.endure->amount = 0;
	}
}

void proc_effects(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {proc_effect_archer,
		proc_effect_gunner, proc_effect_rogue, proc_effect_warrior};

	(list[s->player.cdata.classe])(s);
}
