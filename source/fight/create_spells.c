/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_spells_archer(st_rpg *s)
{
	create_archer_passive(s);
	create_archer_projectiles(s);
}

void create_spells_gunner(st_rpg *s)
{
	create_gunner_bullets(s);
	create_gunner_second(s);
	create_gunner_explosions(s);
	create_gunner_ults(s);
}

void create_spells_rogue(st_rpg *s)
{
	create_rogue_daggers(s);
	create_rogue_autos(s);
}

void create_spells_warrior(st_rpg *s)
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

void create_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {create_spells_archer,
		create_spells_gunner, create_spells_rogue,
		create_spells_warrior};

	(list[s->player.cdata.classe])(s);
}
