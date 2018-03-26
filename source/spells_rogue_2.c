/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void rogue_withdraw(st_rpg *s)
{

}

void rogue_refuge(st_rpg *s)
{

}

void choose_spell2_rogue(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {rogue_withdraw, rogue_refuge};

	(list[s->player.tree.spell2])(s);
}
