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
	slot->id = 1;
	slot->stacks = 1;
	slot->selected = 0;
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

int search_item(item_t *first_slot, unsigned int id)
{
	item_t *current = first_slot;

	while (current != NULL) {
		if (current->id == id)
			return (current->pos);
		current = current->next;
	}
	return (-1);
}

int add_inventory_item(item_t *first_slot, unsigned int id)
{
	item_t *current;
	int pos = search_item(first_slot, id);

	if (pos == -1) {
		while (current != NULL && current->sprite != NULL)
			current = current->next;
		if (current == NULL)
			return (0);
		current->stacks += 1;
	} else {
		while ((signed)current->pos < pos)
			current = current->next;
		current->stacks += 1;
	}
	return (1);
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
