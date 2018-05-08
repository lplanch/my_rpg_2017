/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void game_update(st_rpg *s)
{
	if (s->fi->dialog_box_isopen == 1)
		dialog_box(s, my_strdup(s->fi->pnj[s->fi->nb_pnj].name));
	move_ok(s);
	s->player.last_pos = s->player.obj->pos;
	update_player_position_village(s);
	if (!s->f.panim)
		player_animation_village(s);
	move_id_player(s);
	s->proc.gman.time = sfClock_restart(s->proc.gman.clock);
	s->proc.gman.dt = sfTime_asSeconds(s->proc.gman.time);
	move_infos_box(s);
	check_quests(s);
	draw(s);
}

int event_game(st_rpg *s)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtClosed) {
			destroy(s);
			return (1);
		} if (event.type == sfEvtKeyPressed && event.key.code ==
		sfKeyReturn) {
			check_pnj(s);
		} if (mouse_in_object_quest_box(s->fi
		->quests_box.quests_box->obj, s->window, s) == 1) {
			update_quests_box_des(s);
			s->fi->quests_box.status = 1;
		} else
			s->fi->quests_box.status = 0;
	}
	return (0);
}
