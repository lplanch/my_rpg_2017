/*
** EPITECH PROJECT, 2018
** sound_set.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

void get_sound_option(st_rpg *s)
{
	int fd = open("saves/sound", O_RDONLY);
	char *buffer = get_next_line(fd);

	s->s_music = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	s->s_effect = str_to_int(buffer);
	free(buffer);
	close(fd);
	s->mainm.music = sfMusic_createFromFile("ressources/audio/menu.ogg");
	sfMusic_setVolume(s->mainm.music, s->s_music);
	sfMusic_play(s->mainm.music);
}
