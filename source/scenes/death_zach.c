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
	s->fi->pnj[11].pnj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[14].pnj->sprite, NULL);
}

void dialog_death_zach(st_rpg *s)
{
	sfEvent event;
	g_object *letter =
	create_object("ressources/images/scenes/letter_death_zach.jpg",
	create_vector2f(s->fi->camera.x, s->fi->camera.y - 960),
	create_rect(0, 0, 531, 761), 0);

	sfSprite_setPosition(letter->sprite, create_vector2f(s->fi->camera.x -
	(letter->rect.width / 2), s->fi->camera.y - (letter->rect.height / 2)));
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_death_zach1", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_death_zach1", "samy");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_death_zach2", "jade");
	while (42) {
		sfRenderWindow_pollEvent(s->window, &event);
		draw_all(s);
		sfRenderWindow_drawSprite(s->window, letter->sprite, NULL);
		sfRenderWindow_display(s->window);
		if (sfKeyboard_isKeyPressed(sfKeyReturn)
		&& event.type == sfEvtKeyPressed)
			break;
	}
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_death_zach2", "samy");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_death_zach3", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_death_zach3", "samy");
	destroy_object(letter);
}

void move_all_character_zach(st_rpg *s)
{
	move_player_to_zach(s, create_vector2f(s->player.obj->pos.x,
	s->fi->camera.y - 150));
	move_pnj_zach(s, create_vector2f(s->fi->camera.x,
	s->fi->camera.y - 90), 14);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x,
	s->fi->camera.y - 190), 14);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 150,
	s->fi->camera.y - 90), 11);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 149,
	s->fi->camera.y - 190), 11);
	s->fi->pnj[14].pnj->rect =
	set_texturerect_top(s->fi->pnj[11].pnj, 96);
}

void setup_pos_for_scene_zach(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	sfSprite_scale(s->cut.map->sprite, scale);
	sfSprite_scale(s->cut.zachd->sprite, scale2);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
	s->fi->pnj[14].pnj->rect =
	set_texturerect_top(s->fi->pnj[14].pnj, 144);
	s->fi->pnj[11].pnj->rect =
	set_texturerect_top(s->fi->pnj[11].pnj, 144);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->pnj[11].pnj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 500);
	s->fi->pnj[14].pnj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 500);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	sfSprite_setPosition(s->fi->pnj[14].pnj->sprite,
	s->fi->pnj[14].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[11].pnj->sprite,
	s->fi->pnj[11].pnj->pos);
}

void death_zac(st_rpg *s)
{
	sfVector2f scale = {2, 2};
	sfVector2f scale2 = {1.4, 1.4};
	sfMusic *music = create_music(s->s_music,
	"ressources/audio/death_zach.ogg");

	sfMusic_stop(s->fi->music.music);
	sfMusic_setLoop(music, 1);
	sfMusic_play(music);
	s->fi->zach_status = 1;
	setup_pos_for_scene_zach(s, scale, scale2);
	move_all_character_zach(s);
	draw(s);
	dialog_death_zach(s);
	s->fi->zach_status = 0;
	reset_pos_friends(s);
	sfMusic_stop(music);
	after_quests(s);
	s->fi->pnj[3].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[3].pnj->sprite, s->fi->pnj[3].pnj->pos);
	sfMusic_destroy(music);
	sfMusic_play(s->fi->music.music);
	s->fi->dream_status = 1;
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "player_dream1", "hero");
	s->fi->dream_status = 0;
	wake_up(s);
}
