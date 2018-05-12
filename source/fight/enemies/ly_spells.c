/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

float get_angle_thunder(st_rpg *s)
{
	float mx = s->player.obj->pos.x -
	(s->f.boss.ray->anim->obj->pos.x +
	(s->f.boss.ray->anim->obj->rect.width) / 2);
	float my = s->player.obj->pos.y -
	(s->f.boss.ray->anim->obj->pos.y +
	(s->f.boss.ray->anim->obj->rect.height) / 2);

	if (my <= 0) {
		return (-acos(mx / hypot(mx, my)) * (180 / 3.14159265));
	} else {
		return (acos(mx / hypot(mx, my)) * (180 / 3.14159265));
	}
}

void update_ly_ray(st_rpg *s, float dt)
{
	clocked_animation(s->f.boss.ray->anim);
	if (s->f.boss.ray->anim->li > 1) {
		s->f.boss.ray->anim->li = 0;
		s->f.boss.ray->anim->c = 0;
		s->f.boss.rayrat = get_ratios(get_angle_thunder(s));
	}
	s->f.boss.ray->anim->obj->pos = create_vector2f(s->f.boss.ray->anim->obj
	->pos.x + 350 * dt * s->f.boss.rayrat.x, s->f.boss.ray->anim->obj->pos.y + 350 * dt *
	s->f.boss.rayrat.y);
	sfSprite_setPosition(s->f.boss.ray->anim->obj->sprite,
	s->f.boss.ray->anim->obj->pos);
	sfCircleShape_setPosition(s->f.boss.ray->circle,
	create_vector2f(s->f.boss.ray->anim->obj->pos.x + 350 * dt *
	s->f.boss.rayrat.x - sfCircleShape_getRadius(s->f.boss.ray->circle),
	s->f.boss.ray->anim->obj->pos.x + 350 * dt *
	s->f.boss.rayrat.y - sfCircleShape_getRadius(s->f.boss.ray->circle)));
}

void launch_ly_ray(st_rpg *s)
{
	launch_aoe(s, s->f.boss.ray);
	s->f.boss.ray->anim->obj->pos = create_vector2f(s->f.mob[1]->obj->pos.x
	- s->f.boss.ray->anim->obj->rect.width / 2,
	s->f.mob[1]->obj->pos.y - s->f.boss.ray->anim->obj->rect.height / 2);
	sfSprite_setPosition(s->f.boss.ray->anim->obj->sprite,
	s->f.boss.ray->anim->obj->pos);
	sfCircleShape_setPosition(s->f.boss.ray->circle,
	create_vector2f(s->f.mob[1]->obj->pos.x - sfCircleShape_getRadius(s
	->f.boss.ray->circle),
	s->f.mob[1]->obj->pos.y - sfCircleShape_getRadius(s
	->f.boss.ray->circle)));
}

void launch_ly_spell(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {launch_ly_ray,
		launch_ly_ray};

	(list[s->f.boss.attack_ly])(s);
}
