/*
** EPITECH PROJECT, 2018
** move_prog.c
** File description:
** move file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void move_allpts2(files_t *fi)
{
	fi->pos[6].x = fi->ID_characters->pos.x +
	(fi->ID_characters->rect.width / 4);
	fi->pos[6].y = fi->ID_characters->pos.y;
	fi->pos[7].x = fi->ID_characters->pos.x +
	(fi->ID_characters->rect.width / 2) +
	(fi->ID_characters->rect.width / 4);
	fi->pos[7].y = fi->ID_characters->pos.y;
	fi->pos[8].x = fi->ID_characters->pos.x +
	(fi->ID_characters->rect.width / 4);
	fi->pos[8].y = fi->ID_characters->pos.y +
	fi->ID_characters->rect.height;
	fi->pos[9].x = fi->ID_characters->pos.x +
	(fi->ID_characters->rect.width / 2) +
	(fi->ID_characters->rect.width / 4);
	fi->pos[9].y = fi->ID_characters->pos.y +
	fi->ID_characters->rect.height;
}

void move_allpts(files_t *fi)
{
	fi->pos[0].x = fi->ID_characters->pos.x - 5;
	fi->pos[0].y = fi->ID_characters->pos.y;
	fi->pos[1].x = fi->ID_characters->pos.x + fi->ID_characters->rect.width;
	fi->pos[1].y = fi->ID_characters->pos.y;
	fi->pos[2].x = fi->ID_characters->pos.x - 5;
	fi->pos[2].y = fi->ID_characters->pos.y +
	fi->ID_characters->rect.height;
	fi->pos[3].x = fi->ID_characters->pos.x + fi->ID_characters->rect.width;
	fi->pos[3].y = fi->ID_characters->pos.y +
	fi->ID_characters->rect.height;
	fi->pos[4].x = fi->ID_characters->pos.x +
	(fi->ID_characters->rect.width / 2);
	fi->pos[4].y = fi->ID_characters->pos.y;
	fi->pos[5].x = fi->ID_characters->pos.x +
	(fi->ID_characters->rect.width / 2);
	fi->pos[5].y = fi->ID_characters->pos.y +
	fi->ID_characters->rect.height;
	move_allpts2(fi);
}

void move_id_player(files_t *fi)
{
	fi->ID_characters->rect.left = fi->characters->rect.left;
	fi->ID_characters->rect.top = fi->characters->rect.top;
	fi->ID_characters->rect.width = fi->characters->rect.width + 10;
	fi->ID_characters->rect.height = fi->characters->rect.height - 16;
	fi->ID_characters->pos.x = fi->characters->pos.x + 14;
	fi->ID_characters->pos.y = fi->characters->pos.y + 66;
	move_allpts(fi);
	sfSprite_setTextureRect(fi->ID_characters->sprite,
	fi->ID_characters->rect);
	sfSprite_setPosition(fi->ID_characters->sprite, fi->ID_characters->pos);
}

void move(files_t *fi)
{
	fi->characters->rect.left += 48;
	if (fi->characters->rect.left >= 288)
		fi->characters->rect.left = 144;
}

void move_ok(files_t *fi)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		fi->characters->rect.top = 144;
		fi->direction = 1;
		fi->velocity.y = -speed * 3;
	} else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		fi->characters->rect.top = 0;
		fi->direction = 3;
		fi->velocity.y = speed * 3;
	} else
		fi->velocity.y = 0;
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		fi->characters->rect.top = 96;
		fi->direction = 2;
		fi->velocity.x = speed * 3;
	} else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		fi->characters->rect.top = 48;
		fi->direction = 4;
		fi->velocity.x = -speed * 3;
	} else
		fi->velocity.x = 0;
}
