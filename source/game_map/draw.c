/*
** EPITECH PROJECT, 2018
** draw.c
** File description:
** draw file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_loading(st_rpg *s)
{
	s->fi->time.tmp = sfClock_getElapsedTime(s->fi->time.clock);
	s->fi->time.seconds = s->fi->time.tmp.microseconds / 20000.0;
	if (s->fi->time.seconds > 0.8) {
		if (s->fi->loading->rect.left == 3762)
			s->fi->loading->rect.left = 0;
		else
			s->fi->loading->rect.left += 99;
		sfSprite_setTextureRect(s->fi->loading->sprite, s->fi->loading->rect);
		sfRenderWindow_clear(s->fi->window, sfBlack);
		sfRenderWindow_drawSprite(s->fi->window, s->fi->loading->sprite,
		NULL);
		sfRenderWindow_display(s->fi->window);
		sfClock_restart(s->fi->time.clock);
	}
}

void draw_pnj(st_rpg *s)
{
	int i = 0;
	int nbpnj = 4;

	while (i != nbpnj) {
		sfRenderWindow_drawSprite(s->fi->window,
		s->fi->pnj[i].pnj->sprite, NULL);
		i++;
	}
}

void draw_all(st_rpg *s)
{
	sfSprite_setTextureRect(s->fi->characters->sprite, s->fi->characters->rect);
	sfSprite_setPosition(s->fi->characters->sprite, s->fi->characters->pos);
	sfRenderWindow_clear(s->fi->window, sfBlack);
	sfRenderWindow_drawSprite(s->fi->window, s->fi->map.sprite, NULL);
	sfRenderWindow_drawSprite(s->fi->window, s->fi->map.sprite5, NULL);
	sfRenderWindow_drawSprite(s->fi->window, s->fi->map.sprite3, NULL);
	sfRenderWindow_drawSprite(s->fi->window, s->fi->map.sprite2, NULL);
	//sfRenderWindow_drawSprite(s->fi->window, s->fi->ID_characters->sprite, NULL)
	sfRenderWindow_drawSprite(s->fi->window, s->fi->characters->sprite, NULL);
	draw_pnj(s);
	sfRenderWindow_drawSprite(s->fi->window, s->fi->map.sprite4, NULL);
}

void draw(st_rpg *s)
{
	draw_all(s);
	sfRenderWindow_display(s->fi->window);
	usleep(1);
}
