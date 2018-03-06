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
	game_object *rope;
	game_object *rock[3];
} st_menu;

typedef struct struct_rpg
{
	st_menu mainm;
	sfRenderWindow *window;
} st_rpg;

sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f create_vector2f(float x, float y);

#endif
