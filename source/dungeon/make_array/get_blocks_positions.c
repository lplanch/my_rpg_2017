/*
** EPITECH PROJECT, 2018
** get_blocks_positions.c
** File description:
** get block positions on the map
*/

#include "my.h"
#include "my_rpg.h"

sfVector2f verify_entry_pos(proc_t *proc, int y, int x)
{
	sfVector2f result = {0, 0};

	if (proc->map[y][x] == 'E' || proc->map[y][x] == 'B') {
		result.y = y * 48;
		result.x = x * 48;
	}
	return (result);
}

sfVector2f get_entry_pos(proc_t *proc)
{
	sfVector2f result = {0, 0};

	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++)
			result = verify_entry_pos(proc, y, x);
	}
	return (result);
}

sfVector2f verify_exit_pos(proc_t *proc, int y, int x)
{
	sfVector2f result = {0, 0};

	if (proc->map[y][x] == 'S' || proc->map[y][x] == 'B') {
		result.y = y * 48;
		result.x = x * 48;
	}
	return (result);
}

sfVector2f get_exit_pos(proc_t *proc)
{
	sfVector2f result = {0, 0};

	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++)
			result = verify_exit_pos(proc, y, x);
	}
	return (result);
}
