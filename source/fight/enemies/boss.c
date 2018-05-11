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
	s->f.boss.mob->cdcount -= dt;
	if (s->f.boss.mob->cdcount < 0) {
		s->f.boss.mob->cdcount  = s->f.boss.mob->cd;
		launch_champ_spells(s);
	}
}

void display_champ(st_rpg *s)
{
	printf("top %d, left %d\n", s->f.boss.mob->obj->rect.top, s->f.boss.mob->obj->rect.left);
	sfRenderWindow_drawSprite(s->window, s->f.boss.mob->obj->sprite, NULL);
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
	destroy_enemy(s->f.boss.mob);
}

void generate_champ(st_rpg *s)
{
	s->f.boss.mob = generate_enemy("ressources/enemies/Champ");
	s->f.boss.attack = 0;

	sfSprite_setPosition(s->f.boss.mob->obj->sprite,
	(sfVector2f){s->player.obj->pos.x, s->player.obj->pos.y});
	sfSprite_setScale(s->f.boss.mob->obj->sprite, (sfVector2f){3, 3});
	for (int i = 0; i != 6; i += 1)
		s->f.boss.tent[i] = create_aoe_from_file(
		"ressources/spells/enemies/tent");
	s->f.boss.well = create_aoe_from_file("ressources/spells/enemies/well");
	s->f.boss.ball = create_aoe_from_file("ressources/spells/enemies/ball");
}
