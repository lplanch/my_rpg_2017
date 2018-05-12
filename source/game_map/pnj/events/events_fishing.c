/*
** EPITECH PROJECT, 2018
** events_fishing.c
** File description:
**
*/

#include "my.h"
#include "my_rpg.h"

void launch_fishing_instance(st_rpg *rpg)
{

}

void verify_choice_fishing(st_rpg *rpg, char **tab, char *str, int compter)
{
	if (!my_strcmp(tab[rpg->fi->choice_cursor], "Of course !")) {
		choice_box_quit(rpg, tab, str, compter);
		launch_fishing_instance(rpg);
	}
}
