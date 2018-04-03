/*
** EPITECH PROJECT, 2018
** dialog_box_menu.c
** File description:
** dialog_box_menu.c file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

char **remalloc_tab(char **tab, char *str)
{
	char **tmp = tab;
	int i = 0;
	int compter = 0;

	while (tmp[i] != NULL) {
		compter++;
		i++;
	}
	tab = malloc(sizeof(char *) * (compter + 2));
	for (i = 0; tmp[i]; i++)
		tab[i] = strdup(tmp[i]);
	tab[i++] = strdup(str);
	tab[i] = 0;
	return (tab);
}

int create_choice_box_middle(files_t *fi, int i, char **tab)
{
	float pos_x = fi->camera.x + 446;
	float pos_y = fi->camera.y + 230;
	float pos_text_x = pos_x + 70;
	float posy = 0;

	posy = pos_y - 60 - (60 * i);
	fi->pnj[fi->nb_pnj].choice_box[i] = create_button(tab[i],
	create_object("dialog_box/choice_box2.png",
	create_vector2f(pos_x, posy),
	create_rect(0, 0, 460, 60), 0), sfWhite, 35);
	sfText_setPosition(fi->pnj[fi->nb_pnj].choice_box[i]->text->text,
	create_vector2f(pos_text_x, posy + 10));
	return (posy);
}

void create_choice_box(files_t *fi, int compter, char **tab)
{
	int i = 0;
	float pos_x = fi->camera.x + 446;
	float pos_y = fi->camera.y + 230;
	float posy = 0;

	fi->pnj[fi->nb_pnj].choice_box = malloc(sizeof(st_button) * compter);
	fi->pnj[fi->nb_pnj].choice_box_edge[1] =
	create_object("dialog_box/choice_box3.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 460, 32), 0);
	while (i != compter) {
		posy = create_choice_box_middle(fi, i, tab);
		i++;
	}
	posy = pos_y - 60 - (60 * i);
	fi->pnj[fi->nb_pnj].choice_box_edge[0] =
	create_object("dialog_box/choice_box1.png",
	create_vector2f(pos_x, posy + 28), create_rect(0, 0, 460, 32), 0);
	fi->pnj[fi->nb_pnj].cursor =
	create_object("dialog_box/cursor.png",
	create_vector2f(pos_x + 38, posy + 77), create_rect(0, 0, 24, 24), 0);
}

void up_cursor(files_t *fi)
{
	if (fi->choice_cursor > 0) {
		fi->pnj[fi->nb_pnj].cursor->pos.y -= 60;
		fi->choice_cursor--;
	}
	sfSprite_setPosition(fi->pnj[fi->nb_pnj].cursor->sprite,
	fi->pnj[fi->nb_pnj].cursor->pos);
}

void down_cursor(files_t *fi, int compter)
{
	if (fi->choice_cursor < compter - 1) {
		fi->pnj[fi->nb_pnj].cursor->pos.y += 60;
		fi->choice_cursor++;
	}
	sfSprite_setPosition(fi->pnj[fi->nb_pnj].cursor->sprite,
	fi->pnj[fi->nb_pnj].cursor->pos);
}

int event_choice_box(files_t *fi, int compter)
{
	int a = 0;
	sfEvent event;

	while (sfRenderWindow_pollEvent(fi->window, &event)) {
		if (event.type == sfEvtKeyPressed || event.type == sfEvtMouseButtonPressed) {
			if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
				a++;
			} if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ)) {
				up_cursor(fi);
			} if (sfKeyboard_isKeyPressed(sfKeyDown) ||
			sfKeyboard_isKeyPressed(sfKeyS)) {
				down_cursor(fi, compter);
			}
		}
	}
	return (a);
}

void choise_box_bouc(files_t *fi, int compter)
{
	while (a != 1) {
		a = event_choice_box(fi, compter);
		draw_choice_menu(fi, compter);
	}
	fi->choice_cursor = 0;
}

void choice_box(files_t *fi, int fd)
{
	int a = 0;
	int i = 0;
	int compter = 0;
	char *str = get_next_line(fd);
	char **tab = my_calloc(sizeof(char*) * 1);

	tab = remalloc_tab(tab, str);
	while (1) {
		str = get_next_line(fd);
		if (my_strcmp(str, "<") == 0)
			break;
		tab = remalloc_tab(tab, str);
		compter++;
	}
	compter++;
	create_choice_box(fi, compter, tab);
	choise_box_bouc(fi, compter);
}
