/*
** EPITECH PROJECT, 2018
** launch_dungeon.c
** File description:
** launch the dungeon game
*/

#include "my.h"
#include "my_rpg.h"

void draw_map_block(st_rpg *rpg, int y)
{
	for (int x = 0; rpg->proc.map[y][x] != '\0'; x++) {
		if (rpg->proc.smap[y][x].sprite != NULL) {
			sfRenderWindow_drawSprite(rpg->window,
			rpg->proc.smap[y][x].sprite, NULL);
		}
	}
}

int draw_sprites_map(st_rpg *rpg)
{
	for (int y = 0; rpg->proc.map[y] != NULL; y++)
		draw_map_block(rpg, y);
	sfRenderWindow_drawSprite(rpg->window, rpg->player.obj->sprite, NULL);
	verify_minimap(rpg);
	verify_inventory(rpg);
	verify_fast_inventory(rpg);
	return (1);
}

int update_sprite(st_rpg *rpg)
{
	sfVector2f player_pos;

	rpg->player.last_pos = rpg->player.obj->pos;
	update_player_position(rpg);
	rpg->origin.x = rpg->player.obj->pos.x - WIDTH / 4;
	rpg->origin.y = rpg->player.obj->pos.y - HEIGHT / 4;
	player_pos.x = rpg->player.obj->pos.x -
	(rpg->player.obj->rect.width / 2);
	player_pos.y = rpg->player.obj->pos.y -
	(rpg->player.obj->rect.height / 2);
	sfSprite_setPosition(rpg->player.obj->sprite, player_pos);
	update_camera_position(rpg);
	update_minimap(rpg);
	rpg->proc.gman.time = sfClock_restart(rpg->proc.gman.clock);
	rpg->proc.gman.dt = sfTime_asSeconds(rpg->proc.gman.time);
	return (1);
}

int launch_dungeon_game(st_rpg *rpg)
{
	int done = 0;

	init_dungeon_game(rpg);
	while (!done) {
		verif_input_map(rpg);
		update_sprite(rpg);
		sfRenderWindow_clear(rpg->window, rpg->proc.pvar.background);
		draw_sprites_map(rpg);
		sfRenderWindow_display(rpg->window);
		done = verify_exit_player(rpg);
	}
	return (1);
}
