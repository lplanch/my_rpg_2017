/*
** EPITECH PROJECT, 2018
** draw_inventory.c
** File description:
** file to stock all functions about drawing inventory
*/

#include "my.h"
#include "procedural.h"

void draw_inventory_background(gmanager_t *gman)
{
	sfVector2f player_pos = gman->player.pos;

	player_pos.x -= WIDTH / 5;
	player_pos.y -= HEIGHT / 5;
	sfTexture_updateFromPixels(gman->ing->inv.btexture,
	gman->ing->inv.background->pixels, WIDTH / 2.5, HEIGHT / 2.5, 0, 0);
	sfSprite_setPosition(gman->ing->inv.bsprite, player_pos);
	sfRenderWindow_drawSprite(gman->window, gman->ing->inv.bsprite, NULL);
}

void draw_inventory(gmanager_t *gman)
{
	draw_inventory_background(gman);
}

void verify_inventory(gmanager_t *gman)
{
	if (sfKeyboard_isKeyPressed(key_inv)) {
		draw_inventory(gman);
	}
}
