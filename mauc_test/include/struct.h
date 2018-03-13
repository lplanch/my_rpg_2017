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

typedef struct s_pos
{
	int x;
	int y;
} pos_t;
typedef struct s_testmap
{
	int x;
	int x2;
	int y;
	int *layer_background;
	int *layer_relief;
	int *layer_col;
	int *layer_colID;
	int *layer_prof;
	sfImage *image;
	sfImage *testmap_backgound;
	sfImage *testmap_relief;
	sfImage *testmap_col;
	sfImage *testmap_colID;
	sfImage *testmap_prof;
	sfSprite *sprite;
	sfTexture *texture;
	sfSprite *sprite2;
	sfTexture *texture2;
	sfSprite *sprite3;
	sfTexture *texture3;
	sfSprite *sprite4;
	sfTexture *texture4;
	sfSprite *sprite5;
	sfTexture *texture5;
	sfIntRect square;
	sfColor color;
} testmap_t;

typedef struct s_colsquare
{
	pos_t pos;
	int width;
	int height;
} colsquare_t;

typedef struct s_colcircle
{
	int rayon_circle;
	int center_circle_x;
	int center_circle_y;
} colcircle_t;

typedef struct s_files
{
	int direction;
	int nbr_colcircle;
	int nbr_colsquare;
	sfView *view;
	sfVector2f camera;
	sfRenderWindow *window;
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect square;
	sfVector2f square2;
	sfVector2f invers;
	sfTexture *ID_text;
	sfSprite *ID_sprite;
	sfIntRect ID_player;
	sfVector2f vect_ID_player;
	pos_t pos[6];
	colcircle_t colcircle[48];
	colsquare_t colsquare[11];
	testmap_t testmap;
} files_t;

#endif
