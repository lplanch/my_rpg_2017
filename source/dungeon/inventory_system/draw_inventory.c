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

	player_pos.x -= WIDTH / 2.5;
	player_pos.y -= HEIGHT / 2.5;
	sfSprite_setPosition(rpg->inv.sprite, player_pos);
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.sprite, NULL);
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
