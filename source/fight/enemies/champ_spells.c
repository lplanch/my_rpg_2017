/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void launch_champ_tentacle(st_rpg *s)
{
	int i = 0;

	launch_aoe(s, s->f.boss.tent[i]);
}

void launch_champ_shadowball(st_rpg *s)
{
	launch_aoe(s, s->f.boss.ball);
}

void launch_champ_well(st_rpg *s)
{
	launch_aoe(s, s->f.boss.well);
	sfCircleShape_setPosition(s->f.boss.well->circle,
	create_vector2f(s->player.obj->pos.x - sfCircleShape_getRadius(s
	->f.boss.well->circle),
	s->player.obj->pos.y - sfCircleShape_getRadius(s
	->f.boss.well->circle)));
	sfSprite_setPosition(s->f.boss.well->anim->obj->sprite,
	create_vector2f(s->player.obj->pos.x - s->f.boss.well->anim->obj
	->rect.width / 2,
	s->player.obj->pos.y - s->f.boss.well->anim->obj->rect.height / 2));
}

void launch_champ_spells(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {launch_champ_well,
	launch_champ_well, launch_champ_well};

	(list[rand() % 3])(s);
}
