/*
** EPITECH PROJECT, 2018
** create_inv.c
** File description:
** file to stock all functions about creating inv on screen
*/

#include "my.h"
#include "../../include/procedural.h"

void fill_inventory_background(framebuffer_t *buffer)
{
	sfColor bla = {50, 50, 57, 180};

	for (int i = 0; i < 5; i++) {
		my_draw_vrect(buffer, (int[2]){0 + i, 0 + i},
		(int[2]){WIDTH / 2.5 - i * 2, HEIGHT / 2.5 - i * 2}, bla);
		my_draw_vrect(buffer,
		(int[2]){WIDTH / 2.5 / 4.5 * 3.5 + i, 0 + i},
		(int[2]){WIDTH / 2.5 / 4.5 - i * 2, HEIGHT / 2.5 - i * 2}, bla);
		my_draw_vrect(buffer,
		(int[2]){WIDTH / 2.5 / 4 * 3 + i, 0 + i},
		(int[2]){WIDTH / 2.5 / 4 - i * 2, HEIGHT / 2.5 - i * 2}, bla);
		my_draw_vrect(buffer, (int[2]){WIDTH / 2.5 / 4.5 * 3.5 + i,
		HEIGHT / 2.5 / 3.5 * 2 + i}, (int[2]){WIDTH / 2.5 / 4.5 - i * 2,
		HEIGHT / 2.5 / 3.5 * 1.5 - i * 2}, bla);
		my_draw_circle(buffer, (int[2]){WIDTH / 2.5 / 4.5 * 4,
		HEIGHT / 2.5 / 3.5 * 2.75}, HEIGHT / 2.5 / 7 + i, bla);
	}
}

void create_inventory_screen(ingame_t *ing)
{
	sfColor sfTGrey = {80, 80, 87, 180};

	ing->inv.background = framebuffer_create(WIDTH / 2.5, HEIGHT / 2.5);
	ing->inv.btexture = sfTexture_create(WIDTH / 2.5, HEIGHT / 2.5);
	ing->inv.bsprite = sfSprite_create();
	sfSprite_setTexture(ing->inv.bsprite, ing->inv.btexture, sfTrue);
	fill_minimap_screen(ing->inv.background, sfTGrey);
	fill_inventory_background(ing->inv.background);
}

item_t *create_first_slot(void)
{
	item_t *slot = malloc(sizeof(item_t));

	clear_inventory_slot(slot);
	slot->pos = 0;
	slot->next = NULL;
	return (slot);
}

void create_inventory_var(ingame_t *ing)
{
	ing->inv.size = 10;
	ing->inv.money = 0;
	ing->inv.first_slot = create_first_slot();
	for (int i = 0; i < ing->inv.size; i++)
		add_inventory_slot(ing->inv.first_slot);
	ing->inv.armor = create_first_slot();
	ing->inv.weapon = create_first_slot();
}

ingame_t *create_ingame_player(void)
{
	ingame_t *ing = malloc(sizeof(ingame_t));

	create_inventory_screen(ing);
	create_inventory_var(ing);
	create_fast_inventory_screen(ing);
	return (ing);
}
