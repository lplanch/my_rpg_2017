/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void set_level_up(st_rpg *s)
{
	s->player.stat->lvl += 1;
	s->player.tree.skillp += 1;
	s->player.stat->pvm += rand() % 2;
	s->player.stat->pva = s->player.stat->pvm;
	s->player.stat->frc += rand() % 2;
	s->player.stat->def += rand() % 2;
	s->player.stat->prc += rand() % 3;
	s->player.stat->vit += rand() % 2;
	s->player.stat->cha += rand() % 3;
	s->player.stat->exp -= 100;
	launch_particle(s->part.lvlup, s->player.obj->pos, 0);
}
