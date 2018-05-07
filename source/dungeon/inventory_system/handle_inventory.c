/*
** EPITECH PROJECT, 2018
** handle_inventory.c
** File description:
** file to stock all functions about inventory
*/

#include "my.h"
#include "my_rpg.h"

void clear_inventory_slot(item_t *slot)
{
	slot->id = 0;
	slot->stacks = 0;
	slot->sprite = NULL;
}

void add_inventory_slot(item_t *first_slot)
{
	item_t *conductor = first_slot;

	while (conductor->next != NULL)
		conductor = conductor->next;
	conductor->next = malloc(sizeof(item_t));
	clear_inventory_slot(conductor->next);
	conductor->next->pos = conductor->pos + 1;
	conductor->next->next = NULL;
}

void add_inventory_item(item_t *first_slot, unsigned int id)
{
	
}

void remove_inventory_slot(item_t *first_slot)
{
	item_t *conductor = first_slot;

	while ((conductor = conductor->next->next) != NULL);
	if (conductor->next->sprite != NULL)
		sfSprite_destroy(conductor->next->sprite);
	free(conductor->next);
	conductor->next = NULL;
}
