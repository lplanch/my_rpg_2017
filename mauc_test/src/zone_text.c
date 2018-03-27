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
}

void draw_dialog_box(files_t *fi)
{
	sfRenderWindow_clear(fi->window, sfBlack);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite5, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite3, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite2, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->ID_sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->testmap.sprite4, NULL);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].dialog_box->obj->sprite, NULL);
	sfRenderWindow_drawText(fi->window,
	fi->pnj[fi->nb_pnj].dialog_box->text->text, NULL);
	sfRenderWindow_display(fi->window);
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
	float pos_text_y = pos_y + 60;

	fi->pnj[fi->nb_pnj].dialog_box = create_button("jk",
	create_object("dialog_box/dialog_box_obj.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 908, 185), 0), sfWhite, 35);
	sfText_setPosition(fi->pnj[fi->nb_pnj].dialog_box->text->text,
	create_vector2f(pos_text_x, pos_text_y));
}

void event_dialog_box(files_t *fi, sfEvent event, int fd)
{
	if (event.type == sfEvtKeyPressed || event.type == sfEvtMouseButtonPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyReturn) ||
		sfMouse_isButtonPressed(sfMouseLeft)) {
			if (update_dialog_box(fi, fd) == 1)
				fi->dialog_box_isopen = 0;
		}
	}
}

void dialog_box(files_t *fi)
{
	//char *path = my_strcat("dialog_box/", fi->pnj[fi->nb_pnj].name);
	int fd = open("dialog_box/michel", O_RDONLY);
	sfEvent event;

	create_dialog_box(fi);
	update_dialog_box(fi, fd);
	while (fi->dialog_box_isopen == 1) {
		while (sfRenderWindow_pollEvent(fi->window, &event))
			event_dialog_box(fi, event, fd);
		draw_dialog_box(fi);
	}
	destroy_dialog_box(fi);
	close(fd);
}
