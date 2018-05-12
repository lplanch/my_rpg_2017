/*
** EPITECH PROJECT, 2018
** tp_bridge.c
** File description:
** tp_bridge.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_bridge2(st_rpg *s)
{
	s->player.obj->pos.x = 3720;
	s->player.obj->pos.y = 2700;
	s->player.obj->rect.top = 144;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
}

void tp_bridge(st_rpg *s)
{
	s->player.obj->pos.x = 3707;
	s->player.obj->pos.y = 3492;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 1;
}
