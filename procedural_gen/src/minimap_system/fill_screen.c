/*
** EPITECH PROJECT, 2017
** fill_screen.c
** File description:
** fill the screen with one color
*/

#include "my.h"
#include "../../include/procedural.h"

void my_fill_screen(framebuffer_t *buffer, sfColor color)
{
	for (int y = 0; y < buffer->height; y++) {
		for (int x = 0; x < buffer->width; x++) {
			my_put_pixel(buffer, x, y, color);
		}
	}
}

void fill_minimap_screen(framebuffer_t *buffer, sfColor color)
{
	color.a = 128;
	for (int y = 0; y < buffer->height; y++) {
		for (int x = 0; x < buffer->width; x++) {
			my_put_pixel(buffer, x, y, color);
		}
	}
}
