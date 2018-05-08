/*
** EPITECH PROJECT, 2018
** move_pnj.c
** File description:
** move_pnj.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

sfIntRect set_texturerect_top(g_object *obj, int top)
{
	obj->rect.top = top;
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	return (obj->rect);
}

void wake_up(st_rpg *s)
{
	s->player.obj->rect.left = 0;
	sfSprite_setTextureRect(s->player.obj->sprite, s->player.obj->rect);
	while (s->player.obj->pos.y != 8070) {
		move_camera(s);
		s->player.obj->pos.y -= 1;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		draw(s);
	}
	s->player.obj->pos = create_vector2f(7950, 8037);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
}

void after_quests(st_rpg *s)
{
	night_scene(s);
	s->fi->pnj[8].pnj->rect =
	set_texturerect_top(s->fi->pnj[8].pnj, 193);
	s->fi->pnj[2].pnj->rect =
	set_texturerect_top(s->fi->pnj[2].pnj, 193);
	s->fi->pnj[10].pnj->rect =
	set_texturerect_top(s->fi->pnj[10].pnj, 193);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 193);
	s->fi->pnj[8].pnj->pos = create_vector2f(8100, 7000);
	s->fi->pnj[10].pnj->pos = create_vector2f(9230, 7000);
	s->fi->pnj[2].pnj->pos = create_vector2f(7950, 7700);
	s->player.obj->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->fi->pnj[8].pnj->sprite, s->fi->pnj[8].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[10].pnj->sprite,
	s->fi->pnj[10].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[2].pnj->sprite, s->fi->pnj[2].pnj->pos);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	wake_up(s);
	s->fi->return_value = 0;
}

void quests_1(st_rpg *s)
{
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->samys_music.music);
	s->fi->quests[0]->status = 2;
	s->fi->pnj[8].pnj->rect = set_texturerect_top(s->fi->pnj[8].pnj, 0);
	dialog_box(s, "samy_beginning");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7947, 7374, 10);
	s->player.obj->rect = set_texturerect_top(s->player.obj, 96);
	dialog_box(s, "jade_beginning");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7888, 7502, 2);
	s->fi->pnj[2].pnj->rect = set_texturerect_top(s->fi->pnj[2].pnj, 144);
	s->player.obj->rect = set_texturerect_top(s->player.obj, 0);
	dialog_box(s, "zac_beginning");
	sfText_setString(s->fi->text_finish_quests->text,
	"Quest 1 complete!");
	s->fi->var_for_quests = 255;
	sfMusic_stop(s->fi->samys_music.music);
}
