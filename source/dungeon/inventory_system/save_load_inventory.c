/*
** EPITECH PROJECT, 2018
** save_load_inventory.c
** File description:
** file to stock all functions about saving and loading inventory
*/

#include "my.h"
#include "my_rpg.h"

void load_item_inventory(st_rpg *rpg, int id, int stacks)
{
	item_t *current = rpg->inv.first_slot;

	if (current == NULL) {
		rpg->inv.first_slot = create_first_slot();
		rpg->inv.first_slot->stacks = stacks;
		rpg->inv.first_slot->id = id;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = create_first_slot();
	current->next->pos = current->pos + 1;
	current->next->stacks = stacks;
	current->next->id = id;
}

void load_inventory(st_rpg *rpg)
{
	char *str;
	char *path = get_save_path(rpg);
	char *pathname = my_strcat(path, "inventory");
	int fd = open(pathname, O_RDONLY);
	int spac_pos;

	rpg->inv.first_slot = NULL;
	if (fd < 0)
		return;
	destroy_inventory_items(rpg);
	while ((str = get_next_line(fd)) != NULL) {
		spac_pos = my_str_chrpos(str, ',');
		str[spac_pos] = '\0';
		load_item_inventory(rpg, str_to_int(str),
		str_to_int(&str[spac_pos + 1]));
		free(str);
	}
	close(fd);
	free(path);
	free(pathname);
}

void free_save_inv(char *id, char *nbr, char *temp, char *line)
{
	free(id);
	free(nbr);
	free(temp);
	free(line);
}

void save_current_inventory(st_rpg *rpg)
{
	char *id;
	char *nbr;
	char *temp;
	char *line;
	char *path = get_save_path(rpg);
	char *pathname = my_strcat(path, "inventory");
	int fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
	item_t *current = rpg->inv.first_slot;

	while (current != NULL) {
		id = int_to_str(current->id);
		nbr = int_to_str(current->stacks);
		temp = my_strcat(id, ",");
		line = my_strcat(temp, nbr);
		write(fd, line, my_strlen(line));
		write(fd, "\n", 1);
		current = current->next;
		free_save_inv(id, nbr, temp, line);
	}
	close(fd);
	free(path);
	free(pathname);
}
