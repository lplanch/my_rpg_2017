/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void loot_enemy(st_rpg *s)
{
	s->player.stat->exp += (rand() % 3) + 3;
}
