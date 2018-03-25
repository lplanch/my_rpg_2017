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
	s->f.cdt = create_st_time();
	s->f.cdcount[0] = 0;
	s->f.cdcount[1] = 0;
	s->f.cdcount[2] = 0;
	s->f.cdcount[3] = 0;
	s->f.tree.passive = 0;
	s->f.tree.spell1 = 0;
	s->f.tree.spell2 = 0;
	s->f.tree.spell3 = 0;
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
        while (sfRenderWindow_isOpen(s->window)) {
        	if (fight_events(s))
                	break;
		launch_spells(s);
		update_class(s);
		update_icons_cd(s);
		sfRenderWindow_clear(s->window, sfWhite);
		display_icons(s);
		display_class(s);
		display_life_bar(s);
        	sfRenderWindow_display(s->window);
        }
        return (s->returnv);
}
