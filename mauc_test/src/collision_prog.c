/*
** EPITECH PROJECT, 2018
** collision_prog.c
** File description:
** collision_prog.c file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

int collision_prog(files_t *fi)
{
	int nbr = 0;

	while (nbr < fi->nbr_colcircle) {
		if (check_colcircle(fi, nbr) == 1) {
			return (1);
		} else
			nbr++;
	}
	nbr = 0;
	while (nbr < fi->nbr_colsquare) {
		if (check_colsquare(fi, nbr) == 1) {
			return (1);
		} else
			nbr++;
	}
	return (0);
}

int collision(files_t *fi)
{
	if (collision_ID(fi) == 1)
		return (1);
	else
		 return (collision_prog(fi));
}
