/*
** EPITECH PROJECT, 2018
** mandatory_blocks.c
** File description:
** spawn mandatory blocks like entry and leave
*/

#include "my.h"
#include "my_rpg.h"

int count_rooms(proom_t *proom)
{
	int res = 0;

	while (proom[res].last == 0)
		res += 1;
	return (res);
}

void create_entry(proc_t *proc)
{
	int room = rand() % count_rooms(proc->proom);
	int posx = proc->proom[room].pos1[0] + 2 +
	(rand() % (proc->proom[room].width + 1) - 1);
	int posy = proc->proom[room].pos1[1] + 2 +
	(rand() % (proc->proom[room].height + 1) - 1);

	proc->map[posy][posx] = 'E';
}

void create_leave(proc_t *proc)
{
	int room = rand() % count_rooms(proc->proom);
	int posx = proc->proom[room].pos1[0] + 2 +
	(rand() % (proc->proom[room].height + 1) - 1);
	int posy = proc->proom[room].pos1[1] + 2 +
	(rand() % (proc->proom[room].height + 1) - 1);

	if (proc->map[posy][posx] == 'E')
		proc->map[posy][posx] = 'B';
	else
		proc->map[posy][posx] = 'S';
}
