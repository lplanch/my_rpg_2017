/*
** EPITECH PROJECT, 2018
** samy_boss.c
** File description:
** samy_boss.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_scene_samy(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.map_samy->sprite, NULL);
	if (s->cut.champ_status == 1)
		sfRenderWindow_drawSprite(s->window,
		s->cut.champ->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->cut.samy_value].pnj->sprite, NULL);
}

void dialog_death_samy(st_rpg *s)
{
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_death_samy2", "Samy");
	s->cut.champ_status = 1;
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "champ_death_samy1", "Champ");
	s->fi->dialog_box_isopen = 1;
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 96);
	dialog_box(s, "samy_death_samy3", "Samy");
	s->cut.champ_status = 0;
	reset_pos_friends(s);
	sfMusic_stop(s->fi->samys_music.music);
	s->fi->pnj[s->cut.samy_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[2].pnj->sprite, s->fi->pnj[s->cut.samy_value].pnj->pos);
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "champ_death_samy2", "Champ");
	move_player_to_zach(s, create_vector2f(s->player.obj->pos.x - 200,
	s->fi->camera.y - 200));
	quit_game_for_dungeon(s);
	s->fi->return_value = launch_dungeon(s, &dungeon3_2);
	//samy_boss(s);
}

void move_all_character_samy(st_rpg *s)
{
	move_player_to_zach(s, create_vector2f(s->player.obj->pos.x - 350,
	s->fi->camera.y - 200));
	s->fi->dialog_box_isopen = 1;
	sfMusic_play(s->fi->samys_music.music);
	dialog_box(s, "samy_death_samy1", "Samy");
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 96);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 150,
	s->fi->camera.y - 90), s->cut.samy_value);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 200,
	s->fi->camera.y - 200), s->cut.samy_value);
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 48);
}

void setup_pos_for_scene_samy(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	s->cut.champ_status = 0;
	sfSprite_scale(s->cut.map_samy->sprite, scale);
	sfSprite_scale(s->cut.champ->sprite, scale2);
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 144);
	s->fi->pnj[s->cut.samy_value].pnj->pos =
	create_vector2f(s->fi->camera.x + 20, s->fi->camera.y + 500);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x + 20, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
}

void death_samy(st_rpg *s)
{
	sfVector2f scale = {2, 2};
	sfVector2f scale2 = {3, 3};

	s->cut.map_samy->pos = create_vector2f(s->fi->camera.x - 740,
	s->fi->camera.y - 560);
	s->cut.champ->pos = create_vector2f(s->fi->camera.x - 115,
	s->fi->camera.y - 240);
	sfSprite_setPosition(s->cut.map_samy->sprite, s->cut.map_samy->pos);
	sfSprite_setPosition(s->cut.champ->sprite, s->cut.champ->pos);
	sfMusic_stop(s->fi->music.music);
	s->fi->samy_status = 1;
	setup_pos_for_scene_samy(s, scale, scale2);
	move_all_character_samy(s);
	dialog_death_samy(s);
	s->fi->samy_status = 0;
	sfMusic_play(s->fi->music.music);
}

void samy_boss(st_rpg *s)
{
	sfVector2f scale = {2, 2};
	sfVector2f scale2 = {3, 3};

	s->cut.map_samy->pos = create_vector2f(s->fi->camera.x - 740,
	s->fi->camera.y - 560);
	s->cut.champ->pos = create_vector2f(s->fi->camera.x - 115,
	s->fi->camera.y - 240);
	sfSprite_setPosition(s->cut.map_samy->sprite, s->cut.map_samy->pos);
	sfSprite_setPosition(s->cut.champ->sprite, s->cut.champ->pos);
	sfMusic_stop(s->fi->music.music);
	s->fi->samy_status = 1;
	setup_pos_for_scene_samy(s, scale, scale2);
	move_all_character_samy(s);
	dialog_death_samy(s);
	s->fi->samy_status = 0;
	sfMusic_play(s->fi->music.music);
}
