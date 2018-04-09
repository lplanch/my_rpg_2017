/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

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
