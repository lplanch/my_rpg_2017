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
	s->fi->pnj[10].pnj->rect = set_texturerect_top(s->fi->pnj[10].pnj, 144);
	s->fi->pnj[3].pnj->rect = set_texturerect_top(s->fi->pnj[3].pnj, 144);
	s->fi->pnj[13].pnj->rect = set_texturerect_top(s->fi->pnj[13].pnj, 144);
	s->fi->pnj[10].pnj->pos = create_vector2f(7882, 7374);
	s->fi->pnj[13].pnj->pos = create_vector2f(10000, 10000);
	s->fi->pnj[3].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[10].pnj->sprite, s->fi->pnj[10].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[13].pnj->sprite, s->fi->pnj[13].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[3].pnj->sprite, s->fi->pnj[3].pnj->pos);
}

void print_text_finish_quests2(st_rpg *s, int posx, int posy)
{
	sfText_setColor(s->fi->text_finish_quests->text,
	(sfColor){0, 0, 0, s->fi->var_for_quests});
	sfText_setPosition(s->fi->text_finish_quests->text,
	create_vector2f(posx, posy - 3));
	sfRenderWindow_drawText(s->window,
	s->fi->text_finish_quests->text, NULL);
	sfText_setColor(s->fi->text_finish_quests->text,
	(sfColor){0, 0, 0, s->fi->var_for_quests});
	sfText_setPosition(s->fi->text_finish_quests->text,
	create_vector2f(posx, posy + 3));
	sfRenderWindow_drawText(s->window,
	s->fi->text_finish_quests->text, NULL);
	sfText_setColor(s->fi->text_finish_quests->text,
	(sfColor){255, 255, 255, s->fi->var_for_quests});
	sfText_setPosition(s->fi->text_finish_quests->text,
	create_vector2f(posx, posy));
	sfRenderWindow_drawText(s->window,
	s->fi->text_finish_quests->text, NULL);
}

void print_text_finish_quests(st_rpg *s)
{
	float posx = s->fi->camera.x - 200;
	float posy = s->fi->camera.y - 200;

	if (s->fi->quests[0]->status_text == 1 && s->fi->var_for_quests != 0) {
		sfText_setColor(s->fi->text_finish_quests->text,
		(sfColor){0, 0, 0, s->fi->var_for_quests});
		sfText_setPosition(s->fi->text_finish_quests->text,
		create_vector2f(posx - 3, posy));
		sfRenderWindow_drawText(s->window,
		s->fi->text_finish_quests->text, NULL);
		sfText_setColor(s->fi->text_finish_quests->text,
		(sfColor){0, 0, 0, s->fi->var_for_quests});
		sfText_setPosition(s->fi->text_finish_quests->text,
		create_vector2f(posx + 3, posy));
		sfRenderWindow_drawText(s->window,
		s->fi->text_finish_quests->text, NULL);
		print_text_finish_quests2(s, posx, posy);
		s->fi->var_for_quests -= 1;
	}
}

void check_pnj_for_quests(st_rpg *s)
{
	if (s->fi->quests[0]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "Samy") == 0) {
		stop_player(s);
		quests_1(s);
		after_quests(s);
	} if (s->fi->quests[1]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "Holm") == 0) {
		stop_player(s);
		sfText_setString(s->fi->text_finish_quests->text,
		"Quest 2 complete!");
		s->fi->quests[1]->status = 2;
		s->fi->var_for_quests = 255;
	} if (s->fi->quests[2]->status == 1 && s->fi->num_dungeon == 1) {
		sfText_setString(s->fi->text_finish_quests->text,
		"Quest 3 complete!");
		s->fi->var_for_quests = 255;
		s->fi->num_dungeon = 0;
		s->fi->quests[2]->status = 2;
		reset_pos_friends(s);
	} if (s->fi->quests[3]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "Samy") == 0) {
		stop_player(s);
		quests_3(s);
	} if (s->fi->quests[4]->status == 1 && s->fi->num_dungeon == 2) {
		sfText_setString(s->fi->text_finish_quests->text,
		"Quest 5 complete!");
		s->fi->var_for_quests = 255;
		s->fi->num_dungeon = 0;
		s->fi->quests[4]->status = 2;
		reset_pos_friends(s);
	}
}
