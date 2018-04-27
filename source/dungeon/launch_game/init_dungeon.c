/*
** EPITECH PROJECT, 2018
** init_dungeon.c
** File description:
** file to stock all functions about init struct dungeon
*/

#include "my.h"
#include "my_rpg.h"

void init_player_movement(player_t *player)
{
	player->acceleration.x = 0;
	player->acceleration.y = 0;
	player->max_speed = 200;
	player->nbr_frame.x = 0;
	player->nbr_frame.y = 0;
}

void init_player_camera(st_rpg *rpg)
{
	rpg->proc.gman.camera_pos = rpg->player.obj->pos;
	rpg->proc.gman.camera =
	sfView_copy(sfRenderWindow_getDefaultView(rpg->window));
	sfView_zoom(rpg->proc.gman.camera, 0.5);
	sfView_setCenter(rpg->proc.gman.camera, rpg->proc.gman.camera_pos);
	sfRenderWindow_setView(rpg->window, rpg->proc.gman.camera);
}

void init_dungeon_game(st_rpg *rpg)
{
	init_player_movement(&rpg->player);
	init_player_camera(rpg);
	init_minimap(&rpg->proc);
	create_ingame_inventory(rpg);
	rpg->proc.gman.clock = sfClock_create();
	rpg->proc.gman.dt = 1.;
}
