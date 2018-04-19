/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** free file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void free_tab_withnull(char **tab)
{
	int i = 0;

	while (tab[i] != NULL) {
		free(tab[i]);
		i++;
	}
	free(tab);
}

void free_tab(char **tab, int y)
{
	int i = 0;

	while (i != y) {
		free(tab[i]);
		i++;
	}
	free(tab);
}

void free_all(files_t *fi)
{
	int i = 0;

	while (i != 4) {
		free(fi->map.tab_tileset[i]);
		i++;
	}
	free(fi->map.tab_tileset);
}
