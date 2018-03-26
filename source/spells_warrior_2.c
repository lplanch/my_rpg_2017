/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_stance(st_rpg *s)
{

}

void warrior_lifesteal(st_rpg *s)
{

}

void choose_spell2_warrior(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {warrior_stance, warrior_lifesteal};

	(list[s->player.tree.spell2])(s);
}
