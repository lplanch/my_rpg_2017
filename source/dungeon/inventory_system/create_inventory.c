/*
** EPITECH PROJECT, 2018
** create_inv.c
** File description:
** file to stock all functions about creating inv on screen
*/

#include "my.h"
#include "my_rpg.h"

void create_inventory_screen(ing_inv_t *inv)
{
	inv->texture =
	sfTexture_createFromFile("ressources/inventory.png", NULL);
	inv->sprite = sfSprite_create();
	inv->rect.width = 1500;
	inv->rect.height = 800;
	inv->rect.left = 0;
	inv->rect.top = 0;
	sfSprite_setTextureRect(inv->sprite, inv->rect);
	sfSprite_setTexture(inv->sprite, inv->texture, sfTrue);
}

item_t *create_first_slot(void)
{
	item_t *slot = malloc(sizeof(item_t));

	clear_inventory_slot(slot);
	slot->pos = 0;
	slot->next = NULL;
	return (slot);
}

void create_inventory_var(ing_inv_t *inv)
{
	inv->size = 10;
	inv->money = 0;
	inv->first_slot = create_first_slot();
	for (unsigned int i = 0; i < inv->size; i++)
		add_inventory_slot(inv->first_slot);
	inv->armor = create_first_slot();
	inv->weapon = create_first_slot();
}

void create_ingame_inventory(st_rpg *rpg)
{
	create_inventory_screen(&rpg->inv);
	create_inventory_var(&rpg->inv);
	create_fast_inventory_screen(&rpg->finv);
}
