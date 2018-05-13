/*
** EPITECH PROJECT, 2018
** dungeon_preset_boss.c
** File description:
** file to stock all functions about dungeon preset for boss
*/

#include "my.h"
#include "my_rpg.h"

void dungeon_boss_samy(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl1_tiles.png";
	hey->map_width = 50;
	hey->map_height = 50;
	hey->max_room_s = 12;
	hey->min_room_s = 12;
	hey->nbr_rooms = 6;
	hey->current_floor = 0;
	hey->max_floor = 1;
	hey->background.r = 20;
	hey->background.g = 11;
	hey->background.b = 40;
	hey->background.a = 255;
	hey->min_enemies = 0;
	hey->max_enemies = 1;
	hey->dungeon_music =
	"ressources/audio/music_dungeon2.ogg";
	hey->volume = 50;
}
