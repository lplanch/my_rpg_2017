/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

int left_clicked_on_pause(st_rpg *s, sfEvent event)
{
	int max = 5;

	for (int i = 0; i != max; i += 1) {
		if (event.type == sfEvtMouseButtonPressed &&
			sfMouse_isButtonPressed(sfMouseLeft) &&
			mouse_in_origin(s, s->pausm.button[i]->obj))
			return (1);
	}
	return (0);
}

void pause_menu_manage_cursor_events(st_rpg *s, sfEvent event)
{
	int max = 5;

	if (event.type == sfEvtKeyPressed) {
		if (((sfKeyboard_isKeyPressed(sfKeyS) ||
			sfKeyboard_isKeyPressed(sfKeyDown)) &&
			s->pausm.option < max - 1))
			s->pausm.option += 1;
		else if ((sfKeyboard_isKeyPressed(sfKeyZ) ||
			sfKeyboard_isKeyPressed(sfKeyUp)) &&
			s->pausm.option > 0)
			s->pausm.option -= 1;
	}
	for (int i = 0; i != max; i += 1) {
		if (mouse_in_origin(s, s->pausm.button[i]->obj))
			s->pausm.option = i;
	}
}

int launch_pause_menu(st_rpg *s, sfEvent event)
{
	if ((event.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyE)
	|| sfKeyboard_isKeyPressed(sfKeyReturn)))
	|| left_clicked_on_pause(s, event)) {
		return (which_pause_menu(s));
	}
	return (0);
}

int go_back(st_rpg *s)
{
	if (!s->pausm.menu) {
		destroy_pause_menu(s);
		s->returnv = 0;
		return (1);
	} else {
		s->pausm.menu = 0;
		return (0);
	}
}

int event_pause_menu(st_rpg *s)
{
	int a = 0;
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		which_update(s);
		if (s->pausm.menu == 0)
			pause_menu_manage_cursor_events(s, event);
		if (event.type == sfEvtClosed) {
			s->returnv = 1;
			destroy_pause_menu(s);
			return (1);
		} if (event.type == sfEvtKeyPressed &&
		(sfKeyboard_isKeyPressed(sfKeyEscape))) {
			return (go_back(s));
		} if ((a = launch_pause_menu(s, event)) != 0) {
			s->returnv = a;
			return (1);
		}
	}
	return (0);
}

void set_origin_map(st_rpg *s)
{
	if (!s->fi->map_status) {
		s->origin.x = s->fi->camera.x - 960;
		s->origin.y = s->fi->camera.y - 540;
	}
}

int pause_main(st_rpg *s)
{
	set_origin_map(s);
	generate_pause_menu(s);
	while (sfRenderWindow_isOpen(s->window)) {
		if (event_pause_menu(s)) {
			return (s->returnv);
		} if (s->fi->map_status)
			display_dungeon(s);
		else
			draw_all(s);
		set_colors_pause(s);
		update_cursor_pos_pause(s);
		which_display(s);
		sfRenderWindow_display(s->window);
	}
	return (0);
}
