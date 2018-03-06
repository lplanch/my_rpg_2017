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

int main(void)
{
       st_rpg s;
       sfVideoMode mode = {1920, 1080, 32};

       s.window = sfRenderWindow_create(mode, "RPG", sfDefaultStyle, NULL);
       sfRenderWindow_setFramerateLimit(s.window, 60);
//	main_menu(&s);
       sfRenderWindow_destroy(s.window);
	return (0);
}
