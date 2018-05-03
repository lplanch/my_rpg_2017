/*
** EPITECH PROJECT, 2018
** collision_id.c
** File description:
** collision_id.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int case_tp(st_rpg *s, int nb_ID)
{
	switch (s->fi->map.layer_relief[nb_ID]) {
	case 314:
		s->fi->character->pos.x = 3707;
		s->fi->character->pos.y = 3492;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 1;
		return (1);
	case 93:
		s->fi->character->pos.x = 3720;
		s->fi->character->pos.y = 2700;
		s->fi->character->rect.top = 144;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		return (1);
	case 25:
		s->fi->character->pos.x = 7246;
		s->fi->character->pos.y = 5552;
		s->fi->character->rect.top = 144;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 26:
		s->fi->character->pos.x = 7191;
		s->fi->character->pos.y = 561;
		s->fi->character->rect.top = 96;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 57:
		s->fi->character->pos.x = 3850;
		s->fi->character->pos.y = 9449;
		s->fi->character->rect.top = 144;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 91:
		s->fi->character->pos.x = 8676;
		s->fi->character->pos.y = 7092;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 121:
		s->fi->character->pos.x = 8676;
		s->fi->character->pos.y = 9107;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 123:
		s->fi->character->pos.x = 7551;
		s->fi->character->pos.y = 9107;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 88:
		s->fi->character->pos.x = 2636;
		s->fi->character->pos.y = 11194;
		s->fi->character->rect.top = 48;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 92:
		s->fi->character->pos.x = 5956;
		s->fi->character->pos.y = 7053;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 120:
		s->fi->character->pos.x = 4981;
		s->fi->character->pos.y = 7053;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 122:
		s->fi->character->pos.x = 4360;
		s->fi->character->pos.y = 7053;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 56:
		s->fi->character->pos.x = 7233;
		s->fi->character->pos.y = 4301;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 87:
		s->fi->character->pos.x = 153;
		s->fi->character->pos.y = 8640;
		s->fi->character->rect.top = 96;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);

	case 119:
		s->fi->character->pos.x = 661;
		s->fi->character->pos.y = 4959;
		s->fi->character->rect.top = 144;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 118:
		s->fi->character->pos.x = 4062;
		s->fi->character->pos.y = 1730;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 150:
		s->fi->character->pos.x = 526;
		s->fi->character->pos.y = 6069;
		s->fi->character->rect.top = 144;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 149:
		s->fi->character->pos.x = 5025;
		s->fi->character->pos.y = 1401;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 151:
		s->fi->character->pos.x = 1615;
		s->fi->character->pos.y = 6229;
		s->fi->character->rect.top = 144;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 152:
		s->fi->character->pos.x = 4395;
		s->fi->character->pos.y = 2512;
		s->fi->character->rect.top = 0;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		s->fi->camera_pos = 0;
		return (1);
	default:
		return (0);
		break;
	}
	return (0);
}

int case_id(st_rpg *s, int nb_ID)
{
	switch (s->fi->map.layer_colID[nb_ID]) {
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 42:
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
	case 50:
	case 51:
	case 63:
	case 64:
	case 65:
	case 66:
	case 67:
	case 68:
	case 73:
	case 74:
	case 75:
	case 76:
	case 77:
	case 78:
	case 79:
	case 80:
	case 81:
	case 82:
	case 156:
	case 157:
	case 158:
	case 159:
	case 168:
	case 169:
	case 170:
	case 171:
	case 173:
	case 174:
	case 175:
	case 176:
	case 177:
	case 178:
	case 187:
	case 188:
	case 189:
	case 190:
	case 199:
	case 200:
	case 201:
	case 202:
	case 204:
	case 205:
	case 206:
	case 207:
	case 208:
	case 209:
		return (1);
		break;
	default:
		return (0);
		break;
	}
}
