/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

/*void launch_samy_dash(st_rpg *s)
{
}

void launch_samy_dash(st_rpg *s)
{
}*/

void proc_samy_dash(st_rpg *s)
{
	float amount = s->f.mob[0]->stat->frc -
	(s->player.stat->def / 100 * s->f.mob[0]->stat->frc);

	hurt(s, amount);
	stop_player(s);
	launch_dash(s, s->f.knock);
	s->f.knock->ratios = get_ratios(get_angle_enemy(s,
	0) + 90 + ((rand() % 2) * 180));
	s->player.nbr_frame.x = s->f.knock->ratios.x *
	s->f.knock->speed * 3;
	s->player.nbr_frame.y = s->f.knock->ratios.y *
	s->f.knock->speed * 3;
	launch_dmg_show(s, amount, s->player.obj);
	s->f.recover->count = 1.5;
}

void update_samy_dash(st_rpg *s, float dt)
{
	if (s->f.boss.dash->on) {
		s->f.boss.dash->count -= s->f.boss.dash->speed;
		if (s->f.boss.dash->count <= 0) {
			s->f.mob[0]->cast = 0;
			s->f.boss.dash->on = 0;
		} if (enemy_hitbox(s->player.obj, s->f.mob[0]))
			proc_samy_dash(s);
		s->f.mob[0]->ratios.x = s->f.boss.dash->ratios.x * s->f.boss.dash->speed;
		s->f.mob[0]->ratios.y = s->f.boss.dash->ratios.y * s->f.boss.dash->speed;
		verify_collide_map_enemies(s, dt, 0);
		sfSprite_setPosition(s->f.mob[0]->obj->sprite,
		s->f.mob[0]->obj->pos);
	}
}

void launch_samy_dash(st_rpg *s)
{
	s->f.boss.dash->ratios = get_ratios(get_angle_enemy(s, 0));
	s->f.mob[0]->cast = 2;
	s->f.boss.dash->on = 1;
	s->f.boss.dash->count = s->f.boss.dash->range;
	s->f.mob[0]->ratios.x = s->f.boss.dash->ratios.x * s->f.boss.dash->speed;
	s->f.mob[0]->ratios.y = s->f.boss.dash->ratios.y * s->f.boss.dash->speed;
}

void update_samy_fusrohdah(st_rpg *s)
{
	if (s->f.boss.fus->on) {
		s->f.boss.fus->count -= s->f.boss.fus->speed;
		if (s->f.boss.fus->count <= 0) {
			s->f.mob[0]->cast = 0;
			s->f.boss.fus->on = 0;
		}
	}
}

void launch_samy_fusrohdah(st_rpg *s)
{
	s->f.boss.fus->ratios = get_ratios(get_angle_enemy(s, 0));
	s->f.mob[0]->cast = 2;
	s->f.boss.fus->on = 1;
	s->f.boss.fus->count = s->f.boss.fus->range;
	s->player.nbr_frame.x = s->f.boss.fus->ratios.x * s->f.boss.fus->speed;
	s->player.nbr_frame.y = s->f.boss.fus->ratios.y * s->f.boss.fus->speed;
}

void launch_samy_rage(st_rpg *s)
{
	s->f.boss.rage->amount = 1;
	s->f.boss.fus->speed = s->f.boss.fus->speed * 1.5;
	s->f.boss.fus->range = s->f.boss.fus->range * 1.5;
	s->f.boss.dash->speed = s->f.boss.dash->speed * 1.2;
	s->f.boss.dash->range = s->f.boss.dash->range * 1.2;
}

void launch_samy_spell(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {launch_samy_dash,
	launch_samy_fusrohdah, launch_samy_rage};

	s->f.boss.attack = rand() % 2;
	if (s->f.mob[0]->stat->pva < s->f.mob[0]->stat->pvm / 2 &&
	s->f.boss.rage->amount == 0)
		s->f.boss.attack = 2;
	(list[s->f.boss.attack])(s);
}
