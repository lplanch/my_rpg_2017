/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** collision file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

int collision_ID(files_t *fi)
{
	int i = 0;
	int size_cube = 5 * 32;
	int nb_ID = 0;
	int x = fi->pos[i].x / size_cube;
	int y = fi->pos[i].y / size_cube;

	while (i != 6) {
		nb_ID = 5 * ((fi->pos[i].y / size_cube)) + fi->pos[i].x / size_cube;
		switch (fi->testmap.layer_col[nb_ID]) {
			case 173:
			case 174:
			case 204:
			case 205:
				return (1);
				break;
			default:
				break;
		}
		i++;
	}
	return (0);
}

int check_colsquare(files_t *fi, int nbr)
{
	int i = 0;

	while (i != 6) {
		if (fi->pos[i].x > fi->colsquare[nbr].pos.x && fi->pos[i].x < (fi->colsquare[nbr].pos.x + fi->colsquare[nbr].width) && fi->pos[i].y > fi->colsquare[nbr].pos.y &&
		fi->pos[i].y < (fi->colsquare[nbr].pos.y + fi->colsquare[nbr].height))
			return (1);
		else {
			i++;
		}
	}
	return (0);
}

int check_colcircle(files_t *fi, int nbr)
{
 	float distance_pt_center = 0;
	int i = 0;

	while (i != 6) {
		distance_pt_center = sqrt(powf((fi->pos[i].x - fi->colcircle[nbr].center_circle_x), 2) + powf(((fi->pos[i].y) - fi->colcircle[nbr].center_circle_y), 2));
		//printf("%s\n", "OKKKKK");
		//printf("ccx= %f\n", fi->colcircle[nbr].center_circle_x);
		//printf("ccy= %f\n", fi->colcircle[nbr].center_circle_y);
		//printf("d=%f\n\n", distance_pt_center);
		if (distance_pt_center <= fi->colcircle[nbr].rayon_circle) {
			return (1);
		} else
			i++;
	}
	return (0);
}

int collision_prog(files_t *fi)
{
	int nbr = 0;

	while (nbr < fi->nbr_colcircle) {
		if (check_colcircle(fi, nbr) == 1)
			return (1);
		else
			nbr++;
	}
	nbr = 0;
	while (nbr < fi->nbr_colsquare) {
		if (check_colsquare(fi, nbr) == 1)
			return (1);
		else
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
