/*
** EPITECH PROJECT, 2018
** draw_choice.c
** File description:
** draw_choice file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void draw_choice_menu_text(files_t *fi, int compter)
{
	int i = 0;

	while (i != compter) {
		sfRenderWindow_drawSprite(fi->window,
		fi->pnj[fi->nb_pnj].choice_box[i]->obj->sprite, NULL);
		sfRenderWindow_drawText(fi->window,
		fi->pnj[fi->nb_pnj].choice_box[i]->text->text, NULL);
		i++;
	}
}

void draw_choice_menu(files_t *fi, int compter)
{
	draw_all(fi);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].dialog_box->obj->sprite, NULL);
	sfRenderWindow_drawText(fi->window,
	fi->pnj[fi->nb_pnj].dialog_box->text->text, NULL);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].name_box->obj->sprite, NULL);
	sfRenderWindow_drawText(fi->window,
	fi->pnj[fi->nb_pnj].name_box->text->text, NULL);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].choice_box_edge[1]->sprite, NULL);
	draw_choice_menu_text(fi, compter);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].choice_box_edge[0]->sprite, NULL);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].cursor->sprite, NULL);
	sfRenderWindow_display(fi->window);
}

void draw_dialog_box(files_t *fi)
{
	draw_all(fi);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].dialog_box->obj->sprite, NULL);
	sfRenderWindow_drawText(fi->window,
	fi->pnj[fi->nb_pnj].dialog_box->text->text, NULL);
	sfRenderWindow_drawSprite(fi->window,
	fi->pnj[fi->nb_pnj].name_box->obj->sprite, NULL);
	sfRenderWindow_drawText(fi->window,
	fi->pnj[fi->nb_pnj].name_box->text->text, NULL);
	sfRenderWindow_display(fi->window);
}
