/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_archer_passive(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1) {
		s->f.arc.arrow[i] = create_projectile("ressources/proj/Arrow");
		if (s->player.tree.passive == 0) {
			s->f.arc.arrow[i]->dmg += s->f.arc.arrow[i]->dmg * 0.1;
			s->f.arc.arrow[i]->obj->speed += s->f.arc.arrow[i]
			->obj->speed * 0.5;
		} if (s->player.tree.passive == 1)
			s->f.arc.arrow[i]->effect = "slow";
		if (s->player.tree.passive == 2) {
			//s->player->obj->speed += s->player->obj->speed * 0.2;
		}
	}
}

void create_archer_projectiles(st_rpg *s)
{
	s->f.arc.axe = create_projectile("ressources/proj/Axe");
	s->f.arc.kal = create_st_time();
	s->f.arc.current = 0;
	s->f.arc.kalash = 0;
	s->f.arc.axeangle = 0;
	s->f.arc.kalashcount = 0;
	s->f.arc.kalashspeed = 0.08;
	s->f.arc.heal = create_aoe_from_file("ressources/spells/0/Heal");
	s->f.arc.barrage = create_aoe_from_file("ressources/spells/0/Barrage");
	s->f.arc.leaf = create_effect("power", 0, 6);
}