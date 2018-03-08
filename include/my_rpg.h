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

typedef struct struct_main_menu
{
	st_time t;
	st_anim *anim;
	int option;
	int sens;
	st_button *button[3];
	g_object *cursor;
	g_object *rope;
	g_object *first;
	g_object *abyss[2];
	g_object *rockback[2];
	g_object *rock2[2];
} st_menu;

typedef struct struct_rpg
{
	st_menu mainm;
	sfRenderWindow *window;
} st_rpg;

st_time create_st_time(void);
st_anim *create_anim(g_object *obj, sfVector2i max, float speed);
void clocked_animation(st_anim *anim);
int mouse_in_object(g_object *obj, sfRenderWindow *window);
st_button *create_button(char *str, sfVector2f pos, sfIntRect rect, sfColor c);
void *destroy_button(st_button *button);
void movement_mainm(st_rpg *s);
void destroy_main_menu(st_rpg *s);
int main_menu(st_rpg *s);
void display_menu_background(st_rpg *s);
int main_menu_cutscene(st_rpg *s);
sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f create_vector2f(float x, float y);
sfVector2i create_vector2i(int x, int y);

#endif
