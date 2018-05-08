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
	s->fi->nbr_colsquare = 473;
	s->fi->direction = 3;
}

void setup_camera(st_rpg *s)
{
	s->fi->view = sfView_create();
	s->fi->view = sfView_copy(sfRenderWindow_getDefaultView(s->window));
	s->fi->camera.x = s->player.obj->pos.x;
	s->fi->camera.y = s->player.obj->pos.y;
	s->fi->camera_prec.x = s->player.obj->pos.x;
	s->fi->camera_prec.y = s->player.obj->pos.y;
	s->fi->camera_pos = 0;
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->window, s->fi->view);
}
