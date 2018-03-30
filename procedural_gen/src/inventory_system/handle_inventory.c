/*
** EPITECH PROJECT, 2018
** handle_inventory.c
** File description:
** file to stock all functions about inventory
*/

#include "my.h"
#include "../../include/procedural.h"

void clear_inventory_slot(item_t *slot)
{
	slot->id = 0;
	slot->stacks = 0;
}

void add_inventory_slot(item_t *first_slot)
{
	item_t *conductor = first_slot;

	while ((conductor = conductor->next) != NULL);
	conductor = malloc(sizeof(item_t));
	clear_inventory_slot(conductor);
	conductor->next = NULL;
}

void remove_inventory_slot(item_t *first_slot)
{
	
}

void init_inventory(ingame_t *ingame)
{
	//READ SAVE FILE TO GET ALL INFORMATIONS
	ingame->inventory.size = 10;
	ingame->inventory.money = 100;
	ingame->inventory.first_slot = malloc(sizeof(item_t));
	clear_inventory_slot(ingame->inventory.first_slot);
	ingame->inventory.first_slot->next = NULL;
	ingame->inventory.armor = ingame->inventory.first_slot;
}
