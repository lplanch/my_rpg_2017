/*
** EPITECH PROJECT, 2018
** set_shader.c
** File description:
** description
*/

#include "my_rpg.h"

void destroy_dungeon_shader(st_rpg *s)
{
	destroy_shader(&s->f.shade.vanish);
}

void set_shader(st_rpg *s)
{
	s->f.shade.vanish = create_shader("shader/vanish.frag", 0);
}
