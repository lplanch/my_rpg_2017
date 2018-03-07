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
	sfSprite_setTexture(fi->gsprite, fi->gtexture, sfTrue);
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
	fi->gsquare.left = 0;
	fi->gsquare.top = 0;
	fi->gsquare.width = 6000;
	fi->gsquare.height = 4000;
	fi->gsquare2.x = 0;
	fi->gsquare2.y = 0;
	fi->invers2.x = 5;
	fi->invers2.y = 5;
	sfSprite_scale(fi->sprite, fi->invers);
	sfSprite_scale(fi->gsprite, fi->invers2);
	sfSprite_setTextureRect(fi->sprite, fi->square);
	sfSprite_setPosition(fi->sprite, fi->square2);
	sfSprite_setTextureRect(fi->gsprite, fi->gsquare);
	sfSprite_setPosition(fi->gsprite, fi->gsquare2);
}

void characters_setup(files_t *fi)
{
	fi->texture =
	sfTexture_createFromFile("car/car9.png", NULL);
	fi->sprite = sfSprite_create();
	fi->gtexture =
	sfTexture_createFromFile("TestMap/test_col.png", NULL);
	fi->gsprite = sfSprite_create();
	squaresetup_game(fi);
	spriteset_game(fi);
	sfSprite_setTextureRect(fi->sprite, fi->square);
	sfSprite_setTextureRect(fi->gsprite, fi->gsquare);
}
