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
	fi->nbr_colcircle = 42;
	fi->nbr_colsquare = 204;
	fi->direction = 3;
}

sfVector2f create_vector2f(float x, float y)
{
	sfVector2f square;

	square.x = x;
	square.y = y;
	return (square);
}

void setup_camera(files_t *fi)
{
	fi->view = sfView_create();
	fi->view = sfRenderWindow_getDefaultView(fi->window);
	fi->camera.x = fi->square2.x;
	fi->camera.y = fi->square2.y;
	fi->camera_prec.x = fi->square2.x;
	fi->camera_prec.y = fi->square2.y;
	fi->camera_pos = 0;
	sfView_setCenter(fi->view, fi->camera);
	sfRenderWindow_setView(fi->window, fi->view);
}
