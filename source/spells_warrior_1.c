/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_rush(st_rpg *s)
{

}

void warrior_whirlwing(st_rpg *s)
{

}

void warrior_estoc(st_rpg *s)
{

}

void choose_spell1_warrior(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {warrior_rush, warrior_whirlwing,
		warrior_estoc};

	(list[s->player.tree.spell1])(s);
}
