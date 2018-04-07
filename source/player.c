/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_player(st_rpg *s)
{
	free(s->player.stat);
	destroy_object(s->player.weapon[0]);
	if (check_double_class(s))
		destroy_object(s->player.weapon[1]);
}

int check_double_class(st_rpg *s)
{
	if (s->player.cdata.classe == 1 || s->player.cdata.classe == 2)
		return (1);
	return (0);
}

void display_player(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->player.weapon[0]->sprite, NULL);
	if (check_double_class(s))
		sfRenderWindow_drawSprite(s->window, s->player.weapon[1]
	->sprite, NULL);
}
