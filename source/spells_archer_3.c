/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_axe(st_rpg *s)
{
	s->f.arc.axe->rpos = create_vector2f(920, 540);
	s->f.arc.axe->angle = get_angle(s->window);
	s->f.arc.axeangle = s->f.arc.axe->angle - 70;
	launch_projectile(s->f.arc.axe, s->f.arc.axe->angle - 70);
}

void archer_barrage(st_rpg *s)
{
	sfCircleShape_setPosition(s->f.arc.barrage.circle,
	create_vector2f(sfMouse_getPositionRenderWindow(s->window).x - 100,
	sfMouse_getPositionRenderWindow(s->window).y - 100));
	sfClock_restart(s->f.arc.barrage.t.clock);
	s->f.arc.barrage.t.sec = 0.0;
	s->f.arc.barrage.shot = 1;
}

void choose_spell3_archer(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {archer_barrage, archer_axe};

	(list[s->f.tree.spell3])(s);
}
