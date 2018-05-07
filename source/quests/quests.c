/*
** EPITECH PROJECT, 2018
** move_pnj.c
** File description:
** move_pnj.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

sfIntRect set_texturerect_top(g_object *obj, int top)
{
	obj->rect.top = top;
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	return (obj->rect);
}

void quests_1(st_rpg *s)
{
	s->fi->quests[0]->status = 2;
	s->fi->pnj[2].pnj->rect = set_texturerect_top(s->fi->pnj[2].pnj, 0);
	dialog_box(s, "samy_beginning");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7947, 7374, 3);
	s->fi->character->rect = set_texturerect_top(s->fi->character, 96);
	dialog_box(s, "jade_beginning");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7888, 7502, 0);
	s->fi->pnj[0].pnj->rect = set_texturerect_top(s->fi->pnj[0].pnj, 144);
	s->fi->character->rect = set_texturerect_top(s->fi->character, 0);
	dialog_box(s, "zac_beginning");
	sfText_setString(s->fi->text_finish_quests->text,
	"Quests 1 complete!");
	s->fi->var_for_quests = 255;
}
