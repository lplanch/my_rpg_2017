/*
** EPITECH PROJECT, 2018
** check_pos_camera.c
** File description:
** check_pos_camera.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void check_pos_camera_y(files_t *fi)
{
	if ((fi->characters->pos.y <= 532 && fi->characters->pos.y >= 24 &&
		fi->characters->pos.x >= 136 && fi->characters->pos.x <= 9378)
		|| (fi->characters->pos.y <= 5970 &&
		fi->characters->pos.y >= 5597 && fi->characters->pos.x >= 6270
		&& fi->characters->pos.x <= 8708))
		fi->camera_pos = 3;
	if ((fi->characters->pos.y >= 2740 && fi->characters->pos.y <= 3167 &&
		fi->characters->pos.x >= 136 && fi->characters->pos.x <= 9378)
		|| (fi->characters->pos.y <= 3915 &&
		fi->characters->pos.y >= 3709 && fi->characters->pos.x >= 6270
		&& fi->characters->pos.x <= 8708))
		fi->camera_pos = 3;
	if ((fi->characters->pos.y >= 4255 && fi->characters->pos.y <= 4617 &&
		fi->characters->pos.x >= 746 && fi->characters->pos.x <= 923))
		fi->camera_pos = 1;
}

void check_pos_camera_x(files_t *fi)
{
	if ((fi->characters->pos.x <= 960 && fi->characters->pos.x >= 136 &&
		fi->characters->pos.y >= 24 && fi->characters->pos.y <= 3167) ||
		(fi->characters->pos.x <= 6719 && fi->characters->pos.x >= 6216
		&& fi->characters->pos.y >= 3709 &&
		fi->characters->pos.y <= 5970))
		fi->camera_pos = 2;
	if ((fi->characters->pos.x >= 8634 && fi->characters->pos.x <= 9378 &&
		fi->characters->pos.y >= 24 && fi->characters->pos.y <= 3167) ||
		(fi->characters->pos.x <= 8708 && fi->characters->pos.x >= 7840
		&& fi->characters->pos.y >= 3709 &&
		fi->characters->pos.y <= 5970))
		fi->camera_pos = 2;
}
