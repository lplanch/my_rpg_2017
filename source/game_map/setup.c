/*
** EPITECH PROJECT, 2018
** setup.c
** s->file description:
** setup s->file for my_rpg
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
	s->fi->loading = create_object("images/loading.png",
	create_vector2f(100, 100),
	create_rect(0, 0, 99, 257), 0);
	s->fi->loading->pos.x = s->fi->characters->pos.x - 60;
	s->fi->loading->pos.y = s->fi->characters->pos.y - 170;
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
}

void characters_setup(st_rpg *s)
{
	s->fi->character = create_object("images/car/story_characters/hero.png",
	create_vector2f(3720, 1800),
	create_rect(0, 144, 48, 48), 0);
	sfSprite_scale(s->fi->character->sprite, create_vector2f(2, 2));
	s->fi->ID_character = create_object("car/rose.jpg",
	create_vector2f(3720, 1800),
	create_rect(144, 0, 48, 48), 0);
	setup_camera(s);
	setup_col(s);
}
