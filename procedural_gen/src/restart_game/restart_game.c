/*
** EPITECH PROJECT, 2018
** restart_game.c
** File description:
** file to stock all functions about restarting a game
*/

#include "my.h"
#include "../../include/procedural.h"

void create_char_map_restart(gage_t *gage)
{
	increment_proc_struct(gage->pvar, gage->proc);
	make_positions_proom(gage, gage->proc);
	for (int i = 0; gage->proc->proom[i] != NULL; i++) {
		make_holes(gage->proc->proom[i], gage->proc->map, i);
	}
	gage->proc->map = border_map(gage->pvar, gage->proc->map);
	create_entry(gage->proc);
	create_leave(gage->proc);
	make_map_better(gage->proc->map);
	print_map(gage->proc->map);
}

void print_map(char **map)
{
	for (int y = 0; map[y] != NULL; y++) {
		for (int x = 0; map[y][x] != '\0'; x++) {
			my_putchar(map[y][x]);
			my_putchar(' ');
		}
		my_putchar('\n');
	}
}

void init_next_level(gage_t *gage)
{
	create_char_map_restart(gage);
	gage->proc->smap = create_sprite_map(gage, gage->proc->map);
	gage->proc->gman->player.pos = get_entry_pos(gage->proc);
	gage->proc->gman->player.acceleration.x = 0;
	gage->proc->gman->player.acceleration.y = 0;
	gage->proc->gman->player.nbr_frame.x = 0;
	gage->proc->gman->player.nbr_frame.y = 0;
	gage->proc->gman->dt = 1;
	reset_screen(gage->proc->minimap->f_minimap);
}

void draw_floor_restart(gage_t *gage)
{
	sfVector2f screen_center = gage->proc->gman->camera_pos;
	char *cur_level = int_to_str(gage->pvar->current_floor);
	char *level_string = my_strcat("Floor ", cur_level);
	sfFont *font = sfFont_createFromFile("ressources/OpenSans.ttf");
	sfText *next_level = sfText_create();

	screen_center.y -= 12;
	screen_center.x -= (my_strlen(level_string) * 12) / 2;
	sfText_setString(next_level, level_string);
	sfText_setFont(next_level, font);
	sfText_setCharacterSize(next_level, 24);
	sfText_setPosition(next_level, screen_center);
	fade_in_text(gage->proc->gman->window, next_level);
	init_next_level(gage);
	fade_out_text(gage->proc->gman->window, next_level);
	sfText_destroy(next_level);
	sfFont_destroy(font);
	free(cur_level);
	free(level_string);
}

void next_level_screen(gage_t *gage)
{
	free_dungeon(gage->proc);
	if (gage->pvar->current_floor < gage->pvar->max_floor) {
		gage->pvar->current_floor += 1;
	} else if (gage->pvar->current_floor < gage->pvar->max_floor) {
		gage->pvar->current_floor -= 1;
	} else {
		sfRenderWindow_close(gage->proc->gman->window);
		return;
	}
	draw_floor_restart(gage);
}
