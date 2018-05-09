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
		s->player.obj->pos.x = 3707;
		s->player.obj->pos.y = 3492;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 1;
		return (1);
	case 93:
		s->player.obj->pos.x = 3720;
		s->player.obj->pos.y = 2700;
		s->player.obj->rect.top = 144;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		return (1);
	case 25:
		s->player.obj->pos.x = 7246;
		s->player.obj->pos.y = 5552;
		s->player.obj->rect.top = 144;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 26:
		s->player.obj->pos.x = 7191;
		s->player.obj->pos.y = 561;
		s->player.obj->rect.top = 96;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 57:
		s->player.obj->pos.x = 3850;
		s->player.obj->pos.y = 9449;
		s->player.obj->rect.top = 144;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 91:
		s->player.obj->pos.x = 8792;
		s->player.obj->pos.y = 6969;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 121:
		s->player.obj->pos.x = 8550;
		s->player.obj->pos.y = 9049;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 123:
		s->player.obj->pos.x = 7443;
		s->player.obj->pos.y = 9094;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 88:
		s->player.obj->pos.x = 2636;
		s->player.obj->pos.y = 11194;
		s->player.obj->rect.top = 48;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 92:
		s->player.obj->pos.x = 5847;
		s->player.obj->pos.y = 7020;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 120:
		s->player.obj->pos.x = 5116;
		s->player.obj->pos.y = 7020;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 122:
		s->player.obj->pos.x = 4472;
		s->player.obj->pos.y = 7020;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 56:
		s->player.obj->pos.x = 7233;
		s->player.obj->pos.y = 4301;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 87:
		s->player.obj->pos.x = 153;
		s->player.obj->pos.y = 8640;
		s->player.obj->rect.top = 96;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);

	case 119:
		s->player.obj->pos.x = 661;
		s->player.obj->pos.y = 4959;
		s->player.obj->rect.top = 144;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 118:
		s->player.obj->pos.x = 4062;
		s->player.obj->pos.y = 1730;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 150:
		s->player.obj->pos.x = 526;
		s->player.obj->pos.y = 6069;
		s->player.obj->rect.top = 144;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 149:
		s->player.obj->pos.x = 5025;
		s->player.obj->pos.y = 1401;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 151:
		s->player.obj->pos.x = 1615;
		s->player.obj->pos.y = 6229;
		s->player.obj->rect.top = 144;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		s->fi->camera_pos = 0;
		return (1);
	case 152:
		s->player.obj->pos.x = 4395;
		s->player.obj->pos.y = 2512;
		s->player.obj->rect.top = 0;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
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
