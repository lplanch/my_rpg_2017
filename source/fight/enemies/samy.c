/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_samy(st_rpg *s, float dt)
{
	printf("cast = %d\n", s->f.mob[0]->cast);
	printf("casting = %f\n", s->f.boss.casting);
	s->f.mob[0]->cdcount -= dt;
	if (s->f.mob[0]->cdcount < 0 && enemy_is_able(s, 0)) {
		s->f.mob[0]->cast = 2;
		s->f.boss.casting = 1;
	} if (s->f.boss.casting > 0) {
		s->f.boss.casting -= dt;
	} if (s->f.boss.casting < 0) {
		s->f.mob[0]->cdcount = s->f.mob[0]->cd;
		s->f.mob[0]->cast = 0;
		s->f.boss.casting = 0;
		launch_samy_spell(s);
	}
	update_samy_dash(s);
}

/*void display_samy(st_rpg *s)
{
}*/

void destroy_samy(st_rpg *s)
{
	destroy_dash(s->f.boss.dash);
}

void generate_samy(st_rpg *s)
{
	destroy_enemies(s);
	s->proc.pvar.enemy_nbr = 1;
	s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
	s->f.mob[0] = generate_enemy("ressources/enemies/Samy");
	s->f.mob[0]->obj->pos.x = s->player.obj->pos.x;
	s->f.mob[0]->obj->pos.y = s->player.obj->pos.y;
	sfSprite_setPosition(s->f.mob[0]->obj->sprite,
	s->f.mob[0]->obj->pos);
	sfSprite_setScale(s->f.mob[0]->obj->sprite, (sfVector2f){3, 3});
	s->f.boss.dash = create_dash(70, 800);
	s->f.boss.casting = 0;
}
