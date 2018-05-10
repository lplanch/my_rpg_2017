/*
** EPITECH PROJECT, 2018
** inventory_items_handling.c
** File description:
** handle item in inventory
*/

#include "my.h"
#include "my_rpg.h"

int add_inventory_item(item_t *first_slot, unsigned int id)
{
	item_t *current = first_slot;
	int pos = search_item(first_slot, id);

	if (pos == -1) {
		while (current != NULL && current->id != 1)
			current = current->next;
		if (current == NULL)
			return (0);
		current->id = id;
		if (current->sprite != NULL)
			sfSprite_destroy(current->sprite);
		current->sprite = NULL;
		current->stacks += 1;
	} else {
		while ((signed)current->pos < pos)
			current = current->next;
		current->stacks += 1;
	}
	return (1);
}

void use_inventory_item(st_rpg *rpg, item_t *current)
{
	my_putstr("using item : ");
	my_put_nbr(current->id);
	my_putchar('\n');
}
