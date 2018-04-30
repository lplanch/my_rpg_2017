/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_cursor_pos_pause(st_rpg *s)
{
	s->pausm.cursor->pos.y = s->pausm.button[s->pausm.option]
	->obj->pos.y + 10;
	sfSprite_setPosition(s->pausm.cursor->sprite,
	s->pausm.cursor->pos);
}

void set_colors_pause(st_rpg *s)
{
	for (int i = 0; i != 5; i += 1)
		sfText_setColor(s->pausm.button[i]
		->text->text, sfWhite);
	sfText_setColor(s->pausm.button[s->pausm.option]->text->text, sfYellow);
}
