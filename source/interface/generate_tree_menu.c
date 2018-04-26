/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my_rpg.h"
#include "my.h"

void generate_tree_menu_mouse(st_rpg *s)
{
	for (int i = 0; i != 3; i += 1) {
		s->treem.pas[i] = create_object(get_tree_path(s, 0, i + 1),
		create_vector2f(1535 + i * 125, 90),
		create_rect(0, 0, 128, 128), 0);
		sfSprite_setScale(s->treem.pas[i]->sprite,
		create_vector2f(0.5, 0.5));
		s->treem.m2[i] = create_object(get_tree_path(s, 1, i + 1),
		create_vector2f(1535 + i * 125, 180),
		create_rect(0, 0, 128, 128), 0);
		sfSprite_setScale(s->treem.m2[i]->sprite,
		create_vector2f(0.5, 0.5));
	}
	tree_set_rects(s);
}

void generate_tree_menu_spell(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1)
		s->treem.lock[i] = create_object("images/lock.png",
		create_vector2f(0, 0), create_rect(0, 0, 38, 38), 0);
	update_tree_pos(s);
	for (int i = 0; i != 2; i += 1) {
			s->treem.e[i] = create_object(get_tree_path(s, 2, i + 1),
			create_vector2f(1596 + i * 124, 270),
			create_rect(0, 0, 128, 128), 0);
			sfSprite_setScale(s->treem.e[i]->sprite,
			create_vector2f(0.5, 0.5));
			s->treem.r[i] = create_object(get_tree_path(s, 3, i + 1),
			create_vector2f(1596 + i * 124, 360),
			create_rect(0, 0, 128, 128), 0);
			sfSprite_setScale(s->treem.r[i]->sprite,
			create_vector2f(0.5, 0.5));
	}
}

void generate_tree_menu_pas(st_rpg *s)
{
	char *temp;

	s->treem.status = -1;
	s->treem.spells = get_spinfo(s);
	s->treem.window = create_object("images/pause_window.png",
	create_vector2f(1490, 30), create_rect(0, 0, 400, 600), 0);
	s->treem.classe = create_button(get_class_string(s
	->player.cdata.classe), create_object("images/pictoclass.png",
	create_vector2f(1510, 45), create_rect(0, 32 * s->player.cdata.classe,
	32, 32), 0), sfWhite, 30);
	sfText_setPosition(s->treem.classe->text->text,
	create_vector2f(1555, 45));
	temp = int_to_str(s->player.tree.skillp);
	s->treem.skillp = create_text(my_strcat("SP : ", temp),
	create_vector2f(1720, 45), "fonts/button.ttf");
	free(temp);
	for (int i = 0; i != 4; i += 1) {
		s->treem.select[i] = create_object("images/select.png",
		create_vector2f(0, 0), create_rect(0, 0, 64, 64), 0);
	}
}

void generate_tree_menu(st_rpg *s)
{
	generate_tree_menu_pas(s);
	generate_tree_menu_spell(s);
	generate_tree_menu_mouse(s);
	s->treem.sp[0] = create_text("NAME",
	create_vector2f(1520, 450), "fonts/button.ttf");
	sfText_setCharacterSize(s->treem.sp[0]->text, 20);
	s->treem.sp[1] = create_text("DESCRIPTION",
	create_vector2f(1520, 480), "fonts/button.ttf");
	sfText_setCharacterSize(s->treem.sp[1]->text, 16);
	s->treem.sp[2] = create_text("LOCKSTAGE",
	create_vector2f(1520, 510), "fonts/button.ttf");
	sfText_setCharacterSize(s->treem.sp[2]->text, 25);
	s->treem.sp[3] = create_text("Click again to Unlock",
	create_vector2f(1520, 550), "fonts/button.ttf");
	sfText_setCharacterSize(s->treem.sp[3]->text, 20);
}
