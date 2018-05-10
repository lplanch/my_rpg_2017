/*
** EPITECH PROJECT, 2018
** dungeon_preset1-5.c
** File description:
** dungeon_preset1-5.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void dungeon1(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl1_tiles.png";
	hey->map_width = 80;
	hey->map_height = 45;
	hey->max_room_s = 15;
	hey->min_room_s = 9;
	hey->nbr_rooms = 18;
	hey->current_floor = 0;
	hey->max_floor = 1;
	hey->background.r = 20;
	hey->background.g = 11;
	hey->background.b = 40;
	hey->background.a = 255;
	hey->min_enemies = 3;
	hey->max_enemies = 9;
}
