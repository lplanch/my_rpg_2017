/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

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
			sfImage_setPixel(fi->testmap.testmap, fi->testmap.x,
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

void set_and_draw(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->testmap.texture = sfTexture_createFromImage(fi->testmap.testmap, NULL);
	fi->testmap.sprite = sfSprite_create();
	sfSprite_scale(fi->testmap.sprite, invers);
	sfSprite_setTextureRect(fi->testmap.sprite, fi->testmap.square);
	sfSprite_setTexture(fi->testmap.sprite, fi->testmap.texture, sfTrue);
	while (sfRenderWindow_isOpen(fi->window)) {
		sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite, NULL);
		sfRenderWindow_display(fi->window);
	}
}

void transfer_pixel2(files_t *fi, int compter, int height)
{
	int c = 0;
	int l = 0;

	if (fi->testmap.layer_background[compter] > 0) {
		fi->testmap.y = height * 32;
		ok(fi, fi->testmap.layer_background[compter], c, l);
	}
}

void transfer_pixel(files_t *fi)
{
	int width = 0;
	int height = 0;
	int compter = 0;

	while (height != 5) {
		width = 0;
		while (width != 5) {
			transfer_pixel2(fi, compter, height);
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
	int layer_background[25] = {263, 263, 263, 233, 263, 232, 263, 263, 263,
	264, 263, 235, 263, 263, 263, 264, 269, 263, 233,
	263, 263, 265, 270, 270, 267};
	int layer_col[25] = {282, 142, 143, 0, 0, 0, 173, 174, 230, 231, 0,
	204, 205, 261, 262, 287, 0, 0, 0, 0, 318, 0, 0, 0, 0};

	while (i != 25) {
		fi->testmap.layer_col[i] = layer_col[i];
		fi->testmap.layer_background[i] = layer_background[i];
		i++;
	}
}

void create_images(files_t *fi)
{
	fi->testmap.x2 = 0;
	fi->testmap.image = sfImage_createFromFile("TestMap/gg.png");
	fi->testmap.testmap = sfImage_create(1000, 1000);
	fi->testmap.square.left = 0;
	fi->testmap.square.top = 0;
	fi->testmap.square.height = 1000;
	fi->testmap.square.width = 1000;
	create_layers(fi);
}

void create_map(files_t *fi)
{
	create_images(fi);
	transfer_pixel(fi);
	set_and_draw(fi);
}
