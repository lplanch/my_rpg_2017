/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_earthquake(st_rpg *s)
{

}

void warrior_endure(st_rpg *s)
{

}

void choose_spell3_warrior(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {warrior_earthquake, warrior_endure};

	(list[s->f.tree.spell3])(s);
}
