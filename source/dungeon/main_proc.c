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
	pvar->texture_path = "ressources/dungeon_lvl1_tiles.png";
	pvar->map_width = 80;
	pvar->map_height = 45;
	pvar->max_room_s = 15;
	pvar->min_room_s = 9;
	pvar->nbr_rooms = 18;
	pvar->current_floor = 0;
	pvar->max_floor = 10;
	pvar->background.r = 20;
	pvar->background.g = 11;
	pvar->background.b = 40;
	pvar->background.a = 255;
}

int launch_dungeon(st_rpg *rpg)
{
	make_proc_variables(&rpg->proc.pvar);
	map_creation(&rpg->proc);
	rpg->proc.smap = create_sprite_map(&rpg->proc, rpg->proc.map);
	launch_dungeon_game(rpg);
	return (0);
}
