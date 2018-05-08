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
	launch_dash(s, s->f.war.ultd);
}

void warrior_endure(st_rpg *s)
{
	s->f.war.endure->count = s->f.war.endure->duration;
	s->f.war.endure->amount = 1000000;
	s->player.stat->def += s->f.war.endure->amount;
}

void choose_spell3_warrior(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {warrior_earthquake, warrior_endure};

	(list[s->player.tree.spell3])(s);
}
