/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void setpixel_to_image_relief(files_t *fi, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		p = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_relief, fi->map.x,
			fi->map.y, fi->map.color);
			p++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void setpixel_to_image_prof(files_t *fi, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		p = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_prof, fi->map.x,
			fi->map.y, fi->map.color);
			p++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void setpixel_to_image_colid(files_t *fi, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		p = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_colID, fi->map.x,
			fi->map.y, fi->map.color);
			p++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void setpixel_to_image_col(files_t *fi, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		p = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_col, fi->map.x,
			fi->map.y, fi->map.color);
			p++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void setpixel_to_image_background(files_t *fi, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		p = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_backgound, fi->map.x,
			fi->map.y, fi->map.color);
			p++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}
