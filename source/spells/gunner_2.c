/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_net(st_rpg *s)
{
	s->f.gun.net->angle = get_angle(s);
	launch_projectile(s, s->f.gun.net, s->f.gun.net->angle);
}

void gunner_jump(st_rpg *s)
{
	launch_dash(s, s->f.gun.jump);
}

void choose_spell2_gunner(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {gunner_net, gunner_jump};

	(list[s->player.tree.spell2])(s);
}
