/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/
#include "game_map.h"
#include "my_rpg.h"
#include "my.h"

void create_dungeon_loop(st_rpg *s)
{
	s->dungeon_music.music =
	create_music(s->s_music, s->proc.pvar.dungeon_music);
	sfMusic_play(s->dungeon_music.music);
	sfMusic_setLoop(s->dungeon_music.music, 1);
	create_player(s);
	create_weapon(s);
	map_creation(&s->proc);
	s->proc.smap = create_sprite_map(&s->proc, s->proc.map);
	create_items_list(s);
	init_dungeon_game(s);
	create_main_fight(s);
	create_icons(s);
	create_class(s);
	create_dmg_show(s);
	create_life_bar(s);
	generate_enemies(s);
	create_main_particles(s);
	set_shader(s);
}

void destroy_dungeon_loop(st_rpg *s)
{
	create_dmg_show(s);
	destroy_class(s);
	destroy_icons(s);
	destroy_life_bar(s);
	destroy_enemies(s);
	destroy_main_fight(s);
	destroy_dungeon_shader(s);
	destroy_main_particles(s);
	if (s->returnv != 0)
		free_dungeon(s, &s->proc);
	sfFont_destroy(s->inv.inventory_font);
	sfMusic_destroy(s->dungeon_music.music);
	sfMusic_play(s->fi->music.music);
	s->fi->map_status = 0;
}

void update_origin(st_rpg *s)
{
	origin_life_bar(s);
	origin_icons(s);
}

void update_dungeon_loop(st_rpg *s)
{
	update_dmg_show(s);
	update_pos_weapon(s);
	update_bars(s);
	update_icons_cd(s);
	update_fight(s);
	apply_projectiles(s);
	update_enemies(s);
	update_origin(s);
	update_sprite(s);
	if (!s->f.panim)
		player_animation(s);
	update_class(s);
	update_particles(s);
	update_item_ground(s);
}

void stop_player(st_rpg *s)
{
	s->player.acceleration.x = 0;
	s->player.acceleration.y = 0;
	s->player.nbr_frame.x = 0;
	s->player.nbr_frame.y = 0;
}

void display_dungeon(st_rpg *s)
{
	sfRenderWindow_clear(s->window, s->proc.pvar.background);
	for (int y = 0; s->proc.map[y] != NULL; y++)
		draw_map_block(s, y);
	draw_item_on_ground(s);
	display_player(s);
	display_enemies(s);
	display_class(s);
	display_icons(s);
	display_life_bar(s);
	display_dmg_show(s);
	display_main_particles(s);
	verify_minimap(s);
	verify_inventory(s);
	verify_fast_inventory(s);
}

int dungeon_events(st_rpg *s)
{
	sfEvent event;

	if (s->f.cast != 2) {
		verify_x_movement(s);
		verify_y_movement(s);
	}
	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyEscape)) {
			stop_player(s);
			return (pause_main(s));
		} if (event.type == sfEvtClosed) {
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
	while (sfRenderWindow_isOpen(s->window)) {
		if (dungeon_events(s))
			break;
		if (!s->f.cast && !s->inv.is_open)
			launch_spells(s);
		update_dungeon_loop(s);
		display_dungeon(s);
		sfRenderWindow_display(s->window);
		if (verify_exit_player(s)) {
			s->returnv = 0;
			destroy_dungeon_loop(s);
			s->fi->camera_pos = 1;
			s->player.obj->pos.x = 3707;
			s->player.obj->pos.y = 3550;
			s->fi->dialog_box_isopen = 0;
			s->fi->var_choice = 0;
			s->fi->nb_choice_pre = 0;
			return (4);
		}
	}
	return (s->returnv);
}
