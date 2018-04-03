/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void projectile_damage_enemy(proj_t *proj, enemy_t *mob)
{
	mob->stat->pva -= proj->dmg;
}

void swing_damage_enemy(swing_t *swing, enemy_t *mob)
{
	mob->stat->pva -= swing->dmg;
}

void apply_projectile(proj_t *proj, enemy_t *mob)
{
	if (hitbox(proj->obj, mob->obj) && proj->shot) {
		projectile_damage_enemy(proj, mob);
		proj->shot = 0;
		if (!my_strcmp(proj->effect, "pierce")) {
			projectile_damage_enemy(proj, mob);
			proj->shot = 1;
		}
	}
}

void apply_aoe(aoe_t *aoe, enemy_t *mob)
{
	mob->stat->pva -= aoe->dmg;
}
