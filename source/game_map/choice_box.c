/*
** EPITECH PROJECT, 2018
** dialog_box_menu.c
** File description:
** dialog_box_menu.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void destroy_choice_box(files_t *fi, int compter)
{
	int i = 0;

	while (i != compter) {
		destroy_button(fi->pnj[fi->nb_pnj].choice_box[i]);
		i++;
	}
	free(fi->pnj[fi->nb_pnj].choice_box);
	destroy_object(fi->pnj[fi->nb_pnj].cursor);
	destroy_object(fi->pnj[fi->nb_pnj].choice_box_edge[0]);
	destroy_object(fi->pnj[fi->nb_pnj].choice_box_edge[1]);
}

void up_cursor(files_t *fi)
{
	if (fi->choice_cursor > 0) {
		fi->pnj[fi->nb_pnj].cursor->pos.y -= 60;
		fi->var_choice--;
		fi->choice_cursor--;
	}
	sfSprite_setPosition(fi->pnj[fi->nb_pnj].cursor->sprite,
	fi->pnj[fi->nb_pnj].cursor->pos);
}

void down_cursor(files_t *fi, int compter)
{
	if (fi->choice_cursor < compter - 1) {
		fi->pnj[fi->nb_pnj].cursor->pos.y += 60;
		fi->var_choice++;
		fi->choice_cursor++;
	}
	sfSprite_setPosition(fi->pnj[fi->nb_pnj].cursor->sprite,
	fi->pnj[fi->nb_pnj].cursor->pos);
}

void choise_box_bouc(files_t *fi, int compter, char **tab)
{
	int a = 0;
	int i = 0;

	while (a != 1) {
		a = event_choice_box(fi, compter);
		draw_choice_menu(fi, compter);
	}
	while (tab[i] != NULL) {
		i++;
	}
	destroy_choice_box(fi, compter);
	fi->choice_cursor = 0;
}

void choice_box(files_t *fi, int fd)
{
	int compter = 0;
	char *str = get_next_line(fd);
	char **tab = my_calloc(sizeof(char*) * 1);

	tab = remalloc_tab(tab, str);
	while (1) {
		free(str);
		str = get_next_line(fd);
		if (my_strcmp(str, "<") == 0)
			break;
		tab = remalloc_tab(tab, str);
		compter++;
	}
	compter++;
	create_choice_box(fi, compter, tab);
	choise_box_bouc(fi, compter, tab);
	fi->nb_choice_pre = compter;
	free_tab_withnull(tab);
	free(str);
}
