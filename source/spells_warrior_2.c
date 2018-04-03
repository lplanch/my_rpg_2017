/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_stance(st_rpg *s)
{
	launch_aoe(s->window, s->f.war.shield);
	sfCircleShape_setPosition(s->f.war.shield->circle,
	create_vector2f(920 - sfCircleShape_getRadius(s->f.war.shield->circle),
	540 - sfCircleShape_getRadius(s->f.war.shield->circle)));
	sfSprite_setPosition(s->f.war.shield->anim->obj->sprite,
	create_vector2f(920 - s->f.war.shield->anim->obj->rect.width / 2,
	540 - s->f.war.shield->anim->obj->rect.height / 2));
	s->f.cast = 1;
}

void warrior_lifesteal(st_rpg *s)
{

}

void choose_spell2_warrior(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {warrior_stance, warrior_lifesteal};

	(list[s->player.tree.spell2])(s);
}
