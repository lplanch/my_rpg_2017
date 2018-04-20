/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** collision file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void case_relief(files_t *fi, int nb_ID)
{
	switch (fi->map.layer_relief[nb_ID]) {
	case 435:
		fi->relief = 2;
		break;
	case 436:
		fi->relief = 1;
		break;
	default:
		fi->relief = 0;
		break;
	}
}

int collision_id(files_t *fi)
{
	int i = 0;
	int size_cube = 5 * 32;
	int nb_ID = 0;
	int x = fi->pos[i].x / size_cube;
	int y = fi->pos[i].y / size_cube;

	while (i != 10) {
		nb_ID = 60 * ((fi->pos[i].y / size_cube))
		+ fi->pos[i].x / size_cube;
		if (case_id(fi, nb_ID) == 1) {
			return (1);
		}
		if (case_tp(fi, nb_ID) == 0) {
			fi->camera_pos = 0;
		}
		case_relief(fi, nb_ID);
		i++;
	}
	return (0);
}

int check_colsquare(files_t *fi, int nbr)
{
	int i = 0;

	while (i != 10) {
		if (fi->pos[i].x > fi->colsquare[nbr].pos.x &&
		fi->pos[i].x < (fi->colsquare[nbr].pos.x +
		fi->colsquare[nbr].width) &&
		fi->pos[i].y > fi->colsquare[nbr].pos.y &&
		fi->pos[i].y < (fi->colsquare[nbr].pos.y +
		fi->colsquare[nbr].height)) {
			return (1);
		} else {
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
