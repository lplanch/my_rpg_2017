/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_ly(st_rpg *s, float dt)
{
}

void display_ly(st_rpg *s)
{
	choose_display_enemies(s, 1);
}

void destroy_ly(st_rpg *s)
{
}

void generate_ly(st_rpg *s)
{
	destroy_enemies(s);
	s->proc.pvar.enemy_nbr = 2;
	s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
	generate_champ(s);
	s->f.mob[1] = generate_enemy("ressources/enemies/Ly");
	s->f.mob[1]->obj->pos.x = s->player.obj->pos.x;
	s->f.mob[1]->obj->pos.y = s->player.obj->pos.y;
	sfSprite_setPosition(s->f.mob[1]->obj->sprite,
	s->f.mob[1]->obj->pos);
	sfSprite_setScale(s->f.mob[1]->obj->sprite, (sfVector2f){3, 3});
}
