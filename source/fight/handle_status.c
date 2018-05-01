/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void handle_lifesteal(st_rpg *s, float amount, effect_t *effect)
{
	if (effect->count > 0)
		heal(s, amount * effect->amount / 100);
}

void handle_status(st_rpg *s, float amount)
{
	if (s->player.cdata.classe == 3)
		handle_lifesteal(s, amount, s->f.war.lifesteal);
}
