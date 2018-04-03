/*
** EPITECH PROJECT, 2018
** zone_text.c
** File description:
** zone_text.c file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void destroy_dialog_box(files_t *fi)
{
	destroy_button(fi->pnj[fi->nb_pnj].dialog_box);
	destroy_button(fi->pnj[fi->nb_pnj].name_box);
}

int update_dialog_box(files_t *fi, int fd)
{
	char *str = get_next_line(fd);

	if (str == NULL) {
		free(str);
		return (1);
	} else {
		sfText_setString(fi->pnj[fi->nb_pnj].dialog_box->text->text, str);
		free(str);
		return (0);
	}
}

void create_dialog_box(files_t *fi)
{
	float pos_x = fi->camera.x - 450;
	float pos_y = fi->camera.y + 250;
	float pos_text_x = pos_x + 50;
	float pos_text_y = pos_y + 70;

	fi->pnj[fi->nb_pnj].dialog_box = create_button("jk",
	create_object("dialog_box/dialog_box_obj.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 908, 185), 0), sfWhite, 35);
	sfText_setPosition(fi->pnj[fi->nb_pnj].dialog_box->text->text,
	create_vector2f(pos_text_x, pos_text_y));
}

void create_name_box(files_t *fi)
{
	float pos_x = fi->camera.x - 440;
	float pos_y = fi->camera.y + 200;
	float pos_text_x = pos_x + 30;
	float pos_text_y = pos_y + 26;

	fi->pnj[fi->nb_pnj].name_box = create_button(fi->pnj[fi->nb_pnj].name,
	create_object("dialog_box/name_box_obj.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 162, 76), 0), sfWhite, 20);
	sfText_setPosition(fi->pnj[fi->nb_pnj].name_box->text->text,
	create_vector2f(pos_text_x, pos_text_y));
}

void event_dialog_box(files_t *fi, sfEvent event, int fd)
{
	if (event.type == sfEvtKeyPressed || event.type == sfEvtMouseButtonPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyReturn) ||
		sfMouse_isButtonPressed(sfMouseLeft) &&
		(mouse_in_object(fi->pnj[fi->nb_pnj].dialog_box->obj,
		fi->window, fi) == 1)) {
			if (update_dialog_box(fi, fd) == 1)
				fi->dialog_box_isopen = 0;
		}
	}
}

void dialog_box(files_t *fi)
{
	char *path = my_strcat(my_strdup("dialog_box/text/"),
	my_strdup(fi->pnj[fi->nb_pnj].name));
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
