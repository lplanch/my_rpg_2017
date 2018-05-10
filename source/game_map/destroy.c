/*
** EPITECH PROJECT, 2018
** delete.c
** File description:
** delete file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void destroy_name_box(st_rpg *s)
{
	for (int i = 0; i != s->fi->size_name_pnj; i++) {
		destroy_button(s->fi->name_head[i]);
	}
	free(s->fi->name_head);
	destroy_object(s->fi->name_head_edge[0]);
	destroy_object(s->fi->name_head_edge[1]);
	s->fi->oui = 0;
}

void destroy_music(st_rpg *s)
{
	sfMusic_destroy(s->fi->music.music);
	sfMusic_destroy(s->fi->samys_music.music);
	sfMusic_destroy(s->fi->ponder_music.music);
}

void destroy_pnj(st_rpg *s)
{
	int i = 0;

	while (i != s->fi->max_pnj) {
		destroy_object(s->fi->pnj[i].pnj);
		free(s->fi->pnj[i].name);
		i++;
	}
}

void destroy_sprite(st_rpg *s)
{
	sfSprite_destroy(s->fi->map.sprite);
	sfSprite_destroy(s->fi->map.sprite2);
	sfSprite_destroy(s->fi->map.sprite3);
	sfSprite_destroy(s->fi->map.sprite4);
	sfSprite_destroy(s->fi->map.sprite5);
}

void destroy_texture(st_rpg *s)
{
	sfTexture_destroy(s->fi->map.texture);
	sfTexture_destroy(s->fi->map.texture2);
	sfTexture_destroy(s->fi->map.texture3);
	sfTexture_destroy(s->fi->map.texture4);
	sfTexture_destroy(s->fi->map.texture5);
}

void destroy_quests(st_rpg *s)
{
	for (int i = 0; s->fi->quests[i] != NULL; i++) {
		free(s->fi->quests[i]->title);
		free(s->fi->quests[i]->path);
	}
	destroy_button(s->fi->quests_box.quests_box);
	destroy_button(s->fi->quests_box.quests_des);
	destroy_shader(&s->fi->shader);
	destroy_shader(&s->fi->shade_white);
}

void destroy(st_rpg *s)
{
	sfImage_destroy(s->fi->map.image);
	sfImage_destroy(s->fi->map.map_backgound);
	sfImage_destroy(s->fi->map.map_relief);
	sfImage_destroy(s->fi->map.map_col);
	sfImage_destroy(s->fi->map.map_colID);
	sfImage_destroy(s->fi->map.map_prof);
	destroy_sprite(s);
	destroy_texture(s);
	destroy_pnj(s);
	destroy_quests(s);
	destroy_object(s->player.obj);
	destroy_object(s->fi->ID_character);
	destroy_object(s->fi->loading);
	destroy_object(s->cut.map);
	destroy_object(s->cut.zachd);
	sfClock_destroy(s->fi->time.clock);
	sfClock_destroy(s->fi->pnj_clock.clock);
	sfClock_destroy(s->fi->clock);
	destroy_music(s);
	free_all(s);
}
