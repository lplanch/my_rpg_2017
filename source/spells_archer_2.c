/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_heal(st_rpg *s)
{

}

void archer_leaf(st_rpg *s)
{

}

void choose_spell2_archer(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {archer_heal, archer_leaf};

	(list[s->f.tree.spell2])(s);
}
