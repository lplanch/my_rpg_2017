/*
** EPITECH PROJECT, 2018
** set_text_option.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

void set_text_option(st_rpg *s)
{
	s->mainm.sound[0] = create_text(int_to_str(s->s_effect),
	create_vector2f(1400, 500), "ressources/fonts/button.ttf");
	s->mainm.sound[1] = create_text(int_to_str(s->s_music),
	create_vector2f(1400, 620), "ressources/fonts/button.ttf");
	s->mainm.sound[2] = create_text("<       >",
	create_vector2f(1200, 500), "ressources/fonts/button.ttf");
	s->mainm.sound[3] = create_text("<       >",
	create_vector2f(1200, 620), "ressources/fonts/button.ttf");
	sfText_setCharacterSize(s->mainm.sound[0]->text, 100);
	sfText_setCharacterSize(s->mainm.sound[1]->text, 100);
	sfText_setCharacterSize(s->mainm.sound[2]->text, 100);
	sfText_setCharacterSize(s->mainm.sound[3]->text, 100);
}
