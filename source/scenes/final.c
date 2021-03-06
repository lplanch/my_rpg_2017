/*
** EPITECH PROJECT, 2018
** samy_boss.c
** File description:
** samy_boss.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_scene_final(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.map_boss->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->cut.ly_death->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->cut.champ_death->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->player.obj->sprite, NULL);
}

void dialog_final(st_rpg *s)
{
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "final1", "Ly");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "final2", "Champ");
	s->fi->final_status = 0;
}

void setup_pos_for_scene_final(st_rpg *s, sfVector2f scale,
sfVector2f scale2)
{
	sfSprite_setScale(s->cut.map_boss->sprite, scale);
	sfSprite_setScale(s->cut.ly_death->sprite, scale2);
	sfSprite_setScale(s->cut.champ_death->sprite, scale2);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x - 100, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
}
