/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_update_auto_attack(st_rpg *s)
{
	update_swing(s, s->f.war.auto_a, s->player.weapon[0]);
}

void warrior_update_hasagi_estoc(st_rpg *s)
{
	s->f.war.hpos.x += s->f.war.hrat.x * 10;
	s->f.war.hpos.y += s->f.war.hrat.y * 10;
	s->f.war.count += 14;
	sfSprite_setPosition(s->player.weapon[0]->sprite,
	s->f.war.hpos);
	sfSprite_setScale(s->player.weapon[0]->sprite,
	create_vector2f(1, 1));
	if (hitbox(s->player.weapon[0], s->f.mob->obj)) {
		s->f.mob->stat->pva -= s->f.war.hdmg;
		s->f.war.estoc = 2;
		s->f.cast = 0;
	} if (s->f.war.count >= 100 || s->f.war.estoc == 2) {
		s->f.cast = 0;
		s->f.war.estoc = 2;
		s->f.war.hasagi->angle = get_angle(s->window);
		launch_projectile(s->f.war.hasagi,
		s->f.war.hasagi->angle);
	}
}

void warrior_update_hasagi(st_rpg *s)
{
	if (s->f.war.estoc == 1)
		warrior_update_hasagi_estoc(s);
	else if (s->f.war.estoc == 2)
		update_projectile(s->f.war.hasagi);
	if (!s->f.war.hasagi->shot && s->f.war.estoc == 2)
		s->f.war.estoc = 0;
}
