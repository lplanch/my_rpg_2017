/*
** EPITECH PROJECT, 2018
** create_weapon_armor.c
** File description:
** file to stock all functions about creating weapon and armor
*/

#include "my.h"
#include "my_rpg.h"

void draw_armor_weapon_slot(st_rpg *rpg)
{
	sfVector2f armor_pos = {rpg->player.obj->pos.x + WIDTH / 4.12,
	rpg->player.obj->pos.y - HEIGHT / 6};
	sfVector2f weapon_pos = {rpg->player.obj->pos.x + WIDTH / 4.12,
	rpg->player.obj->pos.y - HEIGHT / 3};

	if (rpg->inv.armor->sprite == NULL)
		create_item_sprite(rpg, rpg->inv.armor);
	if (rpg->inv.weapon->sprite == NULL)
		create_item_sprite(rpg, rpg->inv.weapon);
	sfSprite_setPosition(rpg->inv.armor->sprite, weapon_pos);
	sfSprite_setPosition(rpg->inv.weapon->sprite, armor_pos);
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.armor->sprite, NULL);
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.weapon->sprite, NULL);
}

void highlight_armor(st_rpg *rpg, item_t *current, int *clicked)
{
	int left = rpg->player.obj->pos.x + WIDTH / 4.12;
	int top = rpg->player.obj->pos.y - HEIGHT / 6;

	sfSprite_setPosition(rpg->inv.highlight, (sfVector2f){left, top});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.highlight, NULL);
	if (sfMouse_isButtonPressed(key_select_item) == sfTrue) {
		rpg->inv.focused = current;
		*clicked = 1;
	}
}

void highlight_weapon(st_rpg *rpg, item_t *current, int *clicked)
{
	int left = rpg->player.obj->pos.x + WIDTH / 4.12;
	int top = rpg->player.obj->pos.y - HEIGHT / 3;

	sfSprite_setPosition(rpg->inv.highlight, (sfVector2f){left, top});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.highlight, NULL);
	if (sfMouse_isButtonPressed(key_select_item) == sfTrue) {
		rpg->inv.focused = current;
		*clicked = 1;
	}
}

void verify_armor_weapon_highlight(st_rpg *rpg, int *clicked)
{
	if (mouse_on_inventory_slot(rpg, rpg->player.obj->pos.x + WIDTH / 4.12,
	rpg->player.obj->pos.y - HEIGHT / 6))
		highlight_armor(rpg, rpg->inv.armor, clicked);
	if (mouse_on_inventory_slot(rpg, rpg->player.obj->pos.x + WIDTH / 4.12,
	rpg->player.obj->pos.y - HEIGHT / 3))
		highlight_weapon(rpg, rpg->inv.weapon, clicked);
}

void create_armor_weapon_slot(st_rpg *rpg)
{
	rpg->inv.armor = create_first_slot();
	rpg->inv.armor->pos = -1;
	rpg->inv.weapon = create_first_slot();
	rpg->inv.weapon->pos = -2;
}
