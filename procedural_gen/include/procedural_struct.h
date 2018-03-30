/*
** EPITECH PROJECT, 2018
** procedural_struct.h
** File description:
**
*/

#include "ingame_struct.h"

//MINIMAP
typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

typedef struct minimap {
	framebuffer_t *f_background;
	framebuffer_t *f_minimap;
	sfTexture *fb_texture;
	sfTexture *fm_texture;
	sfSprite *fb_sprite;
	sfSprite *fm_sprite;
	sfFont *current_level_font;
	sfText *current_level_text;
} minimap_t;


//MAP SYSTEM
typedef struct proc_room
{
	int pos1[2];
	int pos2[2];
	int width;
	int height;
	int center[2];
	int visited;
	int drawed;
} proom_t;

typedef struct map_sprite
{
	sfSprite *sprite;
	sfVector2f pos;
	sfIntRect rect;
} smap_t;

typedef struct player_manager
{
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f pos;
	sfVector2f last_pos;
	int max_speed;
	sfVector2i nbr_frame;
	sfVector2f acceleration;
} player_t;

typedef struct game_manager
{
	sfVideoMode mode;
	sfRenderWindow *window;
	sfView *camera;
	player_t player;
	sfVector2f camera_pos;
	sfClock *clock;
	sfTime time;
	float dt;
} gmanager_t;

typedef struct proc_gen
{
	gmanager_t *gman;
	proom_t **proom;
	smap_t ***smap;
	minimap_t *minimap;
	char **map;
	sfTexture *blocks_texture;
	unsigned int current_floor;
} proc_t;

typedef struct proc_var
{
	char *texture_path;
	unsigned int map_width;
	unsigned int map_height;
	unsigned int max_room_s;
	unsigned int min_room_s;
	unsigned int nbr_rooms;
	int current_floor;
	int max_floor;
	sfColor background;
} proc_var_t;

typedef struct game_agent
{
	proc_t *proc;
	ingame_t ingame;
	proc_var_t *pvar;
} gage_t;
