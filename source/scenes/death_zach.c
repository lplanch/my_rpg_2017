/*
** EPITECH PROJECT, 2018
** death_zac.c
** File description:
** death_zac.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_scene_zach(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.map->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->cut.zachd->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[10].pnj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[13].pnj->sprite, NULL);
	sfRenderWindow_display(s->window);
}

void move_all_character_zach(st_rpg *s)
{
	move_player_to_zach(s, create_vector2f(s->player.obj->pos.x,
	s->fi->camera.y - 150));
	move_pnj_zach(s, create_vector2f(s->fi->camera.x,
	s->fi->camera.y - 90), 13);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x,
	s->fi->camera.y - 190), 13);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 150,
	s->fi->camera.y - 90), 10);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 149,
	s->fi->camera.y - 190), 10);
	s->fi->pnj[13].pnj->rect =
	set_texturerect_top(s->fi->pnj[10].pnj, 96);
}

void setup_pos_for_scene_zach(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	sfSprite_scale(s->cut.map->sprite, scale);
	sfSprite_scale(s->cut.zachd->sprite, scale2);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
	s->fi->pnj[13].pnj->rect =
	set_texturerect_top(s->fi->pnj[13].pnj, 144);
	s->fi->pnj[10].pnj->rect =
	set_texturerect_top(s->fi->pnj[10].pnj, 144);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->pnj[10].pnj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 500);
	s->fi->pnj[13].pnj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 500);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	sfSprite_setPosition(s->fi->pnj[13].pnj->sprite,
	s->fi->pnj[13].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[10].pnj->sprite,
	s->fi->pnj[10].pnj->pos);
}

void death_zac(st_rpg *s)
{
	int a = 0;
	sfVector2f scale = {2, 2};
	sfVector2f scale2 = {1.4, 1.4};

	s->cut.map =
	create_object("ressources/images/scenes/map_death_of_zach.png",
	create_vector2f(s->fi->camera.x - 540, s->fi->camera.y - 560),
	create_rect(0, 0, 528, 528), 0);
	s->cut.zachd =
	create_object("ressources/images/scenes/zach_is_dead.png",
	create_vector2f(s->fi->camera.x - 50, s->fi->camera.y - 190),
	create_rect(0, 0, 61, 39), 0);
	setup_pos_for_scene_zach(s, scale, scale2);
	move_all_character_zach(s);
	while (!a) {
		draw_scene_zach(s);
	}
}
