/*
** EPITECH PROJECT, 2018
** make_map_better.c
** File description:
** file to stock all functions about making map better
*/

#include "my.h"
#include "../../include/procedural.h"

void parse_wall_map(char **map, int y, int x)
{
	if (y > 1 && x > 1 && x < my_strlen(map[y]) && y < count_lines(map) - 1) {
		if (map[y][x] == '#' && map[y + 1][x] == ' ' &&
		map[y][x - 1] != ' ' && map[y][x + 1] != ' ')
			map[y][x] = 'T';
		if (map[y][x] == '#' && map[y - 1][x] == ' ' &&
		map[y][x - 1] != ' ' && map[y][x + 1] != ' ')
			map[y][x] = 'V';
		if (map[y][x] == '#' && map[y][x - 1] == ' ' &&
		map[y - 1][x] != ' ' && map[y + 1][x] != ' ')
			map[y][x] = 'R';
		if (map[y][x] == '#' && map[y][x + 1] == ' ' &&
		map[y - 1][x] != ' ' && map[y + 1][x] != ' ')
			map[y][x] = 'L';
	}
}

int many_around(char **map, int x, int y)
{
	int result = 0;

	if (map[y][x + 1] == ' ')
		result += 1;
	if (map[y][x - 1] == ' ')
		result += 1;
	if (map[y + 1][x] == ' ')
		result += 1;
	if (map[y - 1][x] == ' ')
		result += 1;
	if (map[y + 1][x + 1] == ' ')
		result += 1;
	if (map[y - 1][x - 1] == ' ')
		result += 1;
	if (map[y - 1][x + 1] == ' ')
		result += 1;
	if (map[y + 1][x - 1] == ' ')
		result += 1;
	return (result);
}

void parse_corner_map(char **map, int y, int x)
{
	if (y > 1 && x > 1 && x < my_strlen(map[y]) &&
	y < count_lines(map) - 1) {
		if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
		map[y - 1][x - 1] == ' ')
			map[y][x] = 'N';
		if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
		map[y - 1][x + 1] == ' ')
			map[y][x] = 'W';
		if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
		map[y + 1][x - 1] == ' ')
			map[y][x] = 'P';
		if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
		map[y + 1][x + 1] == ' ')
			map[y][x] = 'A';
	}
}

void parse_deadlock_map(char **map, int y, int x)
{
	if (y > 1 && x > 1 && x < my_strlen(map[y]) &&
	y < count_lines(map) - 1) {
		if (map[y][x] == '#' && map[y][x - 1] == ' ' &&
		map[y][x + 1] == ' ' && map[y + 1][x] == ' ' &&
		map[y - 1][x - 1] == ' ' && map[y - 1][x + 1] == ' ')
			map[y][x] = 'Y';
		if (map[y][x] == '#' && map[y][x - 1] == ' ' &&
		map[y][x + 1] == ' ' && map[y + 1][x] == ' ' &&
		map[y + 1][x - 1] == ' ' && map[y + 1][x + 1] == ' ')
			map[y][x] = 'H';
		if (map[y][x] == '#' && many_around(map, x, y) == 7 &&
		map[y][x - 1] != ' ')
			map[y][x] = 'G';
		if (map[y][x] == '#' && many_around(map, x, y) == 7 &&
		map[y][x + 1] != ' ')
			map[y][x] = 'J';
	}
}

void make_map_better(char **map)
{
	for (int y = 0; map[y] != NULL; y++) {
		for (int x = 0; map[y][x] != '\0'; x++) {
			parse_wall_map(map, y, x);
			parse_corner_map(map, y, x);
			parse_deadlock_map(map, y, x);
		}
	}
}
