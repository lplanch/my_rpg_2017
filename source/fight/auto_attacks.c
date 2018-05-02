/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_auto_attack(st_rpg *s)
{
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s);
	launch_projectile(s, s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
}

void gunner_auto_attack(st_rpg *s)
{
	s->f.gun.autocount = 0;
	s->f.gun.auto_a = 1;
}

void rogue_auto_attack(st_rpg *s)
{
	if (s->f.rog.vanish > 0 && s->player.tree.passive == 2 &&
		s->player.tree.lock[3]) {
		s->f.rog.vanish = 0;
		rogue_backstab(s);
	} else {
		launch_swing(s, s->f.rog.auto_a[0],
		s->player.weapon[0]);
		s->f.cast = 1;
		s->f.rog.auto_bool = 1;
	}
}

void warrior_auto_attack(st_rpg *s)
{
	s->f.war.auto_a->sens = -s->f.war.auto_a->sens;
	s->f.war.auto_a->begin = -s->f.war.auto_a->begin;
	launch_swing(s, s->f.war.auto_a, s->player.weapon[0]);
	s->f.cast = 1;
}
