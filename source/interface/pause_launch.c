/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

int launch_pause_menu_status(st_rpg *s)
{
	if (sfKeyboard_isKeyPressed(sfKeyE)) {
		s->pausm.option = 0;
		s->pausm.menu = 0;
	}
	return (0);
}

int launch_pause_menu_main(st_rpg *s)
{
	switch (s->pausm.option) {
		case 0 :
			s->pausm.menu = 1;
			break;
		case 1 :
			s->pausm.menu = 2;
			break;
		case 3 :
			destroy_pause_menu(s);
			s->mainm.option = 0;
			s->mainm.menu = 0;
			return (main_menu(s));
		case 4 :
			destroy_pause_menu(s);
			return (1);
	}
	return (0);
}

int which_pause_menu(st_rpg *s)
{
	if (s->pausm.menu == 0)
		return (launch_pause_menu_main(s));
	if (s->pausm.menu == 1 || s->pausm.menu == 2)
		return (launch_pause_menu_status(s));
	return (0);
}