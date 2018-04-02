/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void setup_variable(files_t *fi)
{
	fi->speed.x = 0;
	fi->speed.y = 0;
	fi->velocity.x = 0;
	fi->velocity.y = 0;
	fi->maxspeed.x = speed * 50;
	fi->maxspeed.y = speed * 50;
	fi->dialog_box_isopen = 0;
	fi->nb_pnj = 2;
}

void characters_setup(files_t *fi)
{
	sfVector2f invers;

	invers.x = 2;
	invers.y = 2;
	fi->characters = create_object("car/hero.png",
	create_vector2f(3720, 1800),
	create_rect(0, 144, 48, 48), 0);
	sfSprite_scale(fi->characters->sprite, invers);
	fi->ID_characters = create_object("car/rose.jpg",
	create_vector2f(3720, 1800),
	create_rect(144, 0, 48, 48), 0);
	setup_camera(fi);
	setup_col(fi);
}
