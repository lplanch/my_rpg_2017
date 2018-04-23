/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my_rpg.h"
#include "my.h"

void destroy_tree_menu(st_rpg *s)
{
	s->treem.shot = 0;
	destroy_object(s->treem.window);
	destroy_button(s->treem.classe);
	destroy_text(s->treem.skillp);
	for (int i = 0; i != 3; i += 1) {
		if (i != 2) {
			destroy_object(s->treem.e[i]);
			destroy_object(s->treem.r[i]);
		}
		destroy_object(s->treem.m2[i]);
		destroy_object(s->treem.pas[i]);
	}
}

void display_object(sfRenderWindow *window, g_object *object)
{
	sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

void display_tree_menu(st_rpg *s)
{
	if (s->treem.shot == 1) {
		sfRenderWindow_drawSprite(s->window, s->treem.window->sprite,
		NULL);
		sfRenderWindow_drawText(s->window, s->treem.skillp->text,
		NULL);
		display_button(s->window, s->treem.classe);
		for (int i = 0; i != 10; i += 1) {
			if (i != 2) {
				display_object(s->window, s->treem.e[i]);
				display_object(s->window, s->treem.r[i]);
			} if (i != 3) {
				display_object(s->window, s->treem.m2[i]);
				display_object(s->window, s->treem.pas[i]);
			} if (i != 4)
				display_object(s->window, s->treem.select[i]);
			if (s->player.tree.lock[i])
				display_object(s->window, s->treem.lock[i]);
		}
	}
}

char *get_spell_char(int i)
{
	switch (i) {
		case 0 :
			return ("p");
		case 1 :
			return ("m");
		case 2 :
			return ("e");
		case 3 :
			return ("r");
	}
	return ("NULL");
}

char *get_tree_path(st_rpg *s, int spell, int number)
{
	char *tmp;
	char *tmp2 = int_to_str(number);
	char *str = my_strcat("spells/", int_to_str(s->player.cdata.classe));

	tmp = my_strcat(str, "/");
	free(str);
	str = my_strcat(tmp, get_spell_char(spell));
	free(tmp);
	tmp = my_strcat(str, tmp2);
	free(str);
	free(tmp2);
	str = my_strcat(tmp, ".png");
	return (str);
}

void tree_set_rects(st_rpg *s)
{
	for (int i = 0; i != 3; i += 1) {
		s->treem.pas[i]->rect = create_rect(0, 0, 64, 64);
		s->treem.m2[i]->rect = create_rect(0, 0, 64, 64);
		if (i != 2) {
			s->treem.e[i]->rect = create_rect(0, 0, 64, 64);
			s->treem.r[i]->rect = create_rect(0, 0, 64, 64);
		}
	}
}

void update_tree_pos(st_rpg *s)
{
	sfSprite_setPosition(s->treem.select[0]->sprite,
	create_vector2f(1535 + s->player.tree.passive * 125, 90));
	sfSprite_setPosition(s->treem.select[1]->sprite,
	create_vector2f(1535 + s->player.tree.spell1 * 125, 180));
	sfSprite_setPosition(s->treem.select[2]->sprite,
	create_vector2f(1596 + s->player.tree.spell2 * 124, 270));
	sfSprite_setPosition(s->treem.select[3]->sprite,
	create_vector2f(1596 + s->player.tree.spell3 * 124, 360));
	for (int i = 0, dec = 0, m = 3, d = 0; i != 10; i += 1) {
		if (i > 5) {
			d = 61;
			m = 2;
			dec = -90;
		}
		sfSprite_setPosition(s->treem.lock[i]->sprite,
		create_vector2f(1535 + d + (i % m) * 125 + 13,
		90 + (i / m) * 90 + dec + 13));
	}
}

void update_tree_mouse(st_rpg *s, int i)
{
	if (mouse_in_object(s->treem.pas[i], s->window))
		s->player.tree.passive = i;
	if (mouse_in_object(s->treem.m2[i], s->window))
		s->player.tree.spell1 = i;
	if (i != 2) {
		if (mouse_in_object(s->treem.e[i], s->window))
			s->player.tree.spell2 = i;
		if (mouse_in_object(s->treem.r[i], s->window))
			s->player.tree.spell3 = i;
	}
}

void update_tree_menu(st_rpg *s)
{
	if (s->treem.shot == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
		for (int i = 0; i != 3; i += 1) {
			update_tree_mouse(s, i);
		}
		update_tree_pos(s);
	}
}

void generate_tree_menu(st_rpg *s)
{
	char *temp;

	s->treem.shot = 1;
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
	create_vector2f(1700, 45), "fonts/button.ttf");
	free(temp);
	for (int i = 0; i != 4; i += 1) {
		s->treem.select[i] = create_object("images/select.png",
		create_vector2f(0, 0), create_rect(0, 0, 64, 64), 0);
	} for (int i = 0; i != 10; i += 1)
		s->treem.lock[i] = create_object("images/lock.png",
		create_vector2f(0, 0), create_rect(0, 0, 38, 38), 0);
	update_tree_pos(s);
	for (int i = 0; i != 3; i += 1) {
		if (i != 2) {
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
