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

#include "procedural_struct.h"

#define MIN(a, b) ((a < b)? a : b)
#define MAX(a, b) ((a > b)? a : b)

//GAME MANAGE
static const unsigned int WIDTH = 1664;
static const unsigned int HEIGHT = 936;
static const char window_name[13] = "INTO THE DEEP";

//INPUTS
static const sfKeyCode key_up = sfKeyZ;
static const sfKeyCode key_down = sfKeyS;
static const sfKeyCode key_left = sfKeyQ;
static const sfKeyCode key_right = sfKeyD;
static const sfKeyCode key_map = sfKeyTab;
static const sfKeyCode key_inv = sfKeyLShift;
static const sfMouseButton key_fast_inv = sfMouseMiddle;

//MAKE MAP
proc_t *map_creation(gage_t *gage);
void make_positions_proom(gage_t *gage, proc_t *proc);
void make_holes(proom_t *proom, char **map, int i);
void make_map_better(char **map);
void increment_proc_struct(proc_var_t *pvar, proc_t *proc);
char **border_map(proc_var_t *pvar, char **map);
void print_map(char **map);

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
int is_wall(char block);

//DRAW MAP
void draw_map(gage_t *gage);
void free_map_tbl(proc_t *proc);
smap_t ***create_sprite_map(gage_t *gage, char **map);

//MANAGER
int verif_input_map(gage_t *gage);
void update_camera_position(proc_t *proc);
void update_player_position(proc_t *proc);
void verify_y_movement(proc_t *proc);
void verify_x_movement(proc_t *proc);
int interval(float value, float less, float max);

//MINIMAP
void init_minimap(gage_t *gage, proc_t *proc);
void verify_minimap(gage_t *gage);
void update_minimap(proc_t *proc);
void draw_rect_room(proc_t *proc, proom_t *proom, int x, int y);
void draw_rect_corridor(proc_t *proc, int x, int y);
void draw_rect_player(proc_t *proc);

//INIT MAP
gmanager_t *init_dungeon_game(proc_t *proc, gage_t *gage);

//FRAMEBUFFER
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_fill_screen(framebuffer_t *buffer, sfColor color);
void my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color);
void fill_minimap_screen(framebuffer_t *buffer, sfColor color);
void reset_screen(framebuffer_t *buffer);
void my_draw_rect(framebuffer_t *buff, int pos[2], int size[2], sfColor color);
void my_draw_f_rect(framebuffer_t *buff, int pos[2], int size[2], int diag[4]);
void my_draw_vrect(framebuffer_t *buff, int pos[2], int size[2], sfColor color);
void my_draw_line(framebuffer_t *b, int pos1[2], int pos2[2], sfColor c);
void my_draw_octan(framebuffer_t *buffer, int r, int pos[2], sfColor color);
void my_draw_circle(framebuffer_t *buffer, int pos[2], int r, sfColor c);
void my_draw_circle_filled(framebuffer_t *b, int pos[2], int r, sfColor c);

//CREATE BLOCKS
int is_ground(char chr);
int many_around(char **map, int x, int y);

void make_ground_block(sfTexture *blocks, smap_t *smap);
void make_exit_block(sfTexture *blocks, smap_t *smap);
void make_leftright_block(sfTexture *blocks, smap_t *smap);
void make_bot_block(sfTexture *blocks, smap_t *smap);
void make_top_block(sfTexture *blocks, smap_t *smap);

void make_corner_botleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_botright_block(sfTexture *blocks, smap_t *smap);
void make_corner_topleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_topright_block(sfTexture *blocks, smap_t *smap);

void make_icorner_botleft_block(sfTexture *blocks, smap_t *smap);
void make_icorner_botright_block(sfTexture *blocks, smap_t *smap);
void make_icorner_topleft_block(sfTexture *blocks, smap_t *smap);
void make_icorner_topright_block(sfTexture *blocks, smap_t *smap);

void make_deadlock_top_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_bot_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_right_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_left_block(sfTexture *blocks, smap_t *smap);

//MAIN GAME
int launch_dungeon_game(gage_t *gage);
void free_dungeon(proc_t *proc);
void free_gage_game(gage_t *gage);

//START A NEW LEVEL
void next_level_screen(gage_t *gage);
void fade_in_text(sfRenderWindow *window, sfText *text);
void fade_out_text(sfRenderWindow *window, sfText *text);

//INVENTORY
ingame_t *create_ingame_player(void);
void clear_inventory_slot(item_t *slot);
void add_inventory_slot(item_t *first_slot);
void remove_inventory_slot(item_t *first_slot);
void create_fast_inventory_screen(ingame_t *ing);
void verify_inventory(gmanager_t *gman);
void verify_fast_inventory(gmanager_t *gman);
