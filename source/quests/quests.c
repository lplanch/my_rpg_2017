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
	while (s->fi->character->pos.y != 8070) {
		move_camera(s);
		s->fi->character->pos.y -= 1;
		sfSprite_setPosition(s->fi->character->sprite,
		s->fi->character->pos);
		draw(s);
	}
	s->fi->character->pos = create_vector2f(7950, 8037);
	sfSprite_setPosition(s->fi->character->sprite, s->fi->character->pos);
	s->fi->character->rect =
	set_texturerect_top(s->fi->character, 144);
}

void after_quests(st_rpg *s)
{
	night_scene(s);
	s->fi->pnj[2].pnj->rect =
	set_texturerect_top(s->fi->pnj[2].pnj, 193);
	s->fi->pnj[0].pnj->rect =
	set_texturerect_top(s->fi->pnj[0].pnj, 193);
	s->fi->pnj[3].pnj->rect =
	set_texturerect_top(s->fi->pnj[3].pnj, 193);
	s->fi->character->rect =
	set_texturerect_top(s->fi->character, 193);
	s->fi->pnj[2].pnj->pos = create_vector2f(8100, 7000);
	s->fi->pnj[3].pnj->pos = create_vector2f(9230, 7000);
	s->fi->pnj[0].pnj->pos = create_vector2f(7950, 7700);
	s->fi->character->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->fi->pnj[2].pnj->sprite, s->fi->pnj[2].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[3].pnj->sprite, s->fi->pnj[3].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[0].pnj->sprite, s->fi->pnj[0].pnj->pos);
	sfSprite_setPosition(s->fi->character->sprite, s->fi->character->pos);
	wake_up(s);
	s->fi->return_value = 0;
}

void quests_1(st_rpg *s)
{
	s->fi->quests[0]->status = 2;
	s->fi->pnj[2].pnj->rect = set_texturerect_top(s->fi->pnj[2].pnj, 0);
	dialog_box(s, "samy_beginning");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7947, 7374, 3);
	s->fi->character->rect = set_texturerect_top(s->fi->character, 96);
	dialog_box(s, "jade_beginning");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7888, 7502, 0);
	s->fi->pnj[0].pnj->rect = set_texturerect_top(s->fi->pnj[0].pnj, 144);
	s->fi->character->rect = set_texturerect_top(s->fi->character, 0);
	dialog_box(s, "zac_beginning");
	sfText_setString(s->fi->text_finish_quests->text,
	"Quests 1 complete!");
	s->fi->var_for_quests = 255;
}
