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
	obj->rect.left = 0;
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

void set_pnj_meeting_without_zac(st_rpg *s)
{
	s->fi->pnj[10].pnj->rect =
	set_texturerect_top(s->fi->pnj[10].pnj, 0);
	s->fi->pnj[13].pnj->rect =
	set_texturerect_top(s->fi->pnj[13].pnj, 48);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 96);
	s->fi->pnj[10].pnj->pos = create_vector2f(8192, 4738);
	s->fi->pnj[13].pnj->pos = create_vector2f(8261, 4781);
	s->fi->pnj[3].pnj->pos = create_vector2f(10000, 10000);
	s->player.obj->pos = create_vector2f(8131, 4771);
	sfSprite_setPosition(s->fi->pnj[10].pnj->sprite, s->fi->pnj[10].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[13].pnj->sprite,
	s->fi->pnj[13].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[3].pnj->sprite, s->fi->pnj[3].pnj->pos);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
}

void after_quests(st_rpg *s)
{
	night_scene(s);
	s->fi->pnj[3].pnj->rect.left = 0;
	s->fi->pnj[10].pnj->rect =
	set_texturerect_top(s->fi->pnj[10].pnj, 193);
	s->fi->pnj[3].pnj->rect =
	set_texturerect_top(s->fi->pnj[3].pnj, 193);
	s->fi->pnj[13].pnj->rect =
	set_texturerect_top(s->fi->pnj[13].pnj, 193);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 193);
	s->fi->pnj[10].pnj->pos = create_vector2f(8100, 7000);
	s->fi->pnj[13].pnj->pos = create_vector2f(9230, 7000);
	s->fi->pnj[3].pnj->pos = create_vector2f(7950, 7700);
	s->player.obj->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->fi->pnj[10].pnj->sprite,
	s->fi->pnj[10].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[13].pnj->sprite,
	s->fi->pnj[13].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[3].pnj->sprite, s->fi->pnj[3].pnj->pos);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->return_value = 0;
}

void start_quests_4(st_rpg *s)
{
	set_pnj_meeting_without_zac(s);
	move_camera(s);
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->ponder_music.music);
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_zac_is_missing1", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_zac_is_missing1", "samy");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_zac_is_missing2", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_zac_is_missing3", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_zac_is_missing2", "samy");
	sfMusic_stop(s->fi->ponder_music.music);
	sfMusic_play(s->fi->music.music);
}

void quests_3(st_rpg *s)
{
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->samys_music.music);
	s->fi->quests[3]->status = 2;
	s->fi->pnj[10].pnj->rect = set_texturerect_top(s->fi->pnj[10].pnj, 0);
	dialog_box(s, "samy_night", "samy");
	sfMusic_stop(s->fi->samys_music.music);
	after_quests(s);
	s->fi->pnj[3].pnj->pos = create_vector2f(1000, 1000);
	sfSprite_setPosition(s->fi->pnj[3].pnj->sprite, s->fi->pnj[3].pnj->pos);
	wake_up(s);
	background_with_text(s,
	"ressources/images/scenes/background_zach_missing.png",
	"Zach is missing", "ressources/fonts/quests2.otf");
	start_quests_4(s);
}

void quests_1(st_rpg *s)
{
	s->player.animsens = 1;
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->samys_music.music);
	s->fi->quests[0]->status = 2;
	s->fi->pnj[10].pnj->rect = set_texturerect_top(s->fi->pnj[10].pnj, 0);
	dialog_box(s, "samy_beginning", "samy");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7947, 7374, 13);
	s->player.obj->rect = set_texturerect_top(s->player.obj, 96);
	dialog_box(s, "jade_beginning", "samy");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7888, 7502, 3);
	s->fi->pnj[3].pnj->rect = set_texturerect_top(s->fi->pnj[3].pnj, 144);
	s->player.obj->rect = set_texturerect_top(s->player.obj, 0);
	dialog_box(s, "zac_beginning", "zac");
	sfText_setString(s->fi->text_finish_quests->text,
	"Quest 1 complete!");
	s->fi->var_for_quests = 255;
	sfMusic_stop(s->fi->samys_music.music);
}
