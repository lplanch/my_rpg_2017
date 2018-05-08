/*
** EPITECH PROJECT, 2018
** check_pnj_for_quests.c
** File description:
** check_pnj_for_quests file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void reset_pos_friends(st_rpg *s)
{
	s->fi->pnj[8].pnj->rect = set_texturerect_top(s->fi->pnj[8].pnj, 144);
	s->fi->pnj[2].pnj->rect = set_texturerect_top(s->fi->pnj[2].pnj, 144);
	s->fi->pnj[10].pnj->rect = set_texturerect_top(s->fi->pnj[10].pnj, 144);
	s->fi->pnj[8].pnj->pos = create_vector2f(7882, 7374);
	s->fi->pnj[10].pnj->pos = create_vector2f(10000, 10000);
	s->fi->pnj[2].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[8].pnj->sprite, s->fi->pnj[8].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[10].pnj->sprite, s->fi->pnj[10].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[2].pnj->sprite, s->fi->pnj[2].pnj->pos);
}

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
		stop_player(s);
		quests_1(s);
		after_quests(s);
	} if (s->fi->quests[1]->status == 1 && s->fi->num_dungeon == 1) {
		sfText_setString(s->fi->text_finish_quests->text,
		"Quest 2 complete!");
		s->fi->var_for_quests = 255;
		s->fi->num_dungeon = 0;
		s->fi->quests[1]->status = 2;
		reset_pos_friends(s);
	}
}
