/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void setupclock(st_rpg *s)
{
	s->fi->time.clock = sfClock_create();
	s->fi->clock = sfClock_create();
}

void setup_loading(st_rpg *s)
{
	s->fi->loading = create_object("ressources/images/loading.png",
	create_vector2f(100, 100),
	create_rect(0, 0, 99, 257), 0);
	s->fi->loading->pos.x = s->fi->character->pos.x - 60;
	s->fi->loading->pos.y = s->fi->character->pos.y - 170;
	sfSprite_setPosition(s->fi->loading->sprite, s->fi->loading->pos);
	setupclock(s);
}

void setup_variable(st_rpg *s)
{
	s->fi->speed.x = 0;
	s->fi->speed.y = 0;
	s->fi->velocity.x = 0;
	s->fi->velocity.y = 0;
	s->fi->maxspeed.x = speed * 50;
	s->fi->maxspeed.y = speed * 50;
	s->fi->dialog_box_isopen = 0;
	s->fi->nb_pnj = 2;
	s->fi->max_pnj = 4;
	s->fi->choice_cursor = 0;
	s->fi->var_choice = 0;
	s->fi->nb_choice_pre = 0;
	s->fi->loading_timer = 0;
	s->fi->pre_var = 0;
	s->fi->relief = 0;
	s->fi->quests_box.status = 0;
	s->fi->quests_box.nb_quests = 0;
	s->fi->music.music = create_music(50, "audio/music_camp.ogg");
}

void setup_quests_box(st_rpg *s)
{
	s->fi->quests_box.quests_box = create_button("Quests",
	create_object("ressources/images/quests/quests_box1.png",
	create_vector2f(0, 0), create_rect(0, 0, 404, 72), 0),
	sfBlack, 20);
	sfFont_destroy(s->fi->quests_box.quests_box->text->font);
	s->fi->quests_box.quests_box->text->font = sfFont_createFromFile("ressources/fonts/quests.otf");
	sfText_setFont(s->fi->quests_box.quests_box->text->text, s->fi->quests_box.quests_box->text->font);
	s->fi->quests_box.quests_des = create_button("Quests",
	create_object("ressources/images/quests/quests_des.png",
	create_vector2f(0, 0), create_rect(0, 0, 302, 409), 0),
	sfBlack, 40);
	sfFont_destroy(s->fi->quests_box.quests_des->text->font);
	s->fi->quests_box.quests_des->text->font = sfFont_createFromFile("ressources/fonts/quests2.otf");
	sfText_setFont(s->fi->quests_box.quests_des->text->text, s->fi->quests_box.quests_des->text->font);
}

void character_setup(st_rpg *s)
{
	s->fi = malloc(sizeof(*(s->fi)));
	*s->fi = (files_t) {0};
	s->fi->character = create_object("ressources/images/story_characters/hero.png",
	create_vector2f(3720, 1800),
	create_rect(0, 144, 48, 48), 0);
	sfSprite_scale(s->fi->character->sprite, create_vector2f(2, 2));
	s->fi->ID_character = create_object("ressources/images/rose.jpg",
	create_vector2f(3720, 1800),
	create_rect(144, 0, 48, 48), 0);
	setup_camera(s);
	setup_col(s);
	setup_quests_box(s);
}
