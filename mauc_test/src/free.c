/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** free file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void free_tab(char **tab, int y)
{
	int i = 0;

	while (i != y) {
		free (tab[i]);
		i++;
	}
	free (tab);
}

void free_all(files_t *fi)
{
	free (fi->testmap.layer_background);
	free (fi->testmap.layer_relief);
	free (fi->testmap.layer_colID);
	free (fi->testmap.layer_col);
	free (fi->testmap.layer_prof);
}
