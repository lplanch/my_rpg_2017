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
	dialog_box(s, "final", "Ly");
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

void final_part2(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	setup_pos_for_scene_final(s, scale, scale2);
	dialog_final(s);
	reset_pos_friends(s);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	s->fi->pnj[s->cut.samy_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
}

void final_scene(st_rpg *s)
{
	sfVector2f scale = {1.5, 1.5};
	sfVector2f scale2 = {3, 3};

	s->returnv = 0;
	s->fi->return_value = 0;
	s->fi->num_dungeon = 0;
	s->player.obj->pos = create_vector2f(7950, 7960);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->camera_pos = 0;
	move_camera(s);
	s->cut.map_boss->pos = create_vector2f(s->fi->camera.x - 740,
	s->fi->camera.y - 560);
	s->cut.champ_death->pos = create_vector2f(s->fi->camera.x,
	s->fi->camera.y - 150);
	s->cut.ly_death->pos = create_vector2f(s->fi->camera.x + 50,
	s->fi->camera.y - 150);
	sfSprite_setPosition(s->cut.champ_death->sprite,
	s->cut.champ_death->pos);
	sfSprite_setPosition(s->cut.ly_death->sprite,
	s->cut.ly_death->pos);
	sfSprite_setPosition(s->cut.map_boss->sprite,
	s->cut.map_boss->pos);
	s->fi->final_status = 1;
	final_part2(s, scale, scale2);
}
