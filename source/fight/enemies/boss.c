/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_champ(st_rpg *s, float dt)
{
	for (int i = 0; i != 6; i += 1)
		clocked_animation(s->f.boss.tent[i]->anim);
	clocked_animation(s->f.boss.well->anim);
	clocked_animation(s->f.boss.ball->anim);
	s->f.mob[0]->cdcount -= dt;
	update_shadowball(s, dt);
	if (precedent_tentacle_is_mid(s))
		update_tentacle(s);
	if (s->f.mob[0]->cdcount < 0) {
		s->f.mob[0]->cdcount  = s->f.mob[0]->cd;
		launch_champ_spells(s);
	}
	update_well(s);
}

void display_champ(st_rpg *s)
{
	for (int i = 0; i != 6; i += 1)
		display_aoe(s->window, s->f.boss.tent[i]);
	display_aoe(s->window, s->f.boss.well);
	display_aoe(s->window, s->f.boss.ball);
}

void destroy_champ(st_rpg *s)
{
	for (int i = 0; i != 6; i += 1)
		destroy_aoe(s->f.boss.tent[i]);
	destroy_aoe(s->f.boss.well);
	destroy_aoe(s->f.boss.ball);
}

void generate_champ(st_rpg *s)
{
	destroy_enemies(s);
	s->proc.pvar.enemy_nbr = 1;
	s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
	s->f.mob[0] = generate_enemy("ressources/enemies/Champ");
	s->f.boss.attack = 0;
	s->f.boss.ctent = 0;
	s->f.boss.used = 0;
	s->f.boss.trat = create_vector2f(0, 0);
	s->f.boss.ballpos = create_vector2f(0, 0);
	s->f.boss.ballrat = create_vector2f(0, 0);
	s->f.mob[0]->obj->pos.x = s->player.obj->pos.x;
	s->f.mob[0]->obj->pos.y = s->player.obj->pos.y;
	sfSprite_setPosition(s->f.mob[0]->obj->sprite,
	s->f.mob[0]->obj->pos);
	sfSprite_setScale(s->f.mob[0]->obj->sprite, (sfVector2f){3, 3});
	for (int i = 0; i != 6; i += 1)
		s->f.boss.tent[i] = create_aoe_from_file(
		"ressources/spells/enemies/tent");
	s->f.boss.well = create_aoe_from_file("ressources/spells/enemies/well");
	s->f.boss.ball = create_aoe_from_file("ressources/spells/enemies/ball");
}
