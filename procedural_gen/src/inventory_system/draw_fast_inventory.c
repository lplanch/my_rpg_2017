/*
** EPITECH PROJECT, 2018
** draw_fast_inventory.c
** File description:
** file to stock all functions about creating fast inventory
*/

#include "my.h"
#include "procedural.h"

void set_created_position(gmanager_t *gman)
{
	sfVector2f mouse_pos;

	if (gman->ing->finv.created == 0) {
		mouse_pos.x -= WIDTH / 4 + HEIGHT / 16 + 20;
		mouse_pos.y -= HEIGHT / 4 + HEIGHT / 16 + 20;
		mouse_pos.x +=
		sfMouse_getPositionRenderWindow(gman->window).x / 2;
		mouse_pos.y +=
		sfMouse_getPositionRenderWindow(gman->window).y / 2;
		gman->ing->finv.created_pos.x = mouse_pos.x;
		gman->ing->finv.created_pos.y = mouse_pos.y;
	}
	gman->ing->finv.created = 1;
}

void draw_fast_inventory_background(gmanager_t *gman)
{
	sfVector2f pos_screen;

	set_created_position(gman);
	pos_screen = gman->ing->finv.created_pos;
	pos_screen.x += gman->player.pos.x;
	pos_screen.y += gman->player.pos.y;
	sfSprite_setPosition(gman->ing->finv.sprite, pos_screen);
	sfRenderWindow_drawSprite(gman->window, gman->ing->finv.sprite, NULL);
}

void draw_fast_inventory(gmanager_t *gman)
{
	draw_fast_inventory_background(gman);
}

void verify_fast_inventory(gmanager_t *gman)
{
	if (sfMouse_isButtonPressed(key_fast_inv)) {
		draw_fast_inventory(gman);
	} else {
		gman->ing->finv.created = 0;
	}
}
