/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_champ(st_rpg *s)
{
	clocked_animation(s->f.boss.tent->anim);
	clocked_animation(s->f.boss.well->anim);
	clocked_animation(s->f.boss.ball->anim);
}

void display_champ(st_rpg *s)
{
	for (int i = 0; i != 6; i += 1)
		display_aoe(s->window, s->f.boss.tent);
	display_aoe(s->window, s->f.boss.well);
	display_aoe(s->window, s->f.boss.ball);
}

void destroy_champ(st_rpg *s)
{
	for (int i = 0; i != 6; i += 1)
		destroy_aoe(s->f.boss.tent);
	destroy_aoe(s->f.boss.well);
	destroy_aoe(s->f.boss.ball);
}

int generate_champ_spells(st_rpg *s)
{
	s->f.boss.mob = generate_enemy("ressources/enemies/Champ");
	s->f.boss.attack = 0;

	for (int i = 0; i != 6; i += 1)
		s->f.boss.tent = create_aoe_from_file(
		"ressources/spells/enemies/tent");
	s->f.boss.well = create_aoe_from_file("ressources/spells/enemies/well");
	s->f.boss.ball = create_aoe_from_file("ressources/spells/enemies/ball");
}
