/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void setup_col(st_rpg *s)
{
	s->fi->nbr_colcircle = 42;
	s->fi->nbr_colsquare = 204;
	s->fi->direction = 3;
}

void setup_camera(st_rpg *s)
{
	s->fi->view = sfView_create();
	s->fi->view = sfRenderWindow_getDefaultView(s->fi->window);
	s->fi->camera.x = s->fi->character->pos.x;
	s->fi->camera.y = s->fi->character->pos.y;
	s->fi->camera_prec.x = s->fi->character->pos.x;
	s->fi->camera_prec.y = s->fi->character->pos.y;
	s->fi->camera_pos = 0;
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->fi->window, s->fi->view);
}

void pnj_setup(st_rpg *s)
{
	get_all_pnj(s, "dialog_box/pnj/");
}
