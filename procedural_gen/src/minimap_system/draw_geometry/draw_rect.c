/*
** EPITECH PROJECT, 2017
** my_draw_rect.c
** File description:
** draw a rect on the screen
*/

#include "my.h"
#include "../../../include/procedural.h"

void my_draw_rect(framebuffer_t *buff, int pos[2], int size[2], sfColor color)
{
	int cx = 0;
	int cy = 0;

	while (cy != size[1]) {
		my_put_pixel(buff, pos[0] + cx, pos[1] + cy, color);
		if (cx == size[0]) {
			cx = 0;
			cy = cy + 1;
		} else {
			cx = cx + 1;
		}
	}
}
