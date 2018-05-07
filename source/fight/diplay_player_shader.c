/*
** EPITECH PROJECT, 2018
** diplay_player_shader.c
** File description:
** description
*/

#include "my_rpg.h"

void display_warrior_shad(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
}

void display_gunner_shad(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
}

void display_archer_shad(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
}

void display_rogue_shad(st_rpg *s)
{
	if (s->f.rog.vanish > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, &s->f.shade.vanish.state);
	} else {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, NULL);
	}
}

void display_player_shade(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {display_archer_shad, display_gunner_shad,
		display_rogue_shad, display_warrior_shad};

	(list[s->player.cdata.classe])(s);
}
