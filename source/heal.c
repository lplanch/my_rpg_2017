/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my.h"
#include "my_rpg.h"

void heal(st_rpg *s, int amount)
{
	s->player.stat->pva += amount;
	if (s->player.stat->pva > s->player.stat->pvm)
		s->player.stat->pva = s->player.stat->pvm;
}
