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
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window);
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
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

}

void warrior_auto_attack(st_rpg *s)
{

}