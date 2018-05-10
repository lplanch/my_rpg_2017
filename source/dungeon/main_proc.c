/*
** EPITECH PROJECT, 2018
** main_proc.c
** File description:
** main_proc file for procedural gen
*/

#include "my.h"
#include "my_rpg.h"

void make_proc_variables(proc_var_t *pvar)
{
	pvar->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl3_tiles.png";
	pvar->map_width = 80;
	pvar->map_height = 45;
	pvar->max_room_s = 15;
	pvar->min_room_s = 9;
	pvar->nbr_rooms = 18;
	pvar->current_floor = 0;
	pvar->max_floor = 1;
	pvar->background.r = 20;
	pvar->background.g = 11;
	pvar->background.b = 40;
	pvar->background.a = 255;
	pvar->min_enemies = 3;
	pvar->max_enemies = 9;
}

int launch_dungeon(st_rpg *rpg)
{
	rpg->fi->map_status = 1;
	make_proc_variables(&rpg->proc.pvar);
	return (dungeon_loop(rpg));
}
