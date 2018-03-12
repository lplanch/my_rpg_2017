/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void ok3(files_t *fi, int col, int c, int l)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	while (c != 32) {
		l = 0;
		fi->testmap.x = fi->testmap.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->testmap.color = sfImage_getPixel(fi->testmap.image, x, y);
			sfImage_setPixel(fi->testmap.testmap_tile3, fi->testmap.x,
			fi->testmap.y, fi->testmap.color);
			l++;
			x++;
			fi->testmap.x++;
		}
		fi->testmap.y++;
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
		fi->testmap.x = fi->testmap.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->testmap.color = sfImage_getPixel(fi->testmap.image, x, y);
			sfImage_setPixel(fi->testmap.testmap_col, fi->testmap.x,
			fi->testmap.y, fi->testmap.color);
			l++;
			x++;
			fi->testmap.x++;
		}
		fi->testmap.y++;
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
		fi->testmap.x = fi->testmap.x2;
		x = (col - compter * 31) * 32 - 32;
		while (l != 32) {
			fi->testmap.color = sfImage_getPixel(fi->testmap.image, x, y);
			sfImage_setPixel(fi->testmap.testmap_backgound, fi->testmap.x,
			fi->testmap.y, fi->testmap.color);
			l++;
			x++;
			fi->testmap.x++;
		}
		fi->testmap.y++;
		y++;
		c++;
	}
}

void draw_map(files_t *fi)
{
	while (sfRenderWindow_isOpen(fi->window)) {
		sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite, NULL);
		sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite2, NULL);
		sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite3, NULL);
		sfRenderWindow_display(fi->window);
	}
}

void set_background(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->testmap.texture = sfTexture_createFromImage(fi->testmap.testmap_backgound, NULL);
	fi->testmap.sprite = sfSprite_create();
	sfSprite_scale(fi->testmap.sprite, invers);
	sfSprite_setTextureRect(fi->testmap.sprite, fi->testmap.square);
	sfSprite_setTexture(fi->testmap.sprite, fi->testmap.texture, sfTrue);
}

void set_col(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->testmap.texture2 = sfTexture_createFromImage(fi->testmap.testmap_col, NULL);
	fi->testmap.sprite2 = sfSprite_create();
	sfSprite_scale(fi->testmap.sprite2, invers);
	sfSprite_setTextureRect(fi->testmap.sprite2, fi->testmap.square);
	sfSprite_setTexture(fi->testmap.sprite2, fi->testmap.texture2, sfTrue);
}

void set_tile(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->testmap.texture3 = sfTexture_createFromImage(fi->testmap.testmap_tile3, NULL);
	fi->testmap.sprite3 = sfSprite_create();
	sfSprite_scale(fi->testmap.sprite3, invers);
	sfSprite_setTextureRect(fi->testmap.sprite3, fi->testmap.square);
	sfSprite_setTexture(fi->testmap.sprite3, fi->testmap.texture3, sfTrue);
}

void transfer_pixel_background2(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->testmap.layer_background[compter] > 0) {
		fi->testmap.y = height * 32;
		ok(fi, fi->testmap.layer_background[compter], c, l);
	}
}

void transfer_pixel_col2(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->testmap.layer_col[compter] == 0)
		fi->testmap.layer_col[compter] = 93;
	fi->testmap.y = height * 32;
	ok2(fi, fi->testmap.layer_col[compter], c, l);
}

void transfer_pixel_tile32(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->testmap.layer_tile3[compter] == 0)
		fi->testmap.layer_tile3[compter] = 93;
	fi->testmap.y = height * 32;
	ok3(fi, fi->testmap.layer_tile3[compter], c, l);
}

void transfer_pixel(files_t *fi)
{
	int width = 0;
	int height = 0;
	int compter = 0;

	while (height != 20) {
		width = 0;
		while (width != 20) {
			transfer_pixel_background2(fi, compter, height);
			transfer_pixel_col2(fi, compter, height);
			transfer_pixel_tile32(fi, compter, height);
			fi->testmap.x2 += 32;
			width++;
			compter++;
		}
		fi->testmap.x2 = 0;
		height++;
	}
}

void create_layers(files_t *fi)
{
	int i = 0;
	int j = 0;
	int **jh = get_layer("TestMap/layers");

	fi->testmap.layer_background = jh[0];
	fi->testmap.layer_tile3 = jh[1];
	fi->testmap.layer_col = jh[2];
}

void create_images(files_t *fi)
{
	fi->testmap.x2 = 0;
	fi->testmap.image = sfImage_createFromFile("TestMap/gg.png");
	fi->testmap.testmap_col = sfImage_create(1000, 1000);
	fi->testmap.testmap_backgound = sfImage_create(1000, 1000);
	fi->testmap.testmap_tile3 = sfImage_create(1000, 1000);
	fi->testmap.square.left = 0;
	fi->testmap.square.top = 0;
	fi->testmap.square.height = 640;
	fi->testmap.square.width = 640;
	create_layers(fi);
}

void create_map(files_t *fi)
{
	create_images(fi);
	transfer_pixel(fi);
	set_background(fi);
	set_col(fi);
	set_tile(fi);
	//draw_map(fi);
}
