/*
** EPITECH PROJECT, 2018
** inv_handle_mouse.c
** File description:
** mouse events in inventory
*/

#include "my.h"
#include "my_rpg.h"

void verify_unfocused_item(st_rpg *rpg, int clicked)
{
	if (sfMouse_isButtonPressed(key_select_item) && clicked == 0) {
		rpg->inv.focused = NULL;
	}
}

void draw_focused_item(st_rpg *rpg)
{
	int left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 7.5;
	int top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 7.5;
	sfVector2f pos;

	if (rpg->inv.focused == NULL)
		return;
	pos.x = left_pos + 120 * (rpg->inv.focused->pos % 9);
	pos.y = top_pos + 120 * (rpg->inv.focused->pos / 9);
	sfSprite_setPosition(rpg->inv.selected, (sfVector2f){pos.x, pos.y});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.selected, NULL);
}

void highlight_item(st_rpg *rpg, item_t *current, int *clicked)
{
	int left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 15.5;
	int top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 15.5;
	sfVector2f pos =
	{left_pos + 120 * (current->pos % 9),
	top_pos + 120 * (current->pos / 9)};

	sfSprite_setPosition(rpg->inv.highlight, (sfVector2f){pos.x, pos.y});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.highlight, NULL);
	if (sfMouse_isButtonPressed(key_select_item) == sfTrue) {
		rpg->inv.focused = current;
		*clicked = 1;
	}
}

void verify_mouse_inv_events(st_rpg *rpg)
{
	item_t *current = rpg->inv.first_slot;
	sfVector2i mouse_pos =
	{sfMouse_getPositionRenderWindow(rpg->window).x + rpg->origin.x,
	sfMouse_getPositionRenderWindow(rpg->window).y + rpg->origin.y};
	sfVector2i current_pos;
	int clicked = 0;

	while (current != NULL) {
		current_pos.x = rpg->player.obj->pos.x -
		WIDTH / 2.5 + 15 + 120 * (current->pos % 9);
		current_pos.y = rpg->player.obj->pos.y -
		HEIGHT / 2.5 + 15 + 120 * (current->pos / 9);
		if (current_pos.x < mouse_pos.x && current_pos.y < mouse_pos.y
			&& mouse_pos.x < current_pos.x + 120 &&
			mouse_pos.y < current_pos.y + 120) {
			highlight_item(rpg, current, &clicked);
		} else
			verify_unfocused_item(rpg, clicked);
		current = current->next;
	}
}
