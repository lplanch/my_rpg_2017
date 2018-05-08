/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void get_ratios_enemies(st_rpg *s)
{

}

void movement_enemies(st_rpg *s, int i)
{
	if (s->f.mob[i]->alive && s->f.mob[i]->cast != 2) {

	}
}

void set_aggro_enemies(st_rpg *s, int i)
{
	sfCircleShape *circle = sfCircleShape_create();

	sfCircleShape_setRadius(circle, 600);
	sfCircleShape_setPosition(circle, (sfVector2f)
	{s->f.mob[i]->obj->pos.x + s->f.mob[i]->obj->rect.width / 2 - 600,
	s->f.mob[i]->obj->pos.y + s->f.mob[i]->obj->rect.height / 2 - 600});
	if (circle_hitbox(circle, s->player.obj))
		s->f.mob[i]->aggro = 1;
}
