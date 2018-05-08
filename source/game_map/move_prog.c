/*
** EPITECH PROJECT, 2018
** move_prog.c
** File description:
** move file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void move_allpts2(st_rpg *s)
{
	s->fi->pos[6].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 4);
	s->fi->pos[6].y = s->fi->ID_character->pos.y;
	s->fi->pos[7].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2) +
	(s->fi->ID_character->rect.width / 4);
	s->fi->pos[7].y = s->fi->ID_character->pos.y;
	s->fi->pos[8].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 4);
	s->fi->pos[8].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	s->fi->pos[9].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2) +
	(s->fi->ID_character->rect.width / 4);
	s->fi->pos[9].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
}

void move_allpts(st_rpg *s)
{
	s->fi->pos[0].x = s->fi->ID_character->pos.x - 5;
	s->fi->pos[0].y = s->fi->ID_character->pos.y;
	s->fi->pos[1].x = s->fi->ID_character->pos.x +
	s->fi->ID_character->rect.width;
	s->fi->pos[1].y = s->fi->ID_character->pos.y;
	s->fi->pos[2].x = s->fi->ID_character->pos.x - 5;
	s->fi->pos[2].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	s->fi->pos[3].x = s->fi->ID_character->pos.x +
	s->fi->ID_character->rect.width;
	s->fi->pos[3].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	s->fi->pos[4].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2);
	s->fi->pos[4].y = s->fi->ID_character->pos.y;
	s->fi->pos[5].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2);
	s->fi->pos[5].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	move_allpts2(s);
}

void move_id_player(st_rpg *s)
{
	s->fi->ID_character->rect.left = s->player.obj->rect.left;
	s->fi->ID_character->rect.top = s->player.obj->rect.top;
	s->fi->ID_character->rect.width = s->player.obj->rect.width + 10;
	s->fi->ID_character->rect.height = s->player.obj->rect.height - 16;
	s->fi->ID_character->pos.x = s->player.obj->pos.x + 14;
	s->fi->ID_character->pos.y = s->player.obj->pos.y + 66;
	move_allpts(s);
	sfSprite_setTextureRect(s->fi->ID_character->sprite,
	s->fi->ID_character->rect);
	sfSprite_setPosition(s->fi->ID_character->sprite,
	s->fi->ID_character->pos);
}

void move_ok(st_rpg *s)
{
	verify_x_movement(s);
	verify_y_movement(s);
}
