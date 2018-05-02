/*
** EPITECH PROJECT, 2018
** check_pos_camera.c
** File description:
** check_pos_camera.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void check_pos_camera_y(st_rpg *s)
{
	if ((s->fi->character->pos.y <= 532 && s->fi->character->pos.y >= 24 &&
		s->fi->character->pos.x >= 136 && s->fi->character->pos.x
		<= 9378) || (s->fi->character->pos.y <= 5970 &&
		s->fi->character->pos.y >= 5597 && s->fi->character->pos.x
		>= 6270 && s->fi->character->pos.x <= 8708))
		s->fi->camera_pos = 3;
	if ((s->fi->character->pos.y >= 2740 && s->fi->character->pos.y
		<= 3167 && s->fi->character->pos.x >= 136 &&
		s->fi->character->pos.x <= 9378) || (s->fi->character->pos.y
		<= 3915 && s->fi->character->pos.y >= 3709 &&
		s->fi->character->pos.x >= 6270 &&
		s->fi->character->pos.x <= 8708))
		s->fi->camera_pos = 3;
	if ((s->fi->character->pos.y >= 3400 && s->fi->character->pos.y
		<= 3900 && s->fi->character->pos.x >= 3526 &&
		s->fi->character->pos.x <= 3900))
		s->fi->camera_pos = 1;
}

void check_pos_camera_x(st_rpg *s)
{
	if ((s->fi->character->pos.x <= 960 && s->fi->character->pos.x >= 136 &&
		s->fi->character->pos.y >= 24 && s->fi->character->pos.y
		<= 3167) || (s->fi->character->pos.x <= 6719 &&
		s->fi->character->pos.x >= 6216 && s->fi->character->pos.y
		>= 3709 && s->fi->character->pos.y <= 5970))
		s->fi->camera_pos = 2;
	if ((s->fi->character->pos.x >= 8634 && s->fi->character->pos.x
		<= 9378 && s->fi->character->pos.y >= 24 &&
		s->fi->character->pos.y <= 3167) || (s->fi->character->pos.x
		<= 8708 && s->fi->character->pos.x >= 7840 &&
		s->fi->character->pos.y >= 3709 && s->fi->character->pos.y
		<= 5970))
		s->fi->camera_pos = 2;
}
