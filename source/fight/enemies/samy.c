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
	s->f.mob[0]->cdcount -= dt;
	if (s->f.mob[0]->cdcount < 0 && enemy_is_able(s, 0)) {
		s->f.mob[0]->cast = 2;
		s->f.boss.casting = 1;
		s->f.boss.attack = rand() % 2;
		if (s->f.mob[0]->stat->pva < s->f.mob[0]->stat->pvm / 2 &&
		s->f.boss.rage->amount == 0)
			s->f.boss.attack = 2;
	} if (s->f.boss.casting > 0) {
		s->f.boss.casting -= dt;
	} if (s->f.boss.casting < 0) {
		s->f.mob[0]->cdcount = s->f.mob[0]->cd;
		s->f.mob[0]->cast = 0;
		s->f.boss.casting = 0;
		launch_samy_spell(s);
	}
	update_samy_dash(s, dt);
	update_samy_fusrohdah(s);
}

int choose_samy_diplay(st_rpg *s)
{
	if (s->f.boss.casting > 0 && s->f.boss.attack == 0) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->obj->sprite, &s->f.shade.samy_rush.state);
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->life->sprite, &s->f.shade.samy_rush.state);
		return (0);
	} else if (s->f.boss.casting > 0 && s->f.boss.attack == 1) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->obj->sprite, &s->f.shade.samy_roda.state);
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->life->sprite, &s->f.shade.samy_roda.state);
		return (0);
	} else if (s->f.boss.casting > 0 && s->f.boss.attack == 2 &&
	s->f.mob[0]->poison->count <= 0 && s->f.mob[0]->stun->count <= 0) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->obj->sprite, &s->f.shade.power.state);
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->life->sprite, &s->f.shade.power.state);
		return (0);
	}
	return (1);
}

void display_samy(st_rpg *s)
{
	if (choose_samy_diplay(s) == 1) {
		choose_display_enemies(s, 0);
	}
}

void destroy_samy(st_rpg *s)
{
	destroy_dash(s->f.boss.dash);
	destroy_dash(s->f.boss.fus);
	destroy_effect(s->f.boss.rage);
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
	s->f.boss.dash = create_dash(5, 200);
	s->f.boss.fus = create_dash(40, 800);
	s->f.boss.rage = create_effect("rage", 0, 5);
	s->f.boss.casting = 0;
}
