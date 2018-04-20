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
	s->fi->pos[1].x = s->fi->ID_character->pos.x + s->fi->ID_character->rect.width;
	s->fi->pos[1].y = s->fi->ID_character->pos.y;
	s->fi->pos[2].x = s->fi->ID_character->pos.x - 5;
	s->fi->pos[2].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	s->fi->pos[3].x = s->fi->ID_character->pos.x + s->fi->ID_character->rect.width;
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
	s->fi->ID_character->rect.left = s->fi->character->rect.left;
	s->fi->ID_character->rect.top = s->fi->character->rect.top;
	s->fi->ID_character->rect.width = s->fi->character->rect.width + 10;
	s->fi->ID_character->rect.height = s->fi->character->rect.height - 16;
	s->fi->ID_character->pos.x = s->fi->character->pos.x + 14;
	s->fi->ID_character->pos.y = s->fi->character->pos.y + 66;
	move_allpts(s);
	sfSprite_setTextureRect(s->fi->ID_character->sprite,
	s->fi->ID_character->rect);
	sfSprite_setPosition(s->fi->ID_character->sprite, s->fi->ID_character->pos);
}

void move(st_rpg *s)
{
	s->fi->character->rect.left += 48;
	if (s->fi->character->rect.left >= 288)
		s->fi->character->rect.left = 144;
}

void move_ok(st_rpg *s)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		s->fi->character->rect.top = 144;
		s->fi->direction = 1;
		s->fi->velocity.y = -speed * 3;
	} else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		s->fi->character->rect.top = 0;
		s->fi->direction = 3;
		s->fi->velocity.y = speed * 3;
	} else
		s->fi->velocity.y = 0;
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		s->fi->character->rect.top = 96;
		s->fi->direction = 2;
		s->fi->velocity.x = speed * 3;
	} else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		s->fi->character->rect.top = 48;
		s->fi->direction = 4;
		s->fi->velocity.x = -speed * 3;
	} else
		s->fi->velocity.x = 0;
}
