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
	if (s->f.arc.barrage.shot)
		sfRenderWindow_drawCircleShape(s->window,
			s->f.arc.barrage.circle, NULL);
	for (int i = 0; i != 20; i += 1) {
		if (s->f.arc.arrow[i]->shot) {
			sfRenderWindow_drawSprite(s->window,
				s->f.arc.arrow[i]->obj->sprite, NULL);
		}
	}
	if (s->f.arc.axe->shot)
		sfRenderWindow_drawSprite(s->window,
			s->f.arc.axe->obj->sprite, NULL);
}

void display_gunner(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1) {
		if (s->f.gun.bullet[i]->shot) {
			sfRenderWindow_drawSprite(s->window,
				s->f.gun.bullet[i]->obj->sprite, NULL);
		}
	}
	if (s->f.gun.blitz->shot == 1)
		sfRenderWindow_drawSprite(s->window,
			s->f.gun.blitz->obj->sprite, NULL);
	if (s->f.gun.grenade->shot == 1)
		sfRenderWindow_drawSprite(s->window,
			s->f.gun.grenade->obj->sprite, NULL);
	if (s->f.gun.grenade->shot == 2)
		sfRenderWindow_drawSprite(s->window,
			s->f.gun.explosion->obj->sprite, NULL);
}

void display_rogue(st_rpg *s)
{

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
