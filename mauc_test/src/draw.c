/*
** EPITECH PROJECT, 2018
** draw.c
** File description:
** draw file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void draw_choice_menu(files_t *fi, int compter)
{
	int i = 0;

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
	while (i != compter) {
		sfRenderWindow_drawSprite(fi->window,
		fi->pnj[fi->nb_pnj].choice_box[i]->obj->sprite, NULL);
		sfRenderWindow_drawText(fi->window,
		fi->pnj[fi->nb_pnj].choice_box[i]->text->text, NULL);
		i++;
	}
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

void draw_pnj(files_t *fi)
{
	int i = 0;
	int nbpnj = 4;

	while (i != nbpnj) {
		sfRenderWindow_drawSprite(fi->window, fi->pnj[i].pnj->sprite, NULL);
		i++;
	}
}

void draw_all(files_t *fi)
{
	sfSprite_setTextureRect(fi->characters->sprite, fi->characters->rect);
	sfSprite_setPosition(fi->characters->sprite, fi->characters->pos);
	sfRenderWindow_clear(fi->window, sfBlack);
	sfRenderWindow_drawSprite(fi->window, fi->map.sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->map.sprite5, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->map.sprite3, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->map.sprite2, NULL);
	//sfRenderWindow_drawSprite(fi->window, fi->ID_characters->sprite, NULL);
	sfRenderWindow_drawSprite(fi->window, fi->characters->sprite, NULL);
	draw_pnj(fi);
	sfRenderWindow_drawSprite(fi->window, fi->map.sprite4, NULL);
}

void draw(files_t *fi)
{
	draw_all(fi);
	sfRenderWindow_display(fi->window);
	usleep(1);
}
