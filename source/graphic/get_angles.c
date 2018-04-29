/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

float get_angle(st_rpg *s, sfRenderWindow *window)
{
	float mx = s->player.obj->pos.x - 960 +
	sfMouse_getPositionRenderWindow(window).x;
	float my = s->player.obj->pos.y - 960 +
	sfMouse_getPositionRenderWindow(window).y;

	if (my <= 0) {
		return (-acos(mx / hypot(mx, my)) * (180 / 3.14159265));
	} else {
		return (acos(mx / hypot(mx, my)) * (180 / 3.14159265));
	}
}

sfVector2f get_ratios(float angle)
{
	float val = 3.14159265 / 180;
	sfVector2f ratios;

	ratios.x = cos(angle * val);
	ratios.y = sin(angle * val);
	return (ratios);
}
