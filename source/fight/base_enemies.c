/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_enemy(enemy_t *enemy)
{
	free(enemy->stat);
	destroy_object(enemy->life);
	destroy_object(enemy->obj);
	free(enemy);
}

void update_life_bars_enemies(st_rpg *s)
{

	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (s->f.mob[i]->stat->pva <= 0)
			s->f.mob[i]->alive = 0;
		sfSprite_setPosition(s->f.mob[i]->life->sprite,
		create_vector2f(s->f.mob[i]->obj->pos.x,
		s->f.mob[i]->obj->pos.y - 20));
		s->f.mob[i]->life->rect.width = s->f.mob[i]->obj->rect.width
		* s->f.mob[i]->stat->pva / s->f.mob[i]->stat->pvm;
		sfSprite_setTextureRect(s->f.mob[i]->life->sprite,
		s->f.mob[i]->life->rect);
	}
}

void display_enemies(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (s->f.mob[i]->alive) {
			sfRenderWindow_drawSprite(s->window,
			s->f.mob[i]->obj->sprite, NULL);
			sfRenderWindow_drawSprite(s->window,
			s->f.mob[i]->life->sprite, NULL);
		}
	}
}
