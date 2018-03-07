/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void spriteset_game(files_t *fi)
{
	sfSprite_setTexture(fi->sprite, fi->texture, sfTrue);
	sfSprite_setTexture(fi->gsprite, fi->gtexture, sfTrue);
}

void squaresetup_game(files_t *fi)
{
	fi->square.left = 0;
	fi->square.top = 0;
	fi->square.width = 48;
	fi->square.height = 48;
	fi->square2.x = 800;
	fi->square2.y = 500;
	fi->gsquare.left = 0;
	fi->gsquare.top = 0;
	fi->gsquare.width = 6000;
	fi->gsquare.height = 4000;
	fi->gsquare2.x = 0;
	fi->gsquare2.y = 0;
	fi->invers.x = 3;
	fi->invers.y = 3;
	sfSprite_scale(fi->sprite, fi->invers);
	sfSprite_setTextureRect(fi->sprite, fi->square);
	sfSprite_setPosition(fi->sprite, fi->square2);
	sfSprite_setTextureRect(fi->gsprite, fi->gsquare);
	sfSprite_setPosition(fi->gsprite, fi->gsquare2);
}

void characters_setup(files_t *fi)
{
	fi->texture =
	sfTexture_createFromFile("car/car2.png", NULL);
	fi->sprite = sfSprite_create();
	fi->gtexture =
	sfTexture_createFromFile("map/mo.jpeg", NULL);
	fi->gsprite = sfSprite_create();
	squaresetup_game(fi);
	spriteset_game(fi);
	sfSprite_setTextureRect(fi->sprite, fi->square);
	sfSprite_setTextureRect(fi->gsprite, fi->gsquare);
}

void move(files_t *fi)
{
	fi->square.left += 48;
	if (fi->square.left >= 144)
		fi->square.left = 0;
}

void key(sfEvent event, files_t *fi)
{
	switch (event.key.code) {
	case sfKeyUp:
		fi->square.top = 144;
		fi->gsquare2.y += 30;
		move(fi);
		break;
	case sfKeyDown:
		fi->square.top = 0;
		fi->gsquare2.y -= 30;
		move(fi);
		break;
	case sfKeyRight:
		fi->square.top = 96;
		fi->gsquare2.x -= 30;
		move(fi);
		break;
	case sfKeyLeft:
		fi->square.top = 48;
		fi->gsquare2.x += 30;
		move(fi);
		break;
	}
	if (event.type == sfEvtKeyPressed &&
	event.key.code == sfKeyReturn) {
	}
}

int game(files_t *fi)
{
	int a = 0;
	sfEvent event;

	while (a == 0) {
		while (sfRenderWindow_pollEvent(fi->window, &event)) {
			if (event.type == sfEvtClosed)
				a = 1;
			key(event, fi);
		}
		sfSprite_setTextureRect(fi->sprite, fi->square);
		sfSprite_setPosition(fi->gsprite, fi->gsquare2);
		sfRenderWindow_drawSprite(fi->window, fi->gsprite, NULL);
		sfRenderWindow_drawSprite(fi->window, fi->sprite, NULL);
		sfRenderWindow_display(fi->window);
	}
}

sfRenderWindow* window_create(files_t *fi, char *name)
{
	sfVideoMode window2 = {1920, 1080, 32};
	fi->window = sfRenderWindow_create(window2, name, sfClose, NULL);
	return (0);
}

void create2(files_t *fi)
{
	characters_setup(fi);
}

void create(files_t *fi)
{
	window_create(fi, "my_rpg");
	create2(fi);
}

int prog(void)
{
	int o = 0;
	files_t fi;

	create(&fi);
	while (sfRenderWindow_isOpen(fi.window)) {
		game(&fi);
		sfRenderWindow_close(fi.window);
	}
	//destroy(&fi);
	return (0);
}

int main(int ac, char **av)
{
	prog();
}
