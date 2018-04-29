/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_dungeon_loop(st_rpg *s)
{
	srand((long)&launch_dungeon);
	make_proc_variables(&s->proc.pvar);
	map_creation(&s->proc);
	s->proc.smap = create_sprite_map(&s->proc, s->proc.map);
	init_dungeon_game(s);
	create_main_fight(s);
	create_icons(s);
	create_class(s);
	create_life_bar(s);
	create_mob_example(s);
}

void destroy_dungeon_loop(st_rpg *s)
{
	destroy_class(s);
	destroy_icons(s);
	destroy_life_bar(s);
	destroy_mob_example(s);
	destroy_player(s);
	destroy_main_fight(s);
	free_dungeon(&s->proc);
}

void update_origin(st_rpg *s)
{
	origin_life_bar();
}

void update_dungeon_loop(st_rpg *s)
{
	update_pos_weapon(s);
	update_class(s);
	update_bars(s);
	update_icons_cd(s);
	update_projectiles(s);
	update_effects(s);
	update_mob_example(s);
	update_sprite(s);
}

int dungeon_events(st_rpg *s)
{
	sfEvent event;

	verify_x_movement(s);
	verify_y_movement(s);
	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtKeyPressed &&
			sfKeyboard_isKeyPressed(sfKeyEscape))
			return (pause_main(s));
		if (event.type == sfEvtClosed) {
			s->returnv = 1;
			destroy_dungeon_loop(s);
			return (1);
		}
		verify_other_input(event, s);
	}
	return (0);
}

int dungeon_loop(st_rpg *s)
{
	create_dungeon_loop(s);
	while (sfRenderWindow_isOpen(s->window)) {
		if (dungeon_events(s))
			break;
		if (!s->f.cast)
			launch_spells(s);
		update_dungeon_loop(s);
		display_fight(s);
		sfRenderWindow_display(s->window);
		if (verify_exit_player(s)) {
			destroy_dungeon_loop(s);
			return (0);
		}
	}
	return (s->returnv);
}
