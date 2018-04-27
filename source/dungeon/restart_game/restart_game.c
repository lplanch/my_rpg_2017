/*
** EPITECH PROJECT, 2018
** restart_game.c
** File description:
** file to stock all functions about restarting a game
*/

#include "my.h"
#include "my_rpg.h"

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

void create_char_map_restart(proc_t *proc)
{
	increment_proc_struct(&proc->pvar, proc);
	make_positions_proom(proc);
	for (int i = 0; proc->proom[i].last == 0; i++)
		make_holes(&proc->proom[i], proc->map);
	proc->map = border_map(&proc->pvar, proc->map);
	create_entry(proc);
	create_leave(proc);
	make_map_better(proc->map);
	print_map(proc->map);
}

void init_next_level(st_rpg *rpg)
{
	char *cur_level = int_to_str(rpg->proc.pvar.current_floor);
	char *level_string = my_strcat("Floor ", cur_level);

	create_char_map_restart(&rpg->proc);
	rpg->proc.smap = create_sprite_map(&rpg->proc, rpg->proc.map);
	rpg->player.obj->pos = get_entry_pos(&rpg->proc);
	rpg->player.acceleration.x = 0;
	rpg->player.acceleration.y = 0;
	rpg->player.nbr_frame.x = 0;
	rpg->player.nbr_frame.y = 0;
	rpg->proc.gman.dt = 1;
	reset_screen(rpg->proc.minimap.f_minimap);
	sfText_setString(rpg->proc.minimap.current_level_text, level_string);
	free(cur_level);
	free(level_string);
}

void draw_floor_restart(st_rpg *rpg)
{
	sfVector2f screen_center = rpg->proc.gman.camera_pos;
	char *cur_level = int_to_str(rpg->proc.pvar.current_floor);
	char *level_string = my_strcat("Floor ", cur_level);
	sfFont *font = sfFont_createFromFile("ressources/OpenSans.ttf");
	sfText *next_level = sfText_create();

	screen_center.y -= 12;
	screen_center.x -= (my_strlen(level_string) * 12) / 2;
	sfText_setString(next_level, level_string);
	sfText_setFont(next_level, font);
	sfText_setCharacterSize(next_level, 24);
	sfText_setPosition(next_level, screen_center);
	fade_in_text(rpg->window, next_level);
	init_next_level(rpg);
	fade_out_text(rpg->window, next_level);
	sfText_destroy(next_level);
	sfFont_destroy(font);
	free(cur_level);
	free(level_string);
}

int next_level_screen(st_rpg *rpg)
{
	free_dungeon(&rpg->proc);
	if (rpg->proc.pvar.current_floor < rpg->proc.pvar.max_floor) {
		rpg->proc.pvar.current_floor += 1;
	} else if (rpg->proc.pvar.current_floor < rpg->proc.pvar.max_floor) {
		rpg->proc.pvar.current_floor -= 1;
	} else
		return (1);
	draw_floor_restart(rpg);
	return (0);
}
