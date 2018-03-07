/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_testmap
{
	int x;
	int x2;
	int y;
	sfImage *image;
	sfImage *testmap;
	sfSprite *sprite;
	sfTexture *texture;
	sfColor color;
} testmap_t;

typedef struct s_files
{
	int direction;
	sfRenderWindow *window;
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect square;
	sfVector2f square2;
	sfVector2f invers;
	sfTexture *gtexture;
	sfSprite *gsprite;
	sfIntRect gsquare;
	sfVector2f gsquare2;
	sfVector2f invers2;
	testmap_t testmap;
} files_t;

#endif
