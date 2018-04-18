/*
** EPITECH PROJECT, 2018
** transfer_pixel.c
** File description:
** transfer_pixel file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void transfer_pixel(files_t *fi)
{
	int width = 0;
	int height = 0;
	int compter = 0;

	while (height != 100) {
		width = 0;
		draw_loading(fi);
		while (width != 60) {
			transfer_pixel_background(fi, compter, height);
			transfer_pixel_relief(fi, compter, height);
			transfer_pixel_col(fi, compter, height);
			transfer_pixel_colid(fi, compter, height);
			transfer_pixel_prof(fi, compter, height);
			fi->map.x2 += 32;
			width++;
			compter++;
		}
		fi->map.x2 = 0;
		height++;
	}
}
