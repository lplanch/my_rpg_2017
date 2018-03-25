/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_archer(st_rpg *s)
{
	display_aoe(s->window, s->f.arc.barrage);
	display_aoe(s->window, s->f.arc.heal);
	for (int i = 0; i != 20; i += 1)
		display_projectile(s->window, s->f.arc.arrow[i]);
	display_projectile(s->window, s->f.arc.axe);
}

void display_gunner(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1)
		display_projectile(s->window, s->f.gun.bullet[i]);
	display_projectile(s->window, s->f.gun.blitz);
	if  (s->f.gun.grenade->shot == 1)
		display_projectile(s->window, s->f.gun.grenade);
	if (s->f.gun.grenade->shot == 2) {
		sfRenderWindow_drawSprite(s->window,
			s->f.gun.explosion->obj->sprite, NULL);
	}
}

void display_rogue(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1)
		display_projectile(s->window, s->f.rog.dagger[i]);
}

void display_warrior(st_rpg *s)
{

}

void display_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {display_archer, display_gunner,
		display_rogue, display_warrior};

	(list[s->cust.cdata.classe])(s);
}