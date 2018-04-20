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
#include "my_rpg.h"
#include "game_object.h"

typedef struct struct_button
{
	t_object *text;
	g_object *obj;
} st_button;

typedef struct s_clock
{
	sfClock *clock;
	sfTime tmp;
	float seconds;
} clockz_t;

typedef struct s_pnj
{
	char *name;
	st_button *name_box;
	st_button *dialog_box;
	g_object *pnj;
	g_object *choice_box_edge[2];
	g_object *cursor;
	st_button **choice_box;
} pnj_t;

typedef struct s_pos
{
	int x;
	int y;
} pos_t;

typedef struct s_map
{
	int x;
	int x2;
	int y;
	int **tab_tileset;
	int *layer_background;
	int *layer_relief;
	int *layer_col;
	int *layer_colID;
	int *layer_prof;
	sfImage *image;
	sfImage *map_backgound;
	sfImage *map_relief;
	sfImage *map_col;
	sfImage *map_colID;
	sfImage *map_prof;
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
} map_t;

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
	int max_pnj;
	int choice_cursor;
	int var_choice;
	int nb_choice_pre;
	int loading_timer;
	int pre_var;
	int relief;
	sfClock *clock;
	sfView *view;
	g_object *character;
	g_object *ID_character;
	g_object *loading;
	sfVector2f camera;
	sfVector2f camera_prec;
	sfRenderWindow *window;
	sfVector2f speed;
	sfVector2f velocity;
	sfVector2f invers;
	sfVector2f maxspeed;
	sfVector2f vect_ID_player;
	pnj_t pnj[4];
	pos_t pos[10];
	colcircle_t colcircle[42];
	colsquare_t colsquare[204];
	map_t map;
	clockz_t time;
} files_t;

#endif
