/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** structurates
*/

#ifndef ST_RPG_
	#define ST_RPG_
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "game_object.h"
#include "projectile.h"

typedef struct struct_animation
{
	int height;
	int width;
	int c;
	int l;
	g_object *obj;
	st_time t;
	int hor;
	int ver;
	float speed;
} st_anim;

typedef struct struct_button
{
	t_object *text;
	g_object *obj;
} st_button;

typedef struct custom_data
{
	char sex;
	char *name;
	int classe;
} st_cdata;

typedef struct struct_st_custom
{
	st_cdata cdata;
	int option;
	float sens;
	int menu;
	float rot;
	int cmin;
	int cmax;
	int pos;
	g_object *cursor;
	st_button *bt[5];
	g_object *circle;
	g_object *back;
} st_custom;

typedef struct struct_main_menu
{
	int menu;
	st_time t;
	int option;
	int sens;
	st_button *button[4];
	g_object *cursor;
	g_object *rope;
	g_object *first;
	g_object *abyss[2];
	g_object *rockback[2];
	g_object *rock2[2];
} st_menu;

typedef struct struct_rpg
{
	g_object *loading;
	int returnv;
	st_custom cust;
	st_menu mainm;
	sfRenderWindow *window;
} st_rpg;

void launch_projectile(proj_t *proj, sfRenderWindow *window);
void loading(st_rpg *s);
int cust_left_clicked(st_rpg *s, sfEvent event);
void cust_menu_goto_name(st_rpg *s);
void cust_menu_goto_classes(st_rpg *s);
void cust_menu_goto_sex(st_rpg *s);
int cust_menu_backto_main(st_rpg *s);
void display_cust(st_rpg *s);
void destroy_cust_buttons(st_rpg *s);
void custom_destroy(st_rpg *s);
void create_st_custom(st_rpg *s);
void custom_manage_cursor_events_mouse(st_rpg *s);
void custom_manage_cursor_events_key(st_rpg *s, sfEvent event);
void cust_cursor_animation(st_rpg *s);
void get_cursor_pos_classes(st_rpg *s);
void get_cursor_pos(st_rpg *s);
int custom_launch(st_rpg *s, sfEvent event);
int cust_get_buttons(int menu);
int cust_minx_buttons(int menu);
int cust_maxx_buttons(int menu);
int cust_miny_buttons(int menu);
int cust_maxy_buttons(int menu);
int custom_main(st_rpg *s);
int event_main_menu(st_rpg *s);
int launch_main_menu_options(st_rpg *s);
int launch_main_menu_create_slots(st_rpg *s);
int launch_main_menu_main(st_rpg *s);
int launch_main_menu_saves(st_rpg *s);
void main_menu_goto_main(st_rpg *s);
void main_menu_goto_slots(st_rpg *s);
void main_menu_goto_saves(st_rpg *s);
void main_menu_goto_options(st_rpg *s);
int get_max_buttons(st_rpg *s);
void destroy_main_menu(st_rpg *s);
void initialize_menu(st_rpg *s);
int left_clicked_on_buttons(st_rpg *s, sfEvent event);
st_time create_st_time(void);
void destroy_anim(st_anim *anim);
st_anim *create_anim(g_object *obj, sfVector2i max, float speed);
void clocked_animation(st_anim *anim);
int mouse_in_object(g_object *obj, sfRenderWindow *window);
st_button *create_button(char *str, g_object *object, sfColor c, int size);
st_button *create_vbutton(char *str, sfVector2f pos, sfColor c, int size);
void destroy_button(st_button *button);
void movement_mainm(st_rpg *s);
void destroy_main_menu(st_rpg *s);
int main_menu(st_rpg *s);
void display_menu_background(st_rpg *s);
int main_menu_cutscene(st_rpg *s);
sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f create_vector2f(float x, float y);
sfVector2i create_vector2i(int x, int y);

#endif
