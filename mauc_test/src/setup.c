/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void setup_col(files_t *fi)
{
	fi->nbr_colcircle = 1;
	fi->colcircle[0].center_circle_x = 127.8 * 5;
	fi->colcircle[0].center_circle_y = 83.8 * 5;
	fi->colcircle[0].rayon_circle = 10 * 5;
}

sfVector2f create_vector2f(float x, float y)
{
	sfVector2f square;

	square.x = x;
	square.y = y;
	return (square);
}

void spriteset_game(files_t *fi)
{
	sfSprite_setTexture(fi->sprite, fi->texture, sfTrue);
	sfSprite_setTexture(fi->ID_sprite, fi->ID_text, sfTrue);
}

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

void squaresetup_game(files_t *fi)
{
	fi->square.left = 0;
	fi->square.top = 0;
	fi->square.width = 48;
	fi->square.height = 48;
	fi->square2.x = 800;
	fi->square2.y = 500;
	fi->invers.x = 2;
	fi->invers.y = 2;
	sfSprite_scale(fi->sprite, fi->invers);
	sfSprite_setTextureRect(fi->sprite, fi->square);
	sfSprite_setPosition(fi->sprite, fi->square2);
}

void characters_setup(files_t *fi)
{
	fi->texture =
	sfTexture_createFromFile("car/car9.png", NULL);
	fi->sprite = sfSprite_create();
	fi->ID_text =
	sfTexture_createFromFile("rose.jpg", NULL);
	fi->ID_sprite = sfSprite_create();
	squaresetup_game(fi);
	spriteset_game(fi);
	sfSprite_setTextureRect(fi->sprite, fi->square);
	setup_col(fi);
}
