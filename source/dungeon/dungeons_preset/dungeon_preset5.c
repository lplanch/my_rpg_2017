/*
** EPITECH PROJECT, 2018
** dungeon_preset5.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

void dungeon5(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl7_tiles.png";
	hey->map_width = 80;
	hey->map_height = 45;
	hey->max_room_s = 20;
	hey->min_room_s = 15;
	hey->nbr_rooms = 100;
	hey->current_floor = 2;
	hey->max_floor = 2;
	hey->background.r = 20;
	hey->background.g = 11;
	hey->background.b = 40;
	hey->background.a = 255;
	hey->min_enemies = 15;
	hey->max_enemies = 30;
	hey->dungeon_music =
	"ressources/audio/music_dungeon.ogg";
	hey->volume = 50;
}
