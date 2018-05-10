/*
** EPITECH PROJECT, 2018
** choice_box_quit.c
** File description:
** choice_box_quit.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void quit_game_for_dungeon(st_rpg *s)
{
	sfView_setCenter(s->fi->view, create_vector2f(960, 540));
	sfRenderWindow_setView(s->window, s->fi->view);
	sfMusic_stop(s->fi->music.music);
	//sfMusic_play(s->proc.dungeon_music);
	//sfMusic_setLoop(s->proc.dungeon_music, 1);
}

void choice_box_quit(st_rpg *s, char **tab, char *str, int compter)
{
	s->fi->nb_choice_pre = compter;
	s->fi->choice_cursor = 0;
	free_tab_withnull(tab);
	free(str);
}

int choice_box_check_quit(st_rpg *s, char **tab, char *str, int compter)
{
	if (my_strcmp(tab[s->fi->choice_cursor], "Rocky Cavern") == 0 &&
	s->fi->quests[1]->status != 0) {
		s->fi->num_dungeon = 1;
		choice_box_quit(s, tab, str, compter);
		quit_game_for_dungeon(s);
		return (launch_dungeon(s, &dungeon1));
	}
	if (my_strcmp(tab[s->fi->choice_cursor], "Chaotic Maze") == 0 &&
	s->fi->quests[4]->status != 0) {
		s->fi->num_dungeon = 1;
		choice_box_quit(s, tab, str, compter);
		quit_game_for_dungeon(s);
		return (dungeon_loop(s));
	}
	choice_box_quit(s, tab, str, compter);
	return (0);
}
