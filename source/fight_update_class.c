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
}

void update_gunner(st_rpg *s)
{
	gunner_update_auto_attack(s);
	gunner_update_grenade(s);
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
	gunner_update_blitz(s);
	gunner_update_ultimate(s);
}

void update_rogue(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		update_projectile(s->f.rog.dagger[i]);
	rogue_update_storm(s);
	update_projectile(s->f.rog.dance);
	update_swing(s, s->f.rog.auto_a[0], s->player.weapon[0]);
	update_swing(s, s->f.rog.auto_a[1], s->player.weapon[0]);
}

void update_warrior(st_rpg *s)
{
	warrior_update_auto_attack(s);
	warrior_update_hasagi(s);
	if (s->f.war.shield->shot)
		clocked_animation(s->f.war.shield->anim);
}

void update_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {update_archer, update_gunner,
		update_rogue, update_warrior};

	(list[s->player.cdata.classe])(s);
}
