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

typedef struct struct_main_menu
{
	st_time t;
	g_object *rope;
	g_object *first;
	g_object *rockback[2];
	g_object *hole[2];
} st_menu;

typedef struct struct_rpg
{
	st_menu mainm;
	sfRenderWindow *window;
} st_rpg;

void destroy_main_menu(st_rpg *s);
int main_menu(st_rpg *s);
void display_menu_background(st_rpg *s);
int main_menu_cutscene(st_rpg *s);
sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f create_vector2f(float x, float y);

#endif
