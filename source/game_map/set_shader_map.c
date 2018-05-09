/*
** EPITECH PROJECT, 2018
** set_shader_map.c
** File description:
** description
*/

#include "my_rpg.h"

void set_shader_map(st_rpg *s)
{
	s->fi->shader = create_shader("shader/black.frag", 0);

}
