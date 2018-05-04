/*
** EPITECH PROJECT, 2018
** shader.c
** File description:
** description
*/

#include "my_rpg.h"

void init_menu_shader(st_rpg *s)
{
	s->mainm.shader.shader = sfShader_createFromFile(
		"shader/simple.vert", "shader/rainbow.frag");
	s->mainm.shader.state.shader = s->mainm.shader.shader;
	s->mainm.shader.state.blendMode = sfBlendAlpha;
	s->mainm.shader.state.transform = sfTransform_Identity;
	s->mainm.shader.state.texture = NULL;
	s->mainm.shader.time = create_st_time();
}

void shader_move(st_rpg *s)
{
	s->mainm.shader.time.time =
	sfClock_getElapsedTime(s->mainm.shader.time.clock);
	s->mainm.shader.time.sec =
	s->mainm.shader.time.time.microseconds / 1000000.0;
	if (s->mainm.shader.time.sec > 1 &&
	s->mainm.shader.time.sec < 2) {
		sfShader_setFloatParameter(s->mainm.shader.shader, "time",
		-s->mainm.shader.time.sec);
	} else {
		sfShader_setFloatParameter(s->mainm.shader.shader, "time",
		s->mainm.shader.time.sec);
	}
	if (s->mainm.shader.time.sec > 2) {
		sfClock_restart(s->mainm.shader.time.clock);
	}
}
