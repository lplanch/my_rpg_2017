/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** collision file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

int collision(files_t *fi)
{
 	float pos_car_x = fi->square2.x - fi->gsquare2.x;
	float pos_car_y = fi->square2.y - fi->gsquare2.y;
	int size_cube = 5 * 32;
	int nextx = pos_car_x / size_cube;
	int nexty = pos_car_y / size_cube;
	int col[5][5] = {{282, 142, 143, 0, 0}, {0, 173, 174, 230, 231}, {0, 204, 205, 261, 262}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

	switch (col[nexty][nextx]) {
		case 282:
		case 204:
		case 205:
		case 261:
		case 262:
			return (1);
			break;
		default:
			return (0);
			break;
	}
	//printf("%s\n", "POSSSSS");
	//printf("X= %i\n", nextx);
	//printf("Y= %i\n", nexty);
}
