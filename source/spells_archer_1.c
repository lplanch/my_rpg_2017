/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_salve(st_rpg *s)
{
	for (int i = -3; i != 4; i += 1) {
		s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window) +
		i * 5;
		launch_projectile(s->f.arc.arrow[s->f.arc.current],
		s->f.arc.arrow[s->f.arc.current]->angle);
		s->f.arc.current += 1;
		update_current_arrow(s);
	}
}

void archer_leap(st_rpg *s)
{

}

void archer_kalash(st_rpg *s)
{
	s->f.arc.kalashcount = 0;
	s->f.arc.kalash = 1;
}

void choose_spell1_archer(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {archer_kalash, archer_leap, archer_salve};

	(list[s->player.tree.spell1])(s);
}
