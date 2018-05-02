/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_archer(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1)
		update_projectile(s->f.arc.arrow[i]);
	update_kalash(s);
	update_axe(s);
	if (s->f.arc.heal->shot)
		clocked_animation(s->f.arc.heal->anim);
	if (s->f.arc.barrage->shot)
		clocked_animation(s->f.arc.barrage->anim);
	if (s->f.arc.barrage->anim->li > s->f.arc.barrage->anim->ver) {
		s->f.arc.barrage->anim->li = 0;
		s->f.cast = 0;
	}
}

void update_gunner(st_rpg *s)
{
	gunner_update_auto_attack(s);
	gunner_update_grenade(s);
	for (int i = 0; i != 100; i += 1)
		update_projectile(s->f.gun.flame[i]);
	for (int i = 0; i != 10; i += 1) {
		update_projectile(s->f.gun.bullet[i]);
		update_projectile(s->f.gun.ultb[i]);
		if (s->f.gun.ultb[i]->shot) {
			s->f.gun.trait[i]->rect.width += 80;
			s->f.gun.trait[i]->rect.height -= 1;
			sfSprite_setTextureRect(s->f.gun.trait[i]->sprite,
			s->f.gun.trait[i]->rect);
		}
	}
	update_projectile(s->f.gun.net);
	gunner_update_blitz(s);
	gunner_update_ultimate(s);
	gunner_update_flamet(s);
}

void update_rogue(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		update_projectile(s->f.rog.dagger[i]);
	rogue_update_storm(s);
	update_projectile(s->f.rog.dance);
	rogue_update_auto_attack(s);
	if (s->f.rog.flash->shot)
		rogue_update_flash(s);
	if (s->f.rog.zone->shot)
		clocked_animation(s->f.rog.flash->anim);
}

void update_warrior(st_rpg *s)
{
	update_swing(s, s->f.war.auto_a, s->player.weapon[0]);
	update_swing(s, s->f.war.whirl, s->player.weapon[0]);
	if (s->f.war.whirl->shot)
		sfSprite_setRotation(s->player.weapon[0]->sprite,
		s->f.war.whirl->count);
	if (s->f.war.whirl->able == 0 && s->f.war.whirl->shot == 1)
		s->f.war.whirl->able = 1;
	warrior_update_hasagi(s);
	if (s->f.war.shield->shot)
		clocked_animation(s->f.war.shield->anim);
	sfSprite_setPosition(s->f.war.paricon->sprite,
	create_vector2f(s->origin.x + 125, s->origin.y + 108));
}

void update_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {update_archer, update_gunner,
		update_rogue, update_warrior};

	(list[s->player.cdata.classe])(s);
}
