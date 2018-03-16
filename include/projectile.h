/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** game_object.h
*/

#ifndef PROJECTILE_
#define PROJECTILE_
#include <SFML/Graphics.h>

typedef struct projectile
{
	g_object *obj;
	float range;
	float used;
	int shot;
	float dmg;
	float ratio;
	float cd;
	char *effect;
	float duration;
	sfVector2f angle;
} proj_t;

proj_t *create_projectile(char *path);
void update_projectile(proj_t *proj);
void destroy_projectile(proj_t *proj);

#endif
