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
		sfText_setString(s->fi->text_finish_quests->text,
		"Quests 1 complete!");
		s->fi->var_for_quests = 255;
	}
}
