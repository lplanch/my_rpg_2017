/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

char *get_stat_value(st_rpg *s, int i)
{
	switch (i) {
	case 0 :
		return (int_to_str(s->player.stat->pvm));
	case 1 :
		return (int_to_str(s->player.stat->frc));
	case 2 :
		return (int_to_str(s->player.stat->def));
	case 3 :
		return (int_to_str(s->player.stat->prc));
	case 4 :
		return (int_to_str(s->player.stat->vit));
	case 5 :
		return (int_to_str(s->player.stat->cha));
	}
	return (NULL);
}

char *get_stat_string(int i)
{
	switch (i) {
	case 0 :
		return ("Max Health");
	case 1 :
		return ("Strength");
	case 2 :
		return ("Resistance");
	case 3 :
		return ("Precision");
	case 4 :
		return ("Speed");
	case 5 :
		return ("Chance");
	}
	return ("SAMY");
}

void my_set_string(sfText *text, char *str)
{
	sfText_setString(text, str);
	free(str);
}

void update_menu_stat_mouse_over(st_rpg *s)
{
	int i = 0;

	if (s->statm.shot == 1 && s->statm.show == 6) {
		for (i = 0; i != 6; i += 1) {
			if (mouse_in_object(s->statm.stats[i]->obj, s->window))
				s->statm.show = i;
		}
		if (s->statm.show != 6) {
			sfText_setString(s->statm.stats[s->statm.show]->text
			->text, get_stat_string(s->statm.show));
		}
	} else if (s->statm.shot == 1 && s->statm.show != 6) {
		if (!mouse_in_object(s->statm.stats[s->statm.show]->obj,
		s->window)) {
			my_set_string(s->statm.stats[s->statm.show]->text
			->text, get_stat_value(s, s->statm.show));
			s->statm.show = 6;
		}
	}
}

char *get_class_string(int i)
{
	switch (i) {
	case 0 :
		return ("Archer");
	case 1 :
		return ("Gunner");
	case 2 :
		return ("Rogue");
	case 3 :
		return ("Warrior");
	}
	return (NULL);
}

void destroy_status_menu(st_rpg *s)
{
	s->statm.shot = 0;
	destroy_object(s->statm.window);
	destroy_object(s->statm.face);
	destroy_button(s->statm.classe);
	destroy_text(s->statm.name);
	destroy_text(s->statm.lvl);
	destroy_text(s->statm.exp);
	for (int i = 0; i != 6; i += 1) {
		destroy_button(s->statm.stats[i]);
	}
}

void display_status_menu(st_rpg *s)
{
	if (s->statm.shot == 1) {
		sfRenderWindow_drawSprite(s->window, s->statm.window->sprite,
		NULL);
		sfRenderWindow_drawSprite(s->window, s->statm.face->sprite,
		NULL);
		sfRenderWindow_drawText(s->window, s->statm.name->text,
		NULL);
		sfRenderWindow_drawText(s->window, s->statm.lvl->text, NULL);
		sfRenderWindow_drawText(s->window, s->statm.exp->text, NULL);
		display_button(s->window, s->statm.classe);
		for (int i = 0; i != 6; i += 1) {
			display_button(s->window, s->statm.stats[i]);
		}
	}
}

void generate_status_menu(st_rpg *s)
{
	s->statm.shot = 1;
	char *temp;

	s->statm.window = create_object("images/pause_window.png",
	create_vector2f(1490, 30), create_rect(0, 0, 400, 600), 0);
	s->statm.face = create_object("images/heroface.png",
	create_vector2f(1500, 40),
	create_rect(0, s->player.cdata.sex * 100, 100, 100), 0);
	s->statm.name = create_text(s->player.cdata.name, create_vector2f(1620,
	50), "fonts/button.ttf");
	temp = int_to_str(s->player.stat->lvl);
	s->statm.lvl = create_text(my_strcat("Level ", temp),
	create_vector2f(1525, 150), "fonts/button.ttf");
	free(temp);
	temp = int_to_str(s->player.stat->exp);
	s->statm.exp = create_text(my_strcat(temp, " / 100 XP"),
	create_vector2f(1525, 200), "fonts/button.ttf");
	free(temp);
	s->statm.classe = create_button(get_class_string(s
	->player.cdata.classe), create_object("images/pictoclass.png",
	create_vector2f(1620, 100), create_rect(0, 32 * s->player.cdata.classe,
	32, 32), 0), sfWhite, 30);
	for (int i = 0; i != 6; i += 1) {
		s->statm.stats[i] = create_button(get_stat_value(s, i),
		create_object("images/pictostat.png",
		create_vector2f(1540, 300 + i * 50), create_rect(0, i * 32, 32,
		32), 0), sfWhite, 30);
		sfText_setPosition(s->statm.stats[i]->text->text,
		create_vector2f(1590, 300 + i * 50));
		sfFont_destroy(s->statm.stats[i]->text->font);
		s->statm.stats[i]->text->font =
		sfFont_createFromFile("fonts/bars.otf");
		sfText_setFont(s->statm.stats[i]->text->text,
		s->statm.stats[i]->text->font);
	}
	sfText_setPosition(s->statm.classe->text->text,
	create_vector2f(1660, 100));
}
