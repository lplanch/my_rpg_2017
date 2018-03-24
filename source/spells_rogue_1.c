/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void rogue_dagger(st_rpg *s)
{

}

void rogue_shadowstep(st_rpg *s)
{

}

void rogue_cloak(st_rpg *s)
{

}

void choose_spell1_rogue(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {rogue_dagger, rogue_shadowstep,
		rogue_cloak};

	(list[s->f.tree.spell1])(s);
}
