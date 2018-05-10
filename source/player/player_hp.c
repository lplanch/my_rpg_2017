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

void hurt(st_rpg *s, float amount)
{
	s->player.stat->pva -= amount;
	if (s->player.stat->pva < 0)
		s->player.stat->pva = 0;
}

int player_is_dead(st_rpg *s)
{
	if (s->player.stat->pva <= 0)
		return (1);
	return (0);
}
