/*
** EPITECH PROJECT, 2018
** draw_inventory.c
** File description:
** file to stock all functions about drawing inventory
*/

#include "my.h"
#include "my_rpg.h"

void draw_inventory_background(st_rpg *rpg)
{
	sfVector2f player_pos = rpg->player.obj->pos;

	player_pos.x -= WIDTH / 5;
	player_pos.y -= HEIGHT / 5;
	sfTexture_updateFromPixels(rpg->inv.btexture,
	rpg->inv.background->pixels, WIDTH / 2.5, HEIGHT / 2.5, 0, 0);
	sfSprite_setPosition(rpg->inv.bsprite, player_pos);
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.bsprite, NULL);
}

void draw_inventory(st_rpg *rpg)
{
	draw_inventory_background(rpg);
}

void verify_inventory(st_rpg *rpg)
{
	if (sfKeyboard_isKeyPressed(key_inv)) {
		draw_inventory(rpg);
	}
}
