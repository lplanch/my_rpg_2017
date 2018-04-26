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
		s->f.arc.arrow[i] = create_projectile("ressources/proj/Arrow");
		if (s->player.tree.passive == 0) {
			s->f.arc.arrow[i]->dmg += s->f.arc.arrow[i]->dmg * 0.1;
			s->f.arc.arrow[i]->obj->speed += s->f.arc.arrow[i]
			->obj->speed * 0.5;
		} if (s->player.tree.passive == 1)
			s->f.arc.arrow[i]->effect = "slow";
		if (s->player.tree.passive == 2) {
			//s->player->obj->speed += s->player->obj->speed * 0.2;
		}
	}
	s->f.arc.axe = create_projectile("ressources/proj/Axe");
	s->f.arc.kal = create_st_time();
	s->f.arc.current = 0;
	s->f.arc.kalash = 0;
	s->f.arc.axeangle = 0;
	s->f.arc.kalashcount = 0;
	s->f.arc.kalashspeed = 0.08;
	s->f.arc.heal = create_aoe_from_file("ressources/spells/0/Heal");
	s->f.arc.barrage = create_aoe_from_file("ressources/spells/0/Barrage");
	s->f.arc.leaf = create_effect("power", 0, 6);
}

void create_spells_gunner(st_rpg *s)
{
	s->f.gun.current = 0;
	s->f.gun.ultrat = create_vector2f(0, 0);
	s->f.gun.ult = 0;
	s->f.gun.autospeed = 0.1;
	for (int i = 0; i != 10; i += 1) {
		s->f.gun.bullet[i] = create_projectile("ressources/proj/Bullet");
		if (s->player.tree.passive == 0)
			s->f.gun.bullet[i]->range += s->f.gun.bullet[i]
			->range * 0.3;
		else if (s->player.tree.passive == 2 && i == 9) {
			destroy_projectile(s->f.gun.bullet[i]);
			s->f.gun.bullet[i] = create_projectile("ressources/spells/1/xblt");
		}
		s->f.gun.ultb[i] = create_projectile("ressources/spells/1/ultBullet");
		s->f.gun.trait[i] = create_object("ressources/spells/1/trait.png",
		create_vector2f(0, 0), create_rect(0, 0, 0, 10), 0);
	}
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
	s->f.gun.explosion = create_anim(create_object("ressources/images/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
	sfSprite_setScale(s->f.gun.explosion->obj->sprite,
	create_vector2f(1.8, 1.8));
	s->f.gun.expbullet = create_anim(create_object("ressources/images/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
	s->f.gun.explo = create_circle(90, 0, sfTransparent);
	s->f.gun.expbt = create_circle(50, 0, sfTransparent);
}

void create_spells_rogue(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		s->f.rog.dagger[i] = create_projectile("ressources/proj/Kunai");
	s->f.rog.ultspeed = 0.1;
	s->f.rog.side = 0;
	s->f.rog.ultcount = 0;
	s->f.rog.ultangle = 1;
	s->f.rog.ulting = 0;
	s->f.rog.vanish = 0;
	s->f.rog.auto_bool = 0;
	s->f.rog.current = 0;
	s->f.rog.ultt = create_st_time();
	s->f.rog.dance = create_projectile("ressources/spells/2/Kunai");
	s->f.rog.auto_a[0] = create_swing_from_file("ressources/spells/2/auto");
	s->f.rog.auto_a[0]->sens = -s->f.rog.auto_a[0]->sens;
	s->f.rog.auto_a[1] = create_swing_from_file("ressources/spells/2/auto2");
	s->f.rog.zone = create_aoe_from_file("ressources/spells/2/Zone");
	s->f.rog.bstab = 0;
	s->f.rog.bdmg = s->f.rog.auto_a[0]->dmg * 3;
	s->f.rog.backstab = create_button("M1",
	create_object("ressources/spells/2/auto2.png", create_vector2f(200, 800),
	create_rect(0, 0, 128, 128), 0), sfWhite, 25);
	s->f.rog.bpos[0] = create_vector2f(0, 0);
	s->f.rog.bpos[1] = create_vector2f(0, 0);
	s->f.rog.brat = create_vector2f(0, 0);
	s->f.rog.bcount = 0;
	if (s->player.tree.passive == 1) {
		s->player.stat->frc += 0.1 * s->player.stat->frc;
	}
}

void create_spells_warrior(st_rpg *s)
{
	s->f.war.auto_a = create_swing_from_file("ressources/spells/3/auto");
	s->f.war.whirl = create_swing_from_file("ressources/spells/3/whirlwing");
	s->f.war.estoc = 0;
	s->f.war.count = 0;
	s->f.war.hdmg = 50;
	s->f.war.shield = create_aoe_from_file("ressources/spells/3/Heal");
	s->f.war.hasagi = create_projectile("ressources/proj/HASAGI");
	s->f.war.hpos = create_vector2f(0, 0);
	s->f.war.hrat = create_vector2f(0, 0);
}

void create_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {create_spells_archer,
		create_spells_gunner, create_spells_rogue,
		create_spells_warrior};

	(list[s->player.cdata.classe])(s);
}
