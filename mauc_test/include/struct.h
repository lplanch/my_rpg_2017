/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "game_object.h"

typedef struct struct_button
{
	t_object *text;
	g_object *obj;
} st_button;

typedef struct s_pnj
{
	char *name;
	st_button *name_box;
	st_button *dialog_box;
	g_object *pnj;
} pnj_t;

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
	int camera_pos;
	int dialog_box_isopen;
	int nb_pnj;
	sfView *view;
	sfVector2f camera;
	sfVector2f camera_prec;
	sfRenderWindow *window;
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect square;
	sfVector2f square2;
	sfVector2f speed;
	sfVector2f velocity;
	sfVector2f invers;
	sfVector2f maxspeed;
	sfTexture *ID_text;
	sfSprite *ID_sprite;
	sfIntRect ID_player;
	sfVector2f vect_ID_player;
	pnj_t pnj[5];
	pos_t pos[10];
	colcircle_t colcircle[42];
	colsquare_t colsquare[204];
	testmap_t testmap;
} files_t;

#endif
