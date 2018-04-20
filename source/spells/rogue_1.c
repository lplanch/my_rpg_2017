/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void rogue_backstab(st_rpg *s)
{
	s->f.cast = 1;
	s->f.rog.bstab = 1;
	s->f.rog.bcount = 0;
	s->f.rog.brat = get_ratios(get_angle(s->window));
	s->f.rog.bpos[0] = s->player.weapon[0]->pos = create_vector2f(960 + 27 *
	s->f.rog.brat.y, 540 - 27 * s->f.rog.brat.x);
	s->f.rog.bpos[1] = s->player.weapon[1]->pos = create_vector2f(960 + 13 *
	s->f.rog.brat.y, 540 - 13 * s->f.rog.brat.x);
	s->f.rog.bpos[0].x -= s->f.rog.brat.x * 50;
	s->f.rog.bpos[0].y -= s->f.rog.brat.y * 50;
	s->f.rog.bpos[1].x -= s->f.rog.brat.x * 50;
	s->f.rog.bpos[1].y -= s->f.rog.brat.y * 50;
}

void rogue_dance(st_rpg *s)
{
	launch_projectile(s->f.rog.dance, get_angle(s->window));
}

void rogue_shadowstep(st_rpg *s)
{

}

void rogue_cloak(st_rpg *s)
{

}

void choose_spell1_rogue(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {rogue_dance, rogue_shadowstep,
		rogue_cloak};

	(list[s->player.tree.spell1])(s);
}