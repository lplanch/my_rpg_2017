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
	slot->sprite = NULL;
	slot->id = 0;
	slot->stacks = 0;
}

void add_inventory_slot(item_t *first_slot)
{
	item_t *conductor = first_slot;
	unsigned int last_pos = first_slot->pos;

	while ((conductor = conductor->next) != NULL)
		last_pos = conductor->pos;
	conductor = malloc(sizeof(item_t));
	clear_inventory_slot(conductor);
	conductor->sprite = NULL;
	conductor->pos = last_pos;
	conductor->next = NULL;
}

void remove_inventory_slot(item_t *first_slot)
{
	item_t *conductor = first_slot;

	while ((conductor = conductor->next->next) != NULL);
	sfSprite_destroy(conductor->next->sprite);
	free(conductor->next);
	conductor->next = NULL;
}
