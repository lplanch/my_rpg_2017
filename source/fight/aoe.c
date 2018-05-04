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

void launch_aoe(st_rpg *s, aoe_t *aoe)
{
	sfCircleShape_setPosition(aoe->circle,
	create_vector2f(s->origin.x +
	sfMouse_getPositionRenderWindow(s->window).x -
	sfCircleShape_getRadius(aoe->circle), s->origin.y +
	sfMouse_getPositionRenderWindow(s->window).y -
	sfCircleShape_getRadius(aoe->circle)));
	sfSprite_setPosition(aoe->anim->obj->sprite,
	create_vector2f(s->origin.x +
	sfMouse_getPositionRenderWindow(s->window).x -
	aoe->anim->obj->rect.width / 2, s->origin.y +
	sfMouse_getPositionRenderWindow(s->window).y -
	aoe->anim->obj->rect.height / 2));
	aoe->anim->obj->rect.left = 0;
	aoe->anim->obj->rect.top = 0;
	aoe->anim->c = 0;
	aoe->anim->li = 0;
	aoe->shot = 1;
	aoe->count = 0;
	sfClock_restart(aoe->anim->t.clock);
}

void proc_aoe(st_rpg *s, aoe_t *aoe)
{
	if (aoe->shot)
		aoe->count += 0.1;
	if (aoe->count >= aoe->duration) {
		aoe->shot = 0;
		s->f.cast = 0;
		aoe->count = 0;
	}
	for (int i = 0; i != 10; i += 1) {
		if (aoe->shot && (circle_hitbox(aoe->circle, s->f.mob[i]->obj)
		|| (circle_hitbox(aoe->circle, s->player.weapon[0]) &&
		!my_strcmp(aoe->effect, "heal")))) {
			if (!my_strcmp(aoe->effect, "heal"))
				heal(s, aoe->dmg);
			if (!my_strcmp(aoe->effect, "damage"))
				apply_aoe(s, aoe, s->f.mob[i]);
		}
	}
}

aoe_t *create_aoe_from_file(char *path)
{
	aoe_t *aoe = malloc(sizeof(aoe_t));
	int fd = open(path, O_RDONLY);
	sfColor color = {str_to_int(get_next_line(fd)),
		str_to_int(get_next_line(fd)), str_to_int(get_next_line(fd)),
		str_to_int(get_next_line(fd))};

	aoe->circle = create_circle(str_to_int(get_next_line(fd)),
	str_to_int(get_next_line(fd)), color);
	aoe->anim = create_anim(create_object(get_next_line(fd),
	create_vector2f(0, 0), create_rect(0, 0, 0, 0), 0),
	create_vector2i(str_to_int(get_next_line(fd)),
	str_to_int(get_next_line(fd))), str_to_int(get_next_line(fd)));
	aoe->anim->speed = aoe->anim->speed / 100;
	aoe->anim->width = sfTexture_getSize(sfSprite_getTexture(aoe->anim->obj
	->sprite)).x / aoe->anim->hor;
	aoe->anim->height = sfTexture_getSize(sfSprite_getTexture(aoe->anim->obj
	->sprite)).y / aoe->anim->ver;
	aoe->anim->obj->rect.width = aoe->anim->width;
	aoe->anim->obj->rect.height = aoe->anim->height;
	aoe->shot = 0;
	aoe->count = 0;
	aoe->effect = get_next_line(fd);
	aoe->dmg = str_to_int(get_next_line(fd));
	aoe->dmgratio = str_to_int(get_next_line(fd));
	aoe->duration = str_to_int(get_next_line(fd)) / 100;
	close(fd);
	return (aoe);
}

aoe_t *create_aoe(sfCircleShape *circle, st_anim *anim, float duration)
{
	aoe_t *aoe = malloc(sizeof(aoe_t));

	aoe->circle = circle;
	aoe->anim = anim;
	aoe->duration = duration;
	aoe->shot = 0;
	aoe->dmg = 0;
	aoe->dmgratio = 0;
	return (aoe);
}

void destroy_aoe(aoe_t *aoe)
{
	destroy_anim(aoe->anim);
	sfCircleShape_destroy(aoe->circle);
}
