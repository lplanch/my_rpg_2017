/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

/*void launch_samy_dash(st_rpg *s)
{
}

void launch_samy_dash(st_rpg *s)
{
}*/

void update_samy_dash(st_rpg *s)
{
	if (s->f.boss.dash->on) {
		s->f.boss.dash->count -= s->f.boss.dash->speed;
		if (s->f.boss.dash->count <= 0) {
			s->f.mob[0]->cast = 0;
			s->f.boss.dash->on = 0;
		}
	}
}

void launch_samy_dash(st_rpg *s)
{
	s->f.boss.dash->ratios = get_ratios(get_angle_enemy(s, 0));
	s->f.mob[0]->cast = 2;
	s->f.boss.dash->on = 1;
	s->f.boss.dash->count = s->f.boss.dash->range;
	s->player.nbr_frame.x = s->f.boss.dash->ratios.x * s->f.boss.dash->speed;
	s->player.nbr_frame.y = s->f.boss.dash->ratios.y * s->f.boss.dash->speed;
}

void launch_samy_spell(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {launch_samy_dash,
	launch_samy_dash, launch_samy_dash};

	s->f.boss.attack = rand() % 3;
	(list[s->f.boss.attack])(s);
}
