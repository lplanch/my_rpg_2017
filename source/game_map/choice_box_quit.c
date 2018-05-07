/*
** EPITECH PROJECT, 2018
** choice_box_quit.c
** File description:
** choice_box_quit.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void choice_box_quit(st_rpg *s, char **tab, char *str, int compter)
{
	s->fi->nb_choice_pre = compter;
	s->fi->choice_cursor = 0;
	free_tab_withnull(tab);
	free(str);
}

int choice_box_check_quit(st_rpg *s, char **tab, char *str, int compter)
{
	if (my_strcmp(tab[s->fi->choice_cursor], "Rocky Cavern") == 0) {
		choice_box_quit(s, tab, str, compter);
		sfView_setCenter(s->fi->view, create_vector2f(960, 540));
		sfRenderWindow_setView(s->window, s->fi->view);
		return (dungeon_loop(s));
	}
	choice_box_quit(s, tab, str, compter);
	return (0);
}
