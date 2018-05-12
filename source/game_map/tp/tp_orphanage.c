/*
** EPITECH PROJECT, 2018
** tp_orphanage.c
** File description:
** tp_orphanage.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_village(st_rpg *s)
{
	s->player.obj->pos.x = 7191;
	s->player.obj->pos.y = 561;
	s->player.obj->rect.top = 96;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_orphanage(st_rpg *s)
{
	s->player.obj->pos.x = 7246;
	s->player.obj->pos.y = 5552;
	s->player.obj->rect.top = 144;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}
