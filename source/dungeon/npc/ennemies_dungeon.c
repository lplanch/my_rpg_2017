/*
** EPITECH PROJECT, 2018
** ennemies_dungeon.c
** File description:
**
*/

#include "my.h"
#include "my_rpg.h"

sfVector2f create_ennemy_position(st_rpg *rpg)
{
	int room = rand() % count_rooms(proc->proom);
	int posx = proc->proom[room].pos1[0] +
	(rand() % (proc->proom[room].width - 4)) + 2;
	int posy = proc->proom[room].pos1[1] +
	(rand() % (proc->proom[room].height - 4)) + 2;
	sfVector2f result = {posy * 96 + 48, posx * 96 + 48};

	return (result);
}
