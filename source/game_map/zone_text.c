/*
** EPITECH PROJECT, 2018
** zone_text.c
** File description:
** zone_text.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void take_good_option(files_t *fi, int fd)
{
	char *str;
	char *un;

	while ((str = get_next_line(fd)) != NULL) {
		un = int_to_str(fi->var_choice);
		if (!my_strcmp(str, un)) {
			free(un);
			fi->choice_cursor = 0;
			free(str);
			break;
		}
		free(un);
		free(str);
	}
	fi->pre_var = fi->var_choice;
	fi->var_choice = fi->nb_choice_pre;
}

int update_dialog_box(files_t *fi, int fd)
{
	char *str = get_next_line(fd);
	char *tra = int_to_str(fi->pre_var + 1);

	if (str == NULL || my_strcmp(str, tra) == 0) {
		free(str);
		free(tra);
		return (1);
	} else if (!my_strcmp(str, ">")) {
		choice_box(fi, fd);
		free(str);
		take_good_option(fi, fd);
		str = get_next_line(fd);
	}
	sfText_setString(fi->pnj[fi->nb_pnj].dialog_box->text->text, str);
	free(str);
	free(tra);
	return (0);
}

void open_or_no(files_t *fi, int fd)
{
	if (update_dialog_box(fi, fd) == 1)
		fi->dialog_box_isopen = 0;
}

void event_dialog_box(files_t *fi, sfEvent event, int fd)
{
	if (event.type == sfEvtKeyPressed ||
	event.type == sfEvtMouseButtonPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyReturn) ||
		(sfMouse_isButtonPressed(sfMouseLeft) &&
		(mouse_in_object_dialogbox(fi->pnj[fi->nb_pnj].dialog_box->obj,
		fi->window, fi) == 1))) {
			open_or_no(fi, fd);
		}
	}
}

void dialog_box(files_t *fi)
{
	char *un = my_strdup("dialog_box/text/");
	char *deux = my_strdup(fi->pnj[fi->nb_pnj].name);
	char *path = my_strcat(un, deux);
	free(un);
	free(deux);
	int fd = open(path, O_RDONLY);
	sfEvent event;

	create_dialog_box(fi);
	create_name_box(fi);
	update_dialog_box(fi, fd);
	while (fi->dialog_box_isopen == 1) {
		while (sfRenderWindow_pollEvent(fi->window, &event))
			event_dialog_box(fi, event, fd);
		draw_dialog_box(fi);
	}
	destroy_dialog_box(fi);
	close(fd);
	free(path);
}
