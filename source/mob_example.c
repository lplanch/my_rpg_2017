/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_mob_example(st_rpg *s)
{
	s->f.mob = malloc(sizeof(enemy_t));
	s->f.mob->obj = create_object("images/enemy.png", create_vector2f(1040,
	500), create_rect(0, 0, 58, 89), 0);
	s->f.mob->life = create_object("images/minibar.png",
	create_vector2f(s->f.mob->obj->pos.x, s->f.mob->obj->pos.y - 20),
	create_rect(0, 0, 50, 10), 0);
	s->f.mob->stat = create_first_stat();
}

void destroy_mob_example(st_rpg *s)
{
	destroy_object(s->f.mob->obj);
	destroy_object(s->f.mob->life);
	free(s->f.mob->stat);
	free(s->f.mob);
}

void update_mob_example(st_rpg *s)
{
	if (s->f.mob->stat->pva <= 0) {
		s->f.mob->stat->pva = s->f.mob->stat->pvm;
		s->f.mob->obj->pos = create_vector2f(100 + rand() % 1720,
	100 + rand() % 880);
		sfSprite_setPosition(s->f.mob->obj->sprite, s->f.mob->obj->pos);
		sfSprite_setPosition(s->f.mob->life->sprite,
	create_vector2f(s->f.mob->obj->pos.x, s->f.mob->obj->pos.y - 20));
	}
	s->f.mob->life->rect.width = 50 * s->f.mob->stat->pva /
	s->f.mob->stat->pvm;
	sfSprite_setTextureRect(s->f.mob->life->sprite, s->f.mob->life->rect);
}

void display_mob_example(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->f.mob->obj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->f.mob->life->sprite, NULL);
}
