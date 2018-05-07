/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

/*void update_particles_archer(st_rpg *s)
{

}*/

void update_particles_gunner(st_rpg *s, float dt)
{
	update_particle(s->f.gun.partf, dt);
	update_particle(s->f.gun.partg, dt);
}

/*void update_particles_archer(st_rpg *s)
{

}

void update_particles_archer(st_rpg *s)
{

}*/

void update_particles_class(st_rpg *s, float dt)
{
	void (*list[4])(st_rpg *s, float dt) = {update_particles_gunner,
		update_particles_gunner, update_particles_gunner,
		update_particles_gunner};

	if (s->player.cdata.classe == 1)
		(list[s->player.cdata.classe])(s, dt);
}
