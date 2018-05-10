/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_spells_warrior2(st_rpg *s)
{
	s->f.war.endure = create_effect("invulnerable", 0, 5);
	s->f.war.lifesteal = create_effect("lifesteal", 20, 5);
	s->f.war.destroyer = create_effect("destroyer", 0, 5);
	s->f.war.parade = create_effect("parade", 0, 5);
	s->f.war.parade->count = 5;
	s->f.war.paricon = create_object("ressources/images/pictostat.png",
	create_vector2f(s->origin.x + 125, s->origin.y + 88),
	create_rect(0, 64, 32, 32), 0);
	s->f.war.rush = create_dash(60, 3000);
	s->f.war.ultd = create_dash(60, 800);
}

void create_spells_warrior1(st_rpg *s)
{
	s->f.war.auto_a = create_swing_from_file("ressources/spells/3/auto");
	s->f.war.whirl =
	create_swing_from_file("ressources/spells/3/whirlwing");
	s->f.war.estoc = 0;
	s->f.war.count = 0;
	s->f.war.hdmg = 50;
	s->f.war.shield = create_aoe_from_file("ressources/spells/3/Heal");
	s->f.war.crack = create_aoe_from_file("ressources/spells/3/Crack");
	s->f.war.hasagi = create_projectile("ressources/proj/HASAGI");
	s->f.war.hpos = create_vector2f(0, 0);
	s->f.war.hrat = create_vector2f(0, 0);
}