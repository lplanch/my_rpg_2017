/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_heal(st_rpg *s)
{
	launch_aoe(s->window, s->f.arc.heal);
	sfCircleShape_setPosition(s->f.arc.heal->circle,
	create_vector2f(920 - sfCircleShape_getRadius(s->f.arc.heal->circle),
	540 - sfCircleShape_getRadius(s->f.arc.heal->circle)));
	sfSprite_setPosition(s->f.arc.heal->anim->obj->sprite,
	create_vector2f(920 - s->f.arc.heal->anim->obj->rect.width / 2,
	540 - s->f.arc.heal->anim->obj->rect.height / 2));
}

void archer_leaf(st_rpg *s)
{
	s->f.arc.leaf->count = s->f.arc.leaf->duration;
	s->f.arc.leaf->amount = 10 + s->player.stat->lvl;
	s->player.stat->frc += s->f.arc.leaf->amount;
}

void choose_spell2_archer(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {archer_heal, archer_leaf};

	(list[s->player.tree.spell2])(s);
}
