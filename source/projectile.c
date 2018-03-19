/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "math.h"
#include "my_rpg.h"
#include "my.h"

float get_angle(sfRenderWindow *window)
{
	float mx = sfMouse_getPositionRenderWindow(window).x - (1920 / 2);
	float my = sfMouse_getPositionRenderWindow(window).y - (1080 / 2);

	if (my <= 0)
		return (-acos(mx / hypot(mx, my)) * (180 / 3.14159265));
	else
		return (acos(mx / hypot(mx, my)) * (180 / 3.14159265));
}

sfVector2f get_ratios(sfRenderWindow *window)
{
	float mx = sfMouse_getPositionRenderWindow(window).x - (1920 / 2);
	float my = sfMouse_getPositionRenderWindow(window).y - (1080 / 2);
	sfVector2f ratio;

	ratio.x = mx / hypot(mx, my);
	ratio.y = my / hypot(mx, my);
	return (ratio);
}

void update_projectile(proj_t *proj)
{
	proj->obj->pos.x += proj->angle.x * proj->obj->speed;
	proj->obj->pos.y += proj->angle.y * proj->obj->speed;
	proj->used -= hypot(proj->angle.x * proj->obj->speed,
		proj->angle.y * proj->obj->speed);
	if (proj->used <= 0)
		proj->shot = 0;
	sfSprite_setPosition(proj->obj->sprite, proj->obj->pos);
}

void launch_projectile(proj_t *proj, sfRenderWindow *window)
{
	proj->angle = get_ratios(window);
	proj->used = proj->range;
	proj->obj->pos.x = 920 - proj->angle.x * proj->obj->rect.width / 2 +
	proj->angle.y * proj->obj->rect.height / 2;
	proj->obj->pos.y = 540 - proj->angle.y * proj->obj->rect.width / 2 -
	proj->angle.x * proj->obj->rect.height / 2;
	sfSprite_setPosition(proj->obj->sprite, proj->obj->pos);
	sfSprite_setRotation(proj->obj->sprite, get_angle(window));
	proj->shot = 1;
}

proj_t *create_projectile(char *path)
{
	int fd = open(path, O_RDONLY);
	proj_t *proj = malloc(sizeof(proj_t));

	proj->obj = create_object(get_next_line(fd), create_vector2f(920,
	540), create_rect(0, 0, 0, 0), 0);
	proj->obj->speed = str_to_int(get_next_line(fd)) / 100;
	proj->range = str_to_int(get_next_line(fd)) / 100;
	proj->used = proj->range;
	proj->dmg = str_to_int(get_next_line(fd)) / 100;
	proj->ratio = str_to_int(get_next_line(fd)) / 100;
	proj->cd = str_to_int(get_next_line(fd)) / 100;
	proj->effect = get_next_line(fd);
	proj->duration = str_to_int(get_next_line(fd)) / 100;
	proj->obj->rect.width = sfTexture_getSize(sfSprite_getTexture(proj
	->obj->sprite)).x;
	proj->obj->rect.height = sfTexture_getSize(sfSprite_getTexture(proj
	->obj->sprite)).y;
	proj->obj->pos.y = 540 - proj->obj->rect.height / 2;
	proj->obj->pos.x = 920 - proj->obj->rect.width / 2;
	sfSprite_setPosition(proj->obj->sprite, proj->obj->pos);
	sfSprite_setPosition(proj->obj->sprite, proj->obj->pos);
	sfSprite_setTextureRect(proj->obj->sprite, proj->obj->rect);
	close(fd);
	proj->angle = create_vector2f(0, 0);
	proj->shot = 0;
/*	printf("width = %d, height = %d\n", proj->obj->rect.width, proj->obj->rect.height);
	printf("speed is = %f\n", proj->obj->speed);
	printf("range is = %f\n", proj->range);
	printf("dmg is = %f\n", proj->dmg);
	printf("ratio is = %f\n", proj->ratio);
	printf("cd is = %f\n", proj->cd);
	printf("width is = %d\n", proj->obj->rect.width);
	printf("height is = %d\n", proj->obj->rect.height);
	printf("effect is = %s\n", proj->effect);
	printf("duration is = %f\n", proj->duration);*/
	return (proj);
}

void destroy_projectile(proj_t *proj)
{
	destroy_object(proj->obj);
	free(proj->effect);
	free(proj);
}
