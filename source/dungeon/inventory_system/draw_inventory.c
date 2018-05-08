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

void create_item_sprite(st_rpg *rpg, item_t *current)
{
	sfIntRect current_rect =
	{115 * (current->id % 10), 115 * (current->id / 10), 115, 115};

	current->sprite = sfSprite_create();
	sfSprite_setTexture(current->sprite, rpg->inv.sheet, sfTrue);
	sfSprite_setTextureRect(current->sprite, current_rect);
}

void draw_inventory_items(st_rpg *rpg)
{
	item_t *current = rpg->inv.first_slot;
	float left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 15;
	float top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 15;
	sfVector2f current_pos;

	while (current != NULL) {
		current_pos.x = left_pos + 120 * (current->pos % 9);
		current_pos.y = top_pos + 120 * (current->pos / 9);
		if (current->sprite == NULL)
			create_item_sprite(rpg, current);
		sfSprite_setPosition(current->sprite, current_pos);
		sfRenderWindow_drawSprite(rpg->window, current->sprite, NULL);
		current = current->next;
	}
}

void draw_inventory(st_rpg *rpg)
{
	draw_inventory_background(rpg);
	draw_inventory_items(rpg);
	verify_mouse_inv_events(rpg);
}

void verify_inventory(st_rpg *rpg)
{
	if (sfKeyboard_isKeyPressed(key_inv)) {
		draw_inventory(rpg);
	}
}
