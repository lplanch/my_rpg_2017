/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_first_tree(st_rpg *s)
{
	s->player.tree.passive = 0;
	s->player.tree.spell1 = 0;
	s->player.tree.spell2 = 0;
	s->player.tree.spell3 = 0;
}
