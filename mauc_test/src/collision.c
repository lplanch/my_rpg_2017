/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** collision file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

int case_ID(files_t *fi, int nb_ID)
{
	printf("%i\n", fi->testmap.layer_colID[nb_ID]);
	switch (fi->testmap.layer_colID[nb_ID]) {
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 42:
		case 43:
		case 44:
		case 45:
		case 46:
		case 47:
		case 48:
		case 49:
		case 50:
		case 51:
		case 63:
		case 64:
		case 65:
		case 66:
		case 67:
		case 68:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
		case 80:
		case 81:
		case 82:
		case 156:
		case 157:
		case 158:
		case 159:
		case 168:
		case 169:
		case 170:
		case 171:
		case 173:
		case 174:
		case 175:
		case 176:
		case 177:
		case 178:
		case 187:
		case 188:
		case 189:
		case 190:
		case 199:
		case 200:
		case 201:
		case 202:
		case 204:
		case 205:
		case 206:
		case 207:
		case 208:
		case 209:
			return (1);
			break;
		default:
			return (0);
			break;
	}
}

int collision_ID(files_t *fi)
{
	int i = 0;
	int size_cube = 5 * 32;
	int nb_ID = 0;
	int x = fi->pos[i].x / size_cube;
	int y = fi->pos[i].y / size_cube;

	while (i != 10) {
		nb_ID = 60 * ((fi->pos[i].y / size_cube)) + fi->pos[i].x / size_cube;
		if (case_ID(fi, nb_ID) == 1)
			return (1);
		i++;
	}
	return (0);
}

int check_colsquare(files_t *fi, int nbr)
{
	int i = 0;

	while (i != 10) {
		if (fi->pos[i].x > fi->colsquare[nbr].pos.x &&
		fi->pos[i].x < (fi->colsquare[nbr].pos.x + fi->colsquare[nbr].width) &&
		fi->pos[i].y > fi->colsquare[nbr].pos.y &&
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

	while (i != 10) {
		distance_pt_center = sqrt(powf((fi->pos[i].x
		- fi->colcircle[nbr].center_circle_x), 2) + powf(((fi->pos[i].y)
		- fi->colcircle[nbr].center_circle_y), 2));
		if (distance_pt_center <= fi->colcircle[nbr].rayon_circle) {
			return (1);
		} else
			i++;
	}
	return (0);
}
