/*
** EPITECH PROJECT, 2018
** samy_boss.c
** File description:
** samy_boss.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_begin(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.begin->sprite, NULL);
}

void dialog_begin(st_rpg *s)
{
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "begin", " ");
	s->fi->begin_status = 1;
	s->player.obj->pos = create_vector2f(7934, 4497);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
}

void begin_part2(st_rpg *s)
{
	dialog_begin(s);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	s->fi->pnj[s->cut.samy_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
}

void begin_scene(st_rpg *s)
{
	s->returnv = 0;
	s->fi->return_value = 0;
	s->fi->num_dungeon = 0;
	s->player.obj->pos = create_vector2f(7950, 7960);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->camera_pos = 0;
	move_camera(s);
	s->cut.begin->pos = create_vector2f(s->fi->camera.x - 970,
	s->fi->camera.y - 560);
	sfSprite_setPosition(s->cut.begin->sprite,
	s->cut.begin->pos);
	s->fi->begin_status = 2;
	begin_part2(s);
}
