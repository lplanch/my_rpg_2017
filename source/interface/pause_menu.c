/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"
#include "game_map.h"

void destroy_pause_menu(st_rpg *s)
{
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->window, s->fi->view);
	destroy_tree_menu(s);
	destroy_status_menu(s);
	destroy_button(s->pausm.title);
	for (int i = 0; i != 5; i += 1)
		destroy_button(s->pausm.button[i]);
	destroy_object(s->pausm.cursor);
	destroy_object(s->pausm.window);
	destroy_text(s->pausm.saved);
}

void display_pause_menu(st_rpg *s)
{
	display_object(s->window, s->pausm.window);
	display_object(s->window, s->pausm.cursor);
	for (int i = 0; i != 5; i += 1)
		display_button(s->window, s->pausm.button[i]);
	display_button(s->window, s->pausm.title);
	if (s->pausm.opac > 0) {
		sfText_setColor(s->pausm.saved->text,
		(sfColor){255, 255, 255, s->pausm.opac});
		sfRenderWindow_drawText(s->window,
			s->pausm.saved->text, NULL);
			s->pausm.opac -= 2;
		}
}

void which_display(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {display_pause_menu, display_status_menu,
		display_tree_menu};

	(list[s->pausm.menu])(s);
}

void which_update(st_rpg *s)
{
	if (s->pausm.menu == 1)
		update_status_menu(s);
	if (s->pausm.menu == 2)
		update_tree_menu(s);
}

void generate_pause_menu(st_rpg *s)
{
	int x = s->origin.x;
	int y = s->origin.y;

	generate_tree_menu(s);
	generate_status_menu(s);
	s->pausm.option = 0;
	s->pausm.menu = 0;
	s->statm.show = 6;
	s->pausm.sens = 1;
	s->pausm.window = create_object("ressources/images/pause_window.png",
	create_vector2f(x + 1490, y + 30), create_rect(0, 0, 400, 600), 0);
	s->pausm.cursor =
	create_object("ressources/images/dialog_box/cursor.png",
	create_vector2f(x + 1500, y + 30), create_rect(0, 0, 24, 24), 0);
	s->pausm.title = create_button("Pause Menu",
	create_object("ressources/images/menu/tc.png", create_vector2f(x + 1540,
	y + 35),
	create_rect(0, 0, 300, 50), 0), sfWhite, 35);
	sfText_setPosition(s->pausm.title->text->text,
	create_vector2f(x + 1572, y + 38));
	s->pausm.button[0] = create_vbutton("Status Menu",
	create_vector2f(x + 1530, y + 120), sfWhite, 42);
	s->pausm.button[1] = create_vbutton("Skill Tree",
	create_vector2f(x + 1530, y + 200), sfWhite, 42);
	s->pausm.button[2] = create_vbutton("Save",
	create_vector2f(x + 1530, y + 280), sfWhite, 42);
	s->pausm.button[3] = create_vbutton("Back to menu",
	create_vector2f(x + 1530, y + 360), sfWhite, 42);
	s->pausm.button[4] = create_vbutton("Quit Game",
	create_vector2f(x + 1530, y + 440), sfWhite, 42);
	s->pausm.saved = create_text("Saved",
	create_vector2f(x + 1700, y + 300), "ressources/fonts/quests.otf");
	s->pausm.opac = 0;
}
