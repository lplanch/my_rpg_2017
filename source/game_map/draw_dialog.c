/*
** EPITECH PROJECT, 2018
** draw_choice.c
** File description:
** draw_choice file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_choice_menu_text(st_rpg *s, int compter)
{
	int i = 0;

	while (i != compter) {
		sfRenderWindow_drawSprite(s->window,
		s->fi->pnj[s->fi->nb_pnj].choice_box[i]->obj->sprite, NULL);
		sfRenderWindow_drawText(s->window,
		s->fi->pnj[s->fi->nb_pnj].choice_box[i]->text->text, NULL);
		i++;
	}
}

void draw_choice_menu(st_rpg *s, int compter)
{
	draw_all(s);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->fi->nb_pnj].dialog_box->obj->sprite, NULL);
	sfRenderWindow_drawText(s->window,
	s->fi->pnj[s->fi->nb_pnj].dialog_box->text->text, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->fi->nb_pnj].name_box->obj->sprite, NULL);
	sfRenderWindow_drawText(s->window,
	s->fi->pnj[s->fi->nb_pnj].name_box->text->text, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->fi->nb_pnj].choice_box_edge[1]->sprite, NULL);
	draw_choice_menu_text(s, compter);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->fi->nb_pnj].choice_box_edge[0]->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->fi->nb_pnj].cursor->sprite, NULL);
	sfRenderWindow_display(s->window);
}

void draw_dialog_box(st_rpg *s)
{
	draw_all(s);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->fi->nb_pnj].dialog_box->obj->sprite, NULL);
	sfRenderWindow_drawText(s->window,
	s->fi->pnj[s->fi->nb_pnj].dialog_box->text->text, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->fi->nb_pnj].name_box->obj->sprite, NULL);
	sfRenderWindow_drawText(s->window,
	s->fi->pnj[s->fi->nb_pnj].name_box->text->text, NULL);
	sfRenderWindow_display(s->window);
}
