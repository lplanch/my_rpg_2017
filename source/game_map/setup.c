/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void setupclock(files_t *fi)
{
	fi->time.clock = sfClock_create();
	fi->clock = sfClock_create();
}

void setup_loading(files_t *fi)
{
	fi->loading = create_object("images/loading.png",
	create_vector2f(100, 100),
	create_rect(0, 0, 99, 257), 0);
	fi->loading->pos.x = fi->characters->pos.x - 60;
	fi->loading->pos.y = fi->characters->pos.y - 170;
	sfSprite_setPosition(fi->loading->sprite, fi->loading->pos);
	setupclock(fi);
}

void setup_variable(files_t *fi)
{
	fi->speed.x = 0;
	fi->speed.y = 0;
	fi->velocity.x = 0;
	fi->velocity.y = 0;
	fi->maxspeed.x = speed * 50;
	fi->maxspeed.y = speed * 50;
	fi->dialog_box_isopen = 0;
	fi->nb_pnj = 2;
	fi->max_pnj = 4;
	fi->choice_cursor = 0;
	fi->var_choice = 0;
	fi->nb_choice_pre = 0;
	fi->loading_timer = 0;
	fi->pre_var = 0;
	fi->relief = 0;
}

void characters_setup(st_rpg *s)
{
	s->fi->character = create_object("images/car/story_characters/hero.png",
	create_vector2f(3720, 1800),
	create_rect(0, 144, 48, 48), 0);
	sfSprite_scale(s->fi->character->sprite, create_vector2f(2, 2));
	fi->ID_character = create_object("car/rose.jpg",
	create_vector2f(3720, 1800),
	create_rect(144, 0, 48, 48), 0);
	setup_camera(fi);
	setup_col(fi);
}
