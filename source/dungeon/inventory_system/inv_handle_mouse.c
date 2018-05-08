/*
** EPITECH PROJECT, 2018
** inv_handle_mouse.c
** File description:
** mouse events in inventory
*/

#include "my.h"
#include "my_rpg.h"

void highlight_item(st_rpg *rpg, item_t *current)
{
	int left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 15;
	int top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 15;
	sfVector2f pos =
	{left_pos + 120 * (current->pos % 9),
	top_pos + 120 * (current->pos / 9)};

	sfSprite_setPosition(rpg->inv.highlight, (sfVector2f){pos.x, pos.y});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.highlight, NULL);
}

void verify_mouse_inv_events(st_rpg *rpg)
{
	item_t *current = rpg->inv.first_slot;
	sfVector2i mouse_pos =
	{sfMouse_getPositionRenderWindow(rpg->window).x + rpg->origin.x,
	sfMouse_getPositionRenderWindow(rpg->window).y + rpg->origin.y};
	sfVector2i current_pos;
	int left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 15;
	int top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 15;

	while (current != NULL) {
		current_pos.x = left_pos + 120 * (current->pos % 9);
		current_pos.y = top_pos + 120 * (current->pos / 9);
		if (current_pos.x < mouse_pos.x && current_pos.y < mouse_pos.y
			&& mouse_pos.x < current_pos.x + 120 &&
			mouse_pos.y < current_pos.y + 120) {
			highlight_item(rpg, current);
		}
		current = current->next;
	}
}
