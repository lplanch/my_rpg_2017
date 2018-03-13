/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void spriteset_game(files_t *fi)
{
	sfSprite_setTexture(fi->sprite, fi->texture, sfTrue);
	sfSprite_setTexture(fi->ID_sprite, fi->ID_text, sfTrue);
}

void squaresetup_game(files_t *fi)
{
	fi->square.left = 0;
	fi->square.top = 0;
	fi->square.width = 48;
	fi->square.height = 48;
	fi->square2.x = 1200;
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
	setup_camera(fi);
	setup_col(fi);
}
