/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_life_bar(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->bar.bars->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->bar.life->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->bar.xp->sprite, NULL);
}

void update_life_bar(st_rpg *s)
{

}

void create_life_bar(st_rpg *s)
{
	s->bar.bars = create_object("images/bars.png", create_vector2f(40, 40),
	create_rect(0, 0, 408, 82), 0);
	s->bar.life = create_object("images/life.png",
	create_vector2f(s->bar.bars->pos.x + 82, s->bar.bars->pos.y + 18),
	create_rect(0, 0, 316, 18), 0);
	s->bar.xp = create_object("images/xp.png",
	create_vector2f(s->bar.life->pos.x, s->bar.bars->pos.y + 47),
	create_rect(0, 0, 316, 18), 0);
}

void destroy_life_bar(st_rpg *s)
{
	destroy_object(s->bar.bars);
	destroy_object(s->bar.life);
	destroy_object(s->bar.xp);
}
