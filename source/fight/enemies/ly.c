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
	clocked_animation(s->f.boss.ray->anim);
}

void display_ly(st_rpg *s)
{
	choose_display_enemies(s, 1);
}

void destroy_ly(st_rpg *s)
{
	destroy_aoe(s->f.boss.ray);
}

void generate_ly(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1)
		destroy_enemy(s->f.mob[i]);
	s->proc.pvar.enemy_nbr = 2;
	s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
	generate_champ(s);
	s->f.mob[1] = generate_enemy("ressources/enemies/Ly");
	s->f.mob[1]->obj->pos.x = s->player.obj->pos.x;
	s->f.mob[1]->obj->pos.y = s->player.obj->pos.y;
	sfSprite_setPosition(s->f.mob[1]->obj->sprite,
	s->f.mob[1]->obj->pos);
	sfSprite_setScale(s->f.mob[1]->obj->sprite, (sfVector2f){3, 3});
	s->f.boss.ray = create_aoe_from_file("ressources/spells/enemies/ray");
}
