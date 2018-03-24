/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_spells_archer(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1) {
		s->f.arc.arrow[i] = create_projectile("projectile/Arrow");
	}
	s->f.arc.axe = create_projectile("projectile/Axe");
	s->f.arc.kal = create_st_time();
	s->f.arc.current = 0;
	s->f.arc.barrage.shot = 0;
	s->f.arc.barrage.duration = 5;
	s->f.arc.barrage.t = create_st_time();
	s->f.arc.kalash = 0;
	s->f.arc.axeangle = 0;
	s->f.arc.kalashcount = 0;
	s->f.arc.kalashspeed = 0.08;
	s->f.arc.barrage.circle = sfCircleShape_create();
	sfCircleShape_setRadius(s->f.arc.barrage.circle, 100);
	sfCircleShape_setOutlineColor(s->f.arc.barrage.circle, sfRed);
	sfCircleShape_setFillColor(s->f.arc.barrage.circle, sfTransparent);
	sfCircleShape_setOutlineThickness(s->f.arc.barrage.circle, 5);
}

void create_spells_gunner(st_rpg *s)
{
	s->f.gun.current = 0;
	s->f.gun.autospeed = 0.1;
	for (int i = 0; i != 10; i += 1)
		s->f.gun.bullet[i] = create_projectile("projectile/Bullet");
	s->f.gun.auto_a = 0;
	s->f.gun.blitz = create_projectile("projectile/Blitz");
	s->f.gun.blitz->obj->rect = create_rect(0, 0, 40, 15);
	sfSprite_setTextureRect(s->f.gun.blitz->obj->sprite,
	s->f.gun.blitz->obj->rect);
	s->f.gun.t = create_st_time();
	s->f.gun.blitzt = create_st_time();
	s->f.gun.delay = 0.8;
	s->f.gun.grenade = create_projectile("projectile/Grenade");
	s->f.gun.grenadespeed = s->f.gun.grenade->obj->speed;
	s->f.gun.explosion = create_anim(create_object("images/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
}

void create_spells_rogue(st_rpg *s)
{

}

void create_spells_warrior(st_rpg *s)
{

}

void create_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {create_spells_archer,
	create_spells_gunner, create_spells_rogue, create_spells_warrior};

	(list[s->cust.cdata.classe])(s);
}
