/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_main_fight(st_rpg *s)
{
	s->f.cast = 0;
	s->f.proc = create_st_time();
	for (int i = 0; i != 4; i += 1)
		s->f.cdcount[i] = 0;
	get_cooldowns(s);
}

int fight_events(st_rpg *s)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtClosed) {
			s->returnv = 1;
			destroy_class(s);
			destroy_icons(s);
			destroy_life_bar(s);
			destroy_mob_example(s);
			sfClock_destroy(s->f.proc.clock);
			destroy_player(s);
			return (1);
		}
	}
	return (0);
}

int fight_instance(st_rpg *s)
{
	create_main_fight(s);
	create_icons(s);
	create_class(s);
	create_life_bar(s);
	create_mob_example(s);
	while (sfRenderWindow_isOpen(s->window)) {
		if (fight_events(s))
			break;
		if (!s->f.cast)
			launch_spells(s);
		update_pos_weapon(s);
		update_class(s);
		update_bars(s);
		update_icons_cd(s);
		update_projectiles(s);
		update_effects(s);
		update_mob_example(s);
		sfRenderWindow_clear(s->window, sfWhite);
		display_icons(s);
		display_class(s);
		display_player(s);
		display_life_bar(s);
		display_mob_example(s);
		sfRenderWindow_display(s->window);
	}
	return (s->returnv);
}
