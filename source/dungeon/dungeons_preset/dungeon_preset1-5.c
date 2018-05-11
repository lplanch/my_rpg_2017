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
	hey->max_room_s = 12;
	hey->min_room_s = 12;
	hey->nbr_rooms = 1;
	hey->current_floor = 0;
	hey->max_floor = 1;
	hey->background.r = 20;
	hey->background.g = 11;
	hey->background.b = 40;
	hey->background.a = 255;
	hey->min_enemies = 1;
	hey->max_enemies = 2;
	hey->dungeon_music =
	"ressources/audio/music_dungeon2.ogg";
	hey->volume = 50;
}

void dungeon2(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl2_tiles.png";
	hey->map_width = 80;
	hey->map_height = 45;
	hey->max_room_s = 9;
	hey->min_room_s = 5;
	hey->nbr_rooms = 100;
	hey->current_floor = 0;
	hey->max_floor = 3;
	hey->background.r = 20;
	hey->background.g = 11;
	hey->background.b = 40;
	hey->background.a = 255;
	hey->min_enemies = 3;
	hey->max_enemies = 20;
	hey->dungeon_music =
	"ressources/audio/music_water_dungeon.ogg";
	hey->volume = 50;
}

void dungeon3(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl3_tiles.png";
	hey->map_width = 80;
	hey->map_height = 45;
	hey->max_room_s = 20;
	hey->min_room_s = 15;
	hey->nbr_rooms = 100;
	hey->current_floor = 0;
	hey->max_floor = 0;
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

void dungeon3_2(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl3_tiles.png";
	hey->map_width = 80;
	hey->map_height = 45;
	hey->max_room_s = 20;
	hey->min_room_s = 15;
	hey->nbr_rooms = 100;
	hey->current_floor = 2;
	hey->max_floor = 5;
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
