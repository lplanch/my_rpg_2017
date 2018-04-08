/*
** EPITECH PROJECT, 2017
** draw_circle.c
** File description:
** draw_circle functions file
*/

#include "../include/my.h"
#include "../include/my_screensaver.h"

void my_draw_line(framebuffer_t *b, int sx, int sy, int lx, int ly, sfColor c)
{
	float cx = lx - sx;
	float cy = ly - sy;
	float ix, iy = 0;
	unsigned int max = 0;

	if (my_abs(cx) > my_abs(cy))
		max = my_abs(cx);
	else
		max = my_abs(cy);
	ix = cx / (float)max;
	iy = cy / (float)max;
	cx = sx;
	cy = sy;
	for (int i = 0; i < max; i++) {
		cx = cx + ix;
		cy = cy + iy;
		my_put_pixel(b, (int)cx, (int)cy, c);
	}
}

void my_draw_octan(framebuffer_t *buffer, int r, int px, int py, sfColor color)
{
	int x = 0;
	int y = r;
	int m = 5 - 4 * r;

	while (x <= y) {
		my_put_pixel(buffer, x + px, y + py, color);
		if (m > 0) {
			y = y - 1;
			m = m - 8 * y;
		}
		x = x + 1;
		m = m + 8 * x + 4;
	}
}

void my_draw_circle(framebuffer_t *buffer, int px, int py, int r, sfColor c)
{
	int x = 0;
	int y = r;
	int m = 5 - 4 * r;

	while (x <= y) {
		my_put_pixel(buffer, x + px, y + py, c);
		my_put_pixel(buffer, y + px, x + py, c);
		my_put_pixel(buffer, -1 * x + px, y + py, c);
		my_put_pixel(buffer, -1 * y + px, x + py, c);
		my_put_pixel(buffer, x + px, -1 * y + py, c);
		my_put_pixel(buffer, y + px, -1 * x + py, c);
		my_put_pixel(buffer, -1 * x + px, -1 * y + py, c);
		my_put_pixel(buffer, -1 * y + px, -1 * x + py, c);
		if (m > 0) {
			y = y - 1;
			m = m - 8 * y;
		}
		x = x + 1;
		m = m + 8 * x + 4;
	}
}

void my_draw_circle_filled(framebuffer_t *b, int px, int py, int r, sfColor c)
{
	for (int i = 1; i <= r; i++)
		my_draw_circle(b, px, py, i, c);
}
