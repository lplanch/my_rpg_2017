/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void rogue_storm(st_rpg *s)
{

}

void rogue_blind(st_rpg *s)
{

}

void choose_spell3_rogue(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {rogue_storm, rogue_blind};

	(list[s->f.tree.spell3])(s);
}
