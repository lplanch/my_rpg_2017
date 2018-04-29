/*
** EPITECH PROJECT, 2018
** main_proc.c
** File description:
** main_proc file for procedural gen
*/

#include "my.h"
#include "my_rpg.h"

void origin_icons(st_rpg *s)
{
	int x = s->origin.x;
	int y = s->origin.y + 800;

	for (int i = 0; i != 4; i += 1)
		sfSprite_setPosition(s->f.icons[i]->sprite,
		create_vector2f(x + i * 100, y));
}
