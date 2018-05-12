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

void update_status_menu(st_rpg *s)
{
	int i = 0;

	if (s->statm.show == 6) {
		for (i = 0; i != 6; i += 1) {
			if (mouse_in_origin(s, s->statm.stats[i]->obj))
				s->statm.show = i;
		}
		if (s->statm.show != 6) {
			sfText_setString(s->statm.stats[s->statm.show]->text
			->text, get_stat_string(s->statm.show));
		}
	} else if (s->statm.show != 6) {
		if (!mouse_in_origin(s, s->statm.stats[s->statm.show]->obj)) {
			my_set_string(s->statm.stats[s->statm.show]->text
			->text, get_stat_value(s, s->statm.show));
			s->statm.show = 6;
		}
	}
}

void set_tree_positions(st_rpg *s)
{
	int x = s->origin.x + 1535;

	sfSprite_setPosition(s->treem.select[0]->sprite,
	create_vector2f(x + s->player.tree.passive * 125, s->origin.y + 90));
	sfSprite_setPosition(s->treem.select[1]->sprite,
	create_vector2f(x + s->player.tree.spell1 * 125, s->origin.y + 180));
	sfSprite_setPosition(s->treem.select[2]->sprite,
	create_vector2f(x + 61 +
	s->player.tree.spell2 * 124, s->origin.y + 270));
	sfSprite_setPosition(s->treem.select[3]->sprite,
	create_vector2f(x + 61 +
	s->player.tree.spell3 * 124, s->origin.y + 360));
}
