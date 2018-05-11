/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void setup_variable_scene_quests(st_rpg *s)
{
	s->fi->oui = 0;
	s->fi->num_dungeon = 0;
	s->fi->map_status = 0;
	s->fi->zach_status = 0;
	s->fi->dream_status = 0;
	s->cut.map =
	create_object("ressources/images/scenes/map_death_of_zach.png",
	create_vector2f(0, 0), create_rect(0, 0, 528, 528), 0);
	s->cut.zachd =
	create_object("ressources/images/scenes/zach_is_dead.png",
	create_vector2f(0, 0), create_rect(0, 0, 61, 39), 0);
	s->cut.map_samy =
	create_object("ressources/images/scenes/map_death_of_samy.png",
	create_vector2f(0, 0), create_rect(0, 0, 816, 528), 0);
	s->cut.samyd =
	create_object("ressources/images/scenes/samy_is_dead.png",
	create_vector2f(0, 0), create_rect(0, 0, 70, 50), 0);
	s->cut.champ =
	create_object("ressources/images/scenes/champ.png",
	create_vector2f(0, 0), create_rect(0, 0, 60, 46), 0);
}

void setup_music(st_rpg *s)
{
	s->fi->music.music =
	create_music(s->s_music, "ressources/audio/Alaria city.ogg");
	s->fi->samys_music.music =
	create_music(s->s_music, "ressources/audio/Samy's Theme.ogg");
	s->fi->reflexion_music.music =
	create_music(s->s_music, "ressources/audio/reflexion.ogg");
}

void setup_col(st_rpg *s)
{
	sfVector2f scale = {5, 5};

	s->fi->nbr_colcircle = 42;
	s->fi->nbr_colsquare = 479;
	s->fi->direction = 3;
	s->fi->lake = create_object("ressources/map_preset/lake.png",
	create_vector2f(2720, 0), create_rect(0, 0, 288, 366), 0);
	sfSprite_scale(s->fi->lake->sprite, scale);
}

void setup_camera(st_rpg *s)
{
	s->fi->view = sfView_create();
	s->fi->view = sfView_copy(sfRenderWindow_getDefaultView(s->window));
	s->fi->camera.x = s->player.obj->pos.x;
	s->fi->camera.y = s->player.obj->pos.y;
	s->fi->camera_prec.x = s->player.obj->pos.x;
	s->fi->camera_prec.y = s->player.obj->pos.y;
	s->fi->camera_pos = 0;
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->window, s->fi->view);
}
