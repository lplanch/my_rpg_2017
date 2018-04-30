/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void handle_lifesteal(st_rpg *s, float amount, char *effect)
{
	if (!my_strcmp(effect, "lifesteal"))
		heal(s, amount);
}
