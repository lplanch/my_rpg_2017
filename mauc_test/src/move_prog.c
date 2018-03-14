/*
** EPITECH PROJECT, 2018
** move_prog.c
** File description:
** move file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void move_allpts(files_t *fi)
{
	fi->pos[0].x = fi->vect_ID_player.x;
	fi->pos[0].y = fi->vect_ID_player.y;
	fi->pos[1].x = fi->vect_ID_player.x + fi->ID_player.width;
	fi->pos[1].y = fi->vect_ID_player.y;
	fi->pos[2].x = fi->vect_ID_player.x;
	fi->pos[2].y = fi->vect_ID_player.y + fi->ID_player.height;
	fi->pos[3].x = fi->vect_ID_player.x + fi->ID_player.width;
	fi->pos[3].y = fi->vect_ID_player.y + fi->ID_player.height;
	fi->pos[4].x = fi->vect_ID_player.x + (fi->ID_player.width / 2);
	fi->pos[4].y = fi->vect_ID_player.y;
	fi->pos[5].x = fi->vect_ID_player.x + (fi->ID_player.width / 2);
	fi->pos[5].y = fi->vect_ID_player.y + fi->ID_player.height;
}

void move_ID_player(files_t *fi)
{
	fi->ID_player.left = fi->square.left;
	fi->ID_player.top = fi->square.top ;
	fi->ID_player.width = fi->square.width + 10;
	fi->ID_player.height = fi->square.height - 16;
	fi->vect_ID_player.x = fi->square2.x + 14;
	fi->vect_ID_player.y = fi->square2.y + 66;
	move_allpts(fi);
	sfSprite_setTextureRect(fi->ID_sprite, fi->ID_player);
	sfSprite_setPosition(fi->sprite, fi->vect_ID_player);
}

void move(files_t *fi)
{
	fi->square.left += 48;
	if (fi->square.left >= 192)
		fi->square.left = 0;
}

void move_ok(files_t *fi)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		fi->square.top = 144;
		fi->direction = 1;
		move_up(fi);
	} if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		fi->square.top = 0;
		fi->direction = 3;
		move_down(fi);
	} if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		fi->square.top = 96;
		fi->direction = 2;
		move_right(fi);
	} if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		fi->square.top = 48;
		fi->direction = 4;
		move_left(fi);
	}
}