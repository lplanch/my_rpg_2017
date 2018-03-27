/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_aoe(sfRenderWindow *window, aoe_t *aoe)
{
	if (aoe->shot) {
		sfRenderWindow_drawSprite(window, aoe->anim->obj->sprite, NULL);
		sfRenderWindow_drawCircleShape(window, aoe->circle, NULL);
	}
}

void launch_aoe(sfRenderWindow *window, aoe_t *aoe)
{
	sfCircleShape_setPosition(aoe->circle,
	create_vector2f(sfMouse_getPositionRenderWindow(window).x -
	sfCircleShape_getRadius(aoe->circle),
	sfMouse_getPositionRenderWindow(window).y -
	sfCircleShape_getRadius(aoe->circle)));
	sfClock_restart(aoe->t.clock);
	sfSprite_setPosition(aoe->anim->obj->sprite,
	create_vector2f(sfMouse_getPositionRenderWindow(window).x -
	aoe->anim->obj->rect.width / 2,
	sfMouse_getPositionRenderWindow(window).y -
	aoe->anim->obj->rect.height / 2));
	aoe->anim->obj->rect.left = 0;
	aoe->anim->obj->rect.top = 0;
	aoe->anim->c = 0;
	aoe->anim->l = 0;
	aoe->t.sec = 0.0;
	aoe->shot = 1;
}

void update_aoe(aoe_t *aoe)
{
	clocked_animation(aoe->anim);
	aoe->t.time = sfClock_getElapsedTime(aoe->t.clock);
	aoe->t.sec = aoe->t.time.microseconds / 1000000.0;
	if (aoe->t.sec > aoe->duration && aoe->shot == 1) {
		aoe->shot = 0;
		aoe->t.sec = 0;
		sfClock_restart(aoe->t.clock);
	}
}

aoe_t *create_aoe(sfCircleShape *circle, st_anim *anim, float duration)
{
	aoe_t *aoe = malloc(sizeof(aoe_t));

	aoe->circle = circle;
	aoe->anim = anim;
	aoe->duration = duration;
	aoe->shot = 0;
	aoe->t = create_st_time();
	return (aoe);
}

void destroy_aoe(aoe_t *aoe)
{
	destroy_anim(aoe->anim);
	sfClock_destroy(aoe->t.clock);
	sfCircleShape_destroy(aoe->circle);
}
