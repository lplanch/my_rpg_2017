/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "game_object.h"
#include "my_rpg.h"

void loading(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->loading->sprite, NULL);
	sfRenderWindow_display(s->window);
}

int main(void)
{
	st_rpg s =  {0};
	sfVideoMode mode = {1920, 1080, 32};

	s.window = sfRenderWindow_create(mode, "RPG", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(s.window, 60);
	s.loading = create_object("images/Loading.png",
	create_vector2f(1600, 800), create_rect(0, 0, 400, 100), 0);
	s.statm.shot = 0;
	s.statm.show = 6;
	main_menu(&s);
	destroy_object(s.loading);
	sfRenderWindow_destroy(s.window);
	return (0);
}
