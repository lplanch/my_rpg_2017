/*
** EPITECH PROJECT, 2018
** launch_dungeon.c
** File description:
** launch the dungeon game
*/

#include "my.h"
#include "../../include/procedural.h"

int draw_sprites_map(gage_t *gage, proc_t *proc)
{
	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++) {
			if (proc->smap[y][x] != NULL) {
				sfRenderWindow_drawSprite(proc->gman->window,
				proc->smap[y][x]->sprite, NULL);
			}
		}
	}
	sfRenderWindow_drawSprite(proc->gman->window,
	proc->gman->player.sprite, NULL);
	verify_minimap(gage);
	verify_inventory(proc->gman);
	return (1);
}

int update_sprite(proc_t *proc)
{
	sfVector2f player_pos;

	proc->gman->player.last_pos = proc->gman->player.pos;
	update_player_position(proc);
	player_pos.x = proc->gman->player.pos.x -
	(proc->gman->player.rect.width / 2);
	player_pos.y = proc->gman->player.pos.y -
	(proc->gman->player.rect.height / 2);
	sfSprite_setPosition(proc->gman->player.sprite, player_pos);
	update_camera_position(proc);
	update_minimap(proc);
	proc->gman->time = sfClock_restart(proc->gman->clock);
	proc->gman->dt = sfTime_asSeconds(proc->gman->time);
	return (1);
}

int launch_dungeon_game(gage_t *gage)
{
	gage->proc->gman = init_dungeon_game(gage->proc, gage);
	while (sfRenderWindow_isOpen(gage->proc->gman->window)) {
		verif_input_map(gage);
		update_sprite(gage->proc);
		sfRenderWindow_clear(gage->proc->gman->window,
		gage->pvar->background);
		draw_sprites_map(gage, gage->proc);
		sfRenderWindow_display(gage->proc->gman->window);
		verify_exit_player(gage);
	}
	free_gage_game(gage);
	return (1);
}
