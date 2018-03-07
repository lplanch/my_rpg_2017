/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void ok(files_t *fi, int col)
{
	int c = 0;
	int d = 0;
	int x = 0;
	int y = 0;
	int compter = 0;

	compter = (col / 31);
	y = compter * 32;
	while (c != 32) {
		d = 0;
		fi->testmap.x = fi->testmap.x2;
		x = (col - compter * 31) * 32 - 32;
		while (d != 32) {
			fi->testmap.color = sfImage_getPixel(fi->testmap.image, x, y);
			sfImage_setPixel(fi->testmap.testmap, fi->testmap.x, fi->testmap.y, fi->testmap.color);
			d++;
			x++;
			fi->testmap.x++;
		}
		fi->testmap.y++;
		y++;
		c++;
	}
}

void create_tileset(files_t *fi)
{
	int a = 0;
	int b = 0;
	int y = 0;
	int x = 0;
	int col[5][5] = {{282, 142, 143, 0, 0}, {0, 173, 174, 230, 231}, {0, 204, 205, 261, 262}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
	sfIntRect square = {0, 0, 1000, 1000};

	fi->testmap.x2 = 0;
	fi->testmap.image = sfImage_createFromFile("TestMap/gg.png");
	fi->testmap.testmap = sfImage_create(1000, 1000);
	while (b != 5) {
		a = 0;
		while (a != 5) {
			if (col[b][a] > 0) {
				fi->testmap.y = b * 32;
				ok(fi, col[b][a]);
				fi->testmap.x2 += 32;
				a++;
			} else {
				fi->testmap.x2 += 32;
				a++;
			}
		}
		fi->testmap.x2 = 0;
		b++;
	}
	fi->testmap.texture = sfTexture_createFromImage(fi->testmap.testmap, NULL);
	fi->testmap.sprite = sfSprite_create();
	sfSprite_setTextureRect(fi->testmap.sprite, square);
	sfSprite_setTexture(fi->testmap.sprite, fi->testmap.texture, sfTrue);
	while (sfRenderWindow_isOpen(fi->window)) {
		sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite, NULL);
		sfRenderWindow_display(fi->window);
	}
}
