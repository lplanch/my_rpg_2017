/*
** EPITECH PROJECT, 2018
** procedural.h
** File description:
** ezwin
*/

#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#define MIN(a, b) ((a < b)? a : b)
#define MAX(a, b) ((a > b)? a : b)

//GAME MANAGE
static const unsigned int WIDTH = 1664;
static const unsigned int HEIGHT = 936;
static const char *window_name = "INTO THE DEEP";

//PROCEDURAL GENERATION
static const unsigned int map_width = 80;
static const unsigned int map_height = 45;
static const unsigned int max_room_s = 12;
static const unsigned int min_room_s = 8;
static const unsigned int nbr_rooms = 9;

static const sfColor background = {20, 11, 40, 255};

//PLAYER
static const float speed = 0.018;

typedef struct proc_room
{
	int pos1[2];
	int pos2[2];
	int width;
	int height;
	int center[2];
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
	sfVector2f pos;
	sfIntRect rect;
	sfVector2f velocity;
	sfVector2f speed;
	sfVector2f m_speed;
} player_t;

typedef struct game_manager
{
	sfVideoMode mode;
	sfRenderWindow *window;
	sfView *camera;
	player_t player;
	sfVector2f camera_pos;
} gmanager_t;

typedef struct proc_gen
{
	gmanager_t *gman;
	proom_t **proom;
	smap_t ***smap;
	char **map;
	sfTexture *blocks_texture;
	unsigned int current_floor;
} proc_t;

typedef struct game_agent
{
	proc_t *proc;
	unsigned int current_floor;
	unsigned int max_floor;
} gage_t;

//MAKE MAP
proc_t *map_creation(void);
void make_positions_proom(proc_t *proc);
void make_holes(proom_t *proom, char **map, int i);
void increment_proc_struct(proc_t *proc);
void make_map_better(char **map);

//CORRIDORS
void v_corridor(char **map, int y1, int y2, int x);
void h_corridor(char **map, int x1, int x2, int y);
void make_corridors(proc_t *proc, int length);

//CREATE MANDATORY BLOCKS
void create_entry(proc_t *proc);
void create_leave(proc_t *proc);
sfVector2f get_entry_pos(proc_t *proc);
sfVector2f get_exit_pos(proc_t *proc);
void verify_exit_player(gage_t *gage);
int verify_collide(char block);

//DRAW MAP
void draw_map(gage_t *gage);
void free_map_tbl(proc_t *proc);
smap_t ***create_sprite_map(proc_t *proc, char **map);

//MANAGER
int verif_input_map(gage_t *gage);
void update_camera_position(proc_t *proc);
void update_player_position(proc_t *proc);

//CREATE BLOCKS
void make_ground_block(sfTexture *blocks, smap_t *smap);
void make_exit_block(sfTexture *blocks, smap_t *smap);
void make_leftright_block(sfTexture *blocks, smap_t *smap);
void make_bot_block(sfTexture *blocks, smap_t *smap);
void make_top_block(sfTexture *blocks, smap_t *smap);

void make_corner_botleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_botright_block(sfTexture *blocks, smap_t *smap);
void make_corner_topleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_topright_block(sfTexture *blocks, smap_t *smap);

void make_deadlock_top_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_bot_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_right_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_left_block(sfTexture *blocks, smap_t *smap);


//MAIN GAME
int launch_dungeon_game(gage_t *gage);
void free_dungeon(proc_t *proc);
void free_gage_game(gage_t *gage);
void next_level_screen(gage_t *gage);
