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
	fi->square.left = 144;
	fi->square.top = 0;
	fi->square.width = 48;
	fi->square.height = 48;
	fi->square2.x = 3720;
	fi->square2.y = 1800;
	fi->invers.x = 2;
	fi->invers.y = 2;
	fi->speed.x = 0;
	fi->speed.y = 0;
	fi->velocity.x = 0;
	fi->velocity.y = 0;
	fi->maxspeed.x = speed * 50;
	fi->maxspeed.y = speed * 50;
	fi->dialog_box_isopen = 0;
	fi->nb_pnj = 0;
	fi->pnj[0].name = "michel";
	sfSprite_scale(fi->sprite, fi->invers);
	sfSprite_setTextureRect(fi->sprite, fi->square);
	sfSprite_setPosition(fi->sprite, fi->square2);
}

void characters_setup(files_t *fi)
{
	fi->texture =
	sfTexture_createFromFile("car/hero.png", NULL);
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
