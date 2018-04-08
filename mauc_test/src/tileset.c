/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void ok5(files_t *fi, int col, int c, int l)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		l = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_relief, fi->map.x,
			fi->map.y, fi->map.color);
			l++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void ok4(files_t *fi, int col, int c, int l)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		l = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_prof, fi->map.x,
			fi->map.y, fi->map.color);
			l++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void ok3(files_t *fi, int col, int c, int l)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		l = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_colID, fi->map.x,
			fi->map.y, fi->map.color);
			l++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void ok2(files_t *fi, int col, int c, int l)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		l = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_col, fi->map.x,
			fi->map.y, fi->map.color);
			l++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void ok(files_t *fi, int col, int c, int l)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		l = 0;
		fi->map.x = fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->map.color = sfImage_getPixel(fi->map.image, x, y);
			sfImage_setPixel(fi->map.map_backgound, fi->map.x,
			fi->map.y, fi->map.color);
			l++;
			x++;
			fi->map.x++;
		}
		fi->map.y++;
		y++;
		c++;
	}
}

void set_background(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture = sfTexture_createFromImage(fi->map.map_backgound, NULL);
	fi->map.sprite = sfSprite_create();
	sfSprite_scale(fi->map.sprite, invers);
	sfSprite_setTextureRect(fi->map.sprite, fi->map.square);
	sfSprite_setTexture(fi->map.sprite, fi->map.texture, sfTrue);
}

void set_relief(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture5 = sfTexture_createFromImage(fi->map.map_relief, NULL);
	fi->map.sprite5 = sfSprite_create();
	sfSprite_scale(fi->map.sprite5, invers);
	sfSprite_setTextureRect(fi->map.sprite5, fi->map.square);
	sfSprite_setTexture(fi->map.sprite5, fi->map.texture5, sfTrue);
}

void set_col(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture2 = sfTexture_createFromImage(fi->map.map_col, NULL);
	fi->map.sprite2 = sfSprite_create();
	sfSprite_scale(fi->map.sprite2, invers);
	sfSprite_setTextureRect(fi->map.sprite2, fi->map.square);
	sfSprite_setTexture(fi->map.sprite2, fi->map.texture2, sfTrue);
}

void set_colID(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture3 = sfTexture_createFromImage(fi->map.map_colID, NULL);
	fi->map.sprite3 = sfSprite_create();
	sfSprite_scale(fi->map.sprite3, invers);
	sfSprite_setTextureRect(fi->map.sprite3, fi->map.square);
	sfSprite_setTexture(fi->map.sprite3, fi->map.texture3, sfTrue);
}

void set_prof(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture4 = sfTexture_createFromImage(fi->map.map_prof, NULL);
	fi->map.sprite4 = sfSprite_create();
	sfSprite_scale(fi->map.sprite4, invers);
	sfSprite_setTextureRect(fi->map.sprite4, fi->map.square);
	sfSprite_setTexture(fi->map.sprite4, fi->map.texture4, sfTrue);
}

void transfer_pixel_background(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->map.layer_background[compter] > 0) {
		fi->map.y = height * 32;
		ok(fi, fi->map.layer_background[compter], c, l);
	}
}

void transfer_pixel_relief(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->map.layer_relief[compter] == 0)
		fi->map.layer_relief[compter] = 93;
	fi->map.y = height * 32;
	ok5(fi, fi->map.layer_relief[compter], c, l);
}

void transfer_pixel_col(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->map.layer_col[compter] == 0)
		fi->map.layer_col[compter] = 93;
	fi->map.y = height * 32;
	ok2(fi, fi->map.layer_col[compter], c, l);
}

void transfer_pixel_colID(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->map.layer_colID[compter] == 0)
		fi->map.layer_colID[compter] = 93;
	fi->map.y = height * 32;
	ok3(fi, fi->map.layer_colID[compter], c, l);
}

void transfer_pixel_prof(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->map.layer_prof[compter] == 0)
		fi->map.layer_prof[compter] = 93;
	fi->map.y = height * 32;
	ok4(fi, fi->map.layer_prof[compter], c, l);
}

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
			transfer_pixel_colID(fi, compter, height);
			transfer_pixel_prof(fi, compter, height);
			fi->map.x2 += 32;
			width++;
			compter++;
		}
		fi->map.x2 = 0;
		height++;
	}
}

void create_layers(files_t *fi)
{
	fi->map.tab_tileset = get_layer("TestMap/layers", fi);
	fi->map.layer_background = fi->map.tab_tileset[0];
	fi->map.layer_relief = fi->map.tab_tileset[1];
	fi->map.layer_colID = fi->map.tab_tileset[2];
	fi->map.layer_col = fi->map.tab_tileset[3];
	fi->map.layer_prof = fi->map.tab_tileset[4];
}

void create_images(files_t *fi)
{
	fi->map.x2 = 0;
	fi->map.image = sfImage_createFromFile("TestMap/gg.png");
	fi->map.map_backgound = sfImage_create(1920, 3200);
	fi->map.map_relief = sfImage_create(1920, 3200);
	fi->map.map_col = sfImage_create(1920, 3200);
	fi->map.map_colID = sfImage_create(1920, 3200);
	fi->map.map_prof = sfImage_create(1920, 3200);
	fi->map.square.left = 0;
	fi->map.square.top = 0;
	fi->map.square.height = 640;
	fi->map.square.width = 640;
	create_layers(fi);
}

void create_map(files_t *fi)
{
	create_images(fi);
	transfer_pixel(fi);
	set_background(fi);
	set_relief(fi);
	set_col(fi);
	set_colID(fi);
	set_prof(fi);
}
