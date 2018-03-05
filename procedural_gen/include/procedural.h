/*
** EPITECH PROJECT, 2018
** procedural.h
** File description:
** ezwin
*/

typedef struct proc_room
{
	int pos[2];
	int width;
	int height;
} proom_t;

typedef struct proc_gen
{
	proom_t **proc_room;
	char **map;
	int width;
	int height;
	int nbr_room;
} proc_t;

int map_creation(int width, int height, int nbr_room);
