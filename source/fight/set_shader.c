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
	destroy_shader(&s->f.shade.power);
	destroy_shader(&s->f.shade.armor);
	destroy_shader(&s->f.shade.endure);
}

void set_shader(st_rpg *s)
{
	s->f.shade.vanish = create_shader("shader/vanish.frag", 0);
	s->f.shade.power = create_shader("shader/power.frag", 0);
	s->f.shade.armor = create_shader("shader/stun.frag", 0);
	s->f.shade.endure = create_shader("shader/endure.frag", 1);
}
