/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_ly_ray(st_rpg *s)
{
	clocked_animation(s->f.boss.ray->anim);
	if (s->f.boss.ray->anim->li > 1) {
		s->f.boss.ray->anim->li = 0;
		s->f.boss.ray->anim->c = 0;
	}
}

void launch_ly_ray(st_rpg *s)
{
	launch_aoe(s, s->f.boss.ray);
	sfCircleShape_setPosition(s->f.boss.ray->circle,
	create_vector2f(s->player.obj->pos.x - sfCircleShape_getRadius(s
	->f.boss.ray->circle),
	s->player.obj->pos.y - sfCircleShape_getRadius(s
	->f.boss.ray->circle)));
	sfSprite_setPosition(s->f.boss.ray->anim->obj->sprite,
	create_vector2f(s->player.obj->pos.x - s->f.boss.ray->anim->obj
	->rect.width / 2,
	s->player.obj->pos.y - s->f.boss.ray->anim->obj->rect.height / 2));
}

void launch_ly_spell(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {launch_ly_ray,
		launch_ly_ray};

	(list[s->f.boss.attack_ly])(s);
}
