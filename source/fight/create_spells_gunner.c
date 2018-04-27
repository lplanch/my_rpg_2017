/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_gunner_bullets(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1) {
		s->f.gun.bullet[i] =
		create_projectile("ressources/proj/Bullet");
		if (s->player.tree.passive == 0)
			s->f.gun.bullet[i]->range += s->f.gun.bullet[i]
			->range * 0.3;
		else if (s->player.tree.passive == 2 && i == 9) {
			destroy_projectile(s->f.gun.bullet[i]);
			s->f.gun.bullet[i] =
			create_projectile("ressources/spells/1/xblt");
		}
		s->f.gun.ultb[i] =
		create_projectile("ressources/spells/1/ultBullet");
		s->f.gun.trait[i] =
		create_object("ressources/spells/1/trait.png",
		create_vector2f(0, 0), create_rect(0, 0, 0, 10), 0);
	}
}

void create_gunner_explosions(st_rpg *s)
{
	s->f.gun.explosion =
	create_anim(create_object("ressources/images/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
	sfSprite_setScale(s->f.gun.explosion->obj->sprite,
	create_vector2f(1.8, 1.8));
	s->f.gun.expbullet =
	create_anim(create_object("ressources/images/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
	s->f.gun.explo = create_circle(90, 0, sfTransparent);
	s->f.gun.expbt = create_circle(50, 0, sfTransparent);
}

void create_gunner_second(st_rpg *s)
{
	s->f.gun.current = 0;
	s->f.gun.ultrat = create_vector2f(0, 0);
	s->f.gun.ult = 0;
	s->f.gun.autospeed = 0.1;
	s->f.gun.origin = s->f.gun.ultb[0]->dmg;
	s->f.gun.auto_a = 0;
	s->f.gun.blitz = create_projectile("ressources/proj/Blitz");
	s->f.gun.blitz->obj->rect = create_rect(0, 0, 40, 15);
	sfSprite_setTextureRect(s->f.gun.blitz->obj->sprite,
	s->f.gun.blitz->obj->rect);
	s->f.gun.t = create_st_time();
	s->f.gun.blitzt = create_st_time();
	s->f.gun.delay = 0.8;
	s->f.gun.grenade = create_projectile("ressources/proj/Grenade");
	s->f.gun.grenadespeed = s->f.gun.grenade->obj->speed;
}