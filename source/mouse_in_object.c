/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** mouse_in_object
*/

#include <SFML/Graphics.h>
#include "game_object.h"

int mouse_in_object(g_object *obj, sfRenderWindow *window)
{
	int mx = sfMouse_getPositionRenderWindow(window).x;
	int my = sfMouse_getPositionRenderWindow(window).y;
	int posx = obj->pos.x;
	int posy = obj->pos.y;
	int width = obj->rect.width;
	int height = obj->rect.height;

	if (mx > posx && mx < posx + width) {
		if (my > posy && my < posy + height) {
			return (1);
		}
	}
	return (0);
}
