/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void projectile_damage_enemy(st_rpg *s, proj_t *proj, enemy_t *mob)
{
	mob->stat->pva -= proj->dmg + s->player.stat->frc * proj->dmgratio;
}

void swing_damage_enemy(st_rpg *s, swing_t *swing, enemy_t *mob)
{
	mob->stat->pva -= swing->dmg + s->player.stat->frc * swing->dmgratio;
}

void apply_projectile(st_rpg *s, proj_t *proj, enemy_t *mob)
{
	if (hitbox(proj->obj, mob->obj) && proj->shot) {
		projectile_damage_enemy(s, proj, mob);
		proj->shot = 0;
		handle_pierce(proj);
		handle_bounce(proj);
		handle_explosive(s, proj);
	}
}

void apply_aoe(st_rpg *s, aoe_t *aoe, enemy_t *mob)
{
	mob->stat->pva -= aoe->dmg + s->player.stat->frc * aoe->dmgratio;
}