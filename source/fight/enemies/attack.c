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
	float amount = s->f.mob[i]->stat->frc -
	(s->player.stat->def / 100 * s->f.mob[i]->stat->frc);

	if (hitbox(s->player.obj, s->f.mob[i]->obj) && s->f.mob[i]->aggro
	&& s->f.mob[i]->alive && !s->f.mob[i]->cast) {
		hurt(s, amount);
		stop_player(s);
		launch_dash(s, s->f.knock);
		s->f.knock->ratios = get_ratios(get_angle_enemy(s, i));
		s->player.nbr_frame.x = s->f.knock->ratios.x *
		s->f.knock->speed;
		s->player.nbr_frame.y = s->f.knock->ratios.y *
		s->f.knock->speed;
		launch_dmg_show(s, amount, s->player.obj);
	}
}
