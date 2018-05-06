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
	float amount = proj->dmg + s->player.stat->frc / 7 * proj->dmgratio;

	mob->stat->pva -= amount;
	handle_status(s, amount, mob);
}

void swing_damage_enemy(st_rpg *s, swing_t *swing, enemy_t *mob)
{
	float amount = swing->dmg + s->player.stat->frc / 7 * swing->dmgratio;

	mob->stat->pva -= amount;
	handle_status(s, amount, mob);
}

void apply_projectile(st_rpg *s, proj_t *proj, enemy_t **mob)
{
	float amount = proj->dmg + s->player.stat->frc / 7 * proj->dmgratio;
	int i = 0;

	while (i != 10) {
		if (hitbox(proj->obj, mob[i]->obj) && proj->shot) {
			projectile_damage_enemy(s, proj, mob[i]);
			proj->shot = 0;
			handle_pierce(proj);
			handle_bounce(s, proj);
			handle_explosive(s, proj);
			handle_status(s, amount, mob[i]);
		}
		i += 1;
	}
}

void apply_aoe(st_rpg *s, aoe_t *aoe, enemy_t *mob)
{
	float amount = aoe->dmg + s->player.stat->frc / 7 * aoe->dmgratio;

	mob->stat->pva -= amount;
	handle_status(s, amount, mob);
}
