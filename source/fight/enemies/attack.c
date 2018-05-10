/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void attack_enemy(st_rpg *s, int i)
{
	float amount = s->f.mob[i]->stat->frc *
	(1 / (s->player.stat->def + 1));

	if (hitbox(s->player.obj, s->f.mob[i]->obj) && s->f.mob[i]->aggro) {
		hurt(s, amount);
		launch_dmg_show(s, amount, s->player.obj);
	}
}
