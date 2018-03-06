/*
** EPITECH PROJECT, 2018
** procedural.h
** File description:
** ezwin
*/

#include <math.h>
#include <time.h>

#define MIN(a, b) ((a < b)? a : b)
#define MAX(a, b) ((a > b)? a : b)

static unsigned int map_width = 80;
static unsigned int map_height = 45;
static unsigned int max_room_s = 13;
static unsigned int min_room_s = 6;
static unsigned int nbr_rooms = 9;

typedef struct proc_room
{
	int pos1[2];
	int pos2[2];
	int width;
	int height;
	int center[2];
} proom_t;

typedef struct proc_gen
{
	proom_t **proom;
	char **map;
} proc_t;

proc_t *map_creation(void);
void make_positions_proom(proc_t *proc);
void make_holes(proom_t *proom, char **map, int i);

//CORRIDORS
void v_corridor(char **map, int y1, int y2, int x);
void h_corridor(char **map, int x1, int x2, int y);
void make_corridors(proc_t *proc, int length);
