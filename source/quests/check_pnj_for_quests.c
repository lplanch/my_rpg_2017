/*
** EPITECH PROJECT, 2018
** check_pnj_for_quests.c
** File description:
** check_pnj_for_quests file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void print_text_finish_quests(st_rpg *s)
{
	float posx = s->fi->camera.x - 200;
	float posy = s->fi->camera.y - 200;

	if (s->fi->quests[0]->status_text == 1 && s->fi->var_for_quests != 0) {
		sfText_setColor(s->fi->text_finish_quests->text,
		(sfColor){255, 255, 255, s->fi->var_for_quests});
		sfText_setPosition(s->fi->text_finish_quests->text,
		create_vector2f(posx, posy));
		sfRenderWindow_drawText(s->window,
		s->fi->text_finish_quests->text, NULL);
		s->fi->var_for_quests -= 1;
	}
}

void check_pnj_for_quests(st_rpg *s)
{
	if (s->fi->quests[0]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "samy") == 0) {
		s->fi->quests[0]->status = 2;
		s->fi->pnj[s->fi->nb_pnj].pnj->rect.top = 0;
		sfSprite_setTextureRect(s->fi->pnj[s->fi->nb_pnj].pnj->sprite,
		s->fi->pnj[s->fi->nb_pnj].pnj->rect);
		dialog_box(s, "samy_beginning");
		s->fi->dialog_box_isopen = 1;
		move_pnj(s, 7947, 7374, 3);
		dialog_box(s, "jade_beginning");
		s->fi->dialog_box_isopen = 1;
		move_pnj(s, 7888, 7502, 0);
		s->fi->pnj[0].pnj->rect.top = 144;
		sfSprite_setTextureRect(s->fi->pnj[0].pnj->sprite,
		s->fi->pnj[0].pnj->rect);
		dialog_box(s, "zac_beginning");
		sfText_setString(s->fi->text_finish_quests->text,
		"Quests 1 complete!");
		s->fi->var_for_quests = 255;
	}
}
