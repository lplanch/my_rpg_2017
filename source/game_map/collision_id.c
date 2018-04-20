/*
** EPITECH PROJECT, 2018
** collision_id.c
** File description:
** collision_id.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int case_tp(files_t *fi, int nb_ID)
{
	switch (fi->map.layer_relief[nb_ID]) {
	case 314:
		fi->characters->pos.x = 840;
		fi->characters->pos.y = 4284;
		fi->characters->rect.top = 0;
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
		fi->camera_pos = 1;
		return (1);
	case 286:
		fi->characters->pos.x = 3720;
		fi->characters->pos.y = 2700;
		fi->characters->rect.top = 144;
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
		return (1);
	case 25:
		fi->characters->pos.x = 7218;
		fi->characters->pos.y = 5957;
		fi->characters->rect.top = 144;
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
		fi->camera_pos = 0;
		return (1);
	case 284:
		fi->characters->pos.x = 6591;
		fi->characters->pos.y = 54;
		fi->characters->rect.top = 96;
		sfSprite_setPosition(fi->characters->sprite,
		fi->characters->pos);
		fi->camera_pos = 0;
		return (1);
	default:
		return (0);
		break;
	}
	return (0);
}

int case_id(files_t *fi, int nb_ID)
{
	switch (fi->map.layer_colID[nb_ID]) {
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