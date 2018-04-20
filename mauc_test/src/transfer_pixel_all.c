/*
** EPITECH PROJECT, 2018
** transfer_pixel_all.c
** File description:
** transfer_pixel_all file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void transfer_pixel_background(files_t *fi, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (fi->map.layer_background[compter] > 0) {
		fi->map.y = height * 32;
		setpixel_to_image_background(fi,
		fi->map.layer_background[compter], c, p);
	}
}

void transfer_pixel_relief(files_t *fi, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (fi->map.layer_relief[compter] == 0)
		fi->map.layer_relief[compter] = 93;
	fi->map.y = height * 32;
	setpixel_to_image_relief(fi, fi->map.layer_relief[compter], c, p);
}

void transfer_pixel_col(files_t *fi, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (fi->map.layer_col[compter] == 0)
		fi->map.layer_col[compter] = 93;
	fi->map.y = height * 32;
	setpixel_to_image_col(fi, fi->map.layer_col[compter], c, p);
}

void transfer_pixel_colid(files_t *fi, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (fi->map.layer_colID[compter] == 0)
		fi->map.layer_colID[compter] = 93;
	fi->map.y = height * 32;
	setpixel_to_image_colid(fi, fi->map.layer_colID[compter], c, p);
}

void transfer_pixel_prof(files_t *fi, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (fi->map.layer_prof[compter] == 0)
		fi->map.layer_prof[compter] = 93;
	fi->map.y = height * 32;
	setpixel_to_image_prof(fi, fi->map.layer_prof[compter], c, p);
}
