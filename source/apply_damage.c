/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void handle_explosive(st_rpg *s, proj_t *proj)
{
	if (!my_strcmp(proj->effect, "explosive")) {
		s->f.gun.expbullet->obj->pos = create_vector2f(s
		->f.gun.bullet[9]->obj->pos.x - 50, s->f.gun.bullet[9]
		->obj->pos.y - 50);
		sfSprite_setPosition(s->f.gun.expbullet->obj->sprite,
		s->f.gun.expbullet->obj->pos);
		sfCircleShape_setPosition(s->f.gun.expbt,
		s->f.gun.expbullet->obj->pos);
		s->f.gun.bullet[9]->shot = 2;
		s->f.gun.expbullet->l = 0;
		s->f.gun.expbullet->c = 0;
		if (circle_hitbox(s->f.gun.expbt, s->f.mob->obj)) {
			s->f.mob->stat->pva -= 70 + 15 * s->player.stat->lvl;
		}
	}
}

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
		if (!my_strcmp(proj->effect, "pierce")) {
			projectile_damage_enemy(s, proj, mob);
			proj->shot = 1;
		} else {
			projectile_damage_enemy(s, proj, mob);
			proj->shot = 0;
		}
		handle_explosive(s, proj);
	}
}

void apply_aoe(st_rpg *s, aoe_t *aoe, enemy_t *mob)
{
	mob->stat->pva -= aoe->dmg + s->player.stat->frc * aoe->dmgratio;
}
