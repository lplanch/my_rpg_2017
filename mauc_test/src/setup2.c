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

void setup_camera(files_t *fi)
{
	fi->view = sfView_create();
	fi->view = sfRenderWindow_getDefaultView(fi->window);
	fi->camera.x = fi->characters->pos.x;
	fi->camera.y = fi->characters->pos.y;
	fi->camera_prec.x = fi->characters->pos.x;
	fi->camera_prec.y = fi->characters->pos.y;
	fi->camera_pos = 0;
	sfView_setCenter(fi->view, fi->camera);
	sfRenderWindow_setView(fi->window, fi->view);
}

void pnj_setup(files_t *fi)
{
	int i = 0;
	int tot_pnj = 3;
	sfVector2f invers;

	invers.x = 2;
	invers.y = 2;
	get_all_pnj(fi, "dialog_box/pnj/");
}
