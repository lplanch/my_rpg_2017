/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_enemies(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1)
		destroy_enemy(s->f.mob[i]);
}

void update_enemies(st_rpg *s)
{
	update_life_bars_enemies(s);
}

void generate_enemies(st_rpg *s)
{
	s->f.mob = malloc(sizeof(enemy_t) * 10);
	for (int i = 0; i != 10; i += 1) {
		s->f.mob[i] = generate_enemy("ressources/enemies/Fanatic");
		s->f.mob[i]->obj->pos = create_ennemy_position(s);
		sfSprite_setPosition(s->f.mob[i]->obj->sprite,
		s->f.mob[i]->obj->pos);
	}
}
