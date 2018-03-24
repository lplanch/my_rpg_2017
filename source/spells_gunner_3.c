/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_snipe(st_rpg *s)
{

}

void gunner_turret(st_rpg *s)
{

}

void choose_spell3_gunner(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {gunner_snipe, gunner_turret};

	(list[s->f.tree.spell3])(s);
}
