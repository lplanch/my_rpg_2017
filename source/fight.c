/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_icons_archer(st_rpg *s)
{
	s->fight.icons[0] = create_button("M1",
	create_object("spells/archer/Quick_Shot.png",
	create_vector2f(200, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
	s->fight.icons[1] = create_button("E",
	create_object("spells/archer/Rapid_Fire.png",
	create_vector2f(300, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
	s->fight.icons[2] = create_button("R",
	create_object("spells/archer/Stormaxe.png",
	create_vector2f(400, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
}

void display_icons(st_rpg *s)
{
	for (int i = 0; i != 3; i += 1) {
		sfRenderWindow_drawSprite(s->window,
			s->fight.icons[i]->obj->sprite, NULL);
		sfRenderWindow_drawText(s->window,
			s->fight.icons[i]->text->text, NULL);
	}
}

void destroy_icons(st_rpg *s)
{
	for (int i = 0; i != 3; i += 1)
		destroy_button(s->fight.icons[i]);
}

void create_spells_archer(st_rpg *s)
{
	create_icons_archer(s);
	for (int i = 0; i != 10; i += 1) {
		s->fight.arrow[i] = create_projectile("projectile/Arrow");
	}
	s->fight.axe = create_projectile("projectile/Axe");
	s->fight.t = create_st_time();
	s->fight.current = 0;
	s->fight.kalash = 0;
	s->fight.kalashspeed = 0.05;
}

void update_axe(st_rpg *s)
{
	update_projectile(s->fight.axe);
	//sfSprite_setRotation(s->fight.axe->obj->sprite,
		//sfSprite_getRotation(s->fight.axe->obj->sprite) + 15);
}

void destroy_spells_archer(st_rpg *s)
{
	destroy_icons(s);
	for (int i = 0; i != 10; i += 1)
		destroy_projectile(s->fight.arrow[i]);
	destroy_projectile(s->fight.axe);
	sfClock_destroy(s->fight.t.clock);
}

void update_current_arrow(st_rpg *s)
{
	if (s->fight.current > 9)
		s->fight.current = 0;
}

void update_kalash(st_rpg *s)
{
	s->fight.t.time = sfClock_getElapsedTime(s->fight.t.clock);
	s->fight.t.sec = s->fight.t.time.microseconds / 1000000.0;
	if (s->fight.t.sec > s->fight.kalashspeed && s->fight.kalash == 1) {
		launch_projectile(s->fight.arrow[s->fight.current], s->window);
		s->fight.current += 1;
		if (s->fight.current > 9)
			s->fight.kalash = 0;
		update_current_arrow(s);
		sfClock_restart(s->fight.t.clock);
	}
}

void fight_manage_events(st_rpg *s)
{
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		launch_projectile(s->fight.arrow[s->fight.current], s->window);
		s->fight.current += 1;
		update_current_arrow(s);
	} if (sfKeyboard_isKeyPressed(sfKeyE))
		s->fight.kalash = 1;
	if (sfKeyboard_isKeyPressed(sfKeyR))
		launch_projectile(s->fight.axe, s->window);
}

int fight_events(st_rpg *s)
{
       sfEvent event;

       while (sfRenderWindow_pollEvent(s->window, &event)) {
        	if (event.type == sfEvtClosed) {
                	s->returnv = 1;
                	destroy_spells_archer(s);
                	return (1);
		}
		if (event.type == sfEvtMouseButtonPressed || event.type ==
		sfEvtKeyPressed)
        		fight_manage_events(s);
	}
	return (0);
}

void display_arrows(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1) {
		if (s->fight.arrow[i]->shot) {
			sfRenderWindow_drawSprite(s->window,
				s->fight.arrow[i]->obj->sprite, NULL);
		}
	}
	if (s->fight.axe->shot)
		sfRenderWindow_drawSprite(s->window,
			s->fight.axe->obj->sprite, NULL);
}

int fight_instance(st_rpg *s)
{
	create_spells_archer(s);
        while (sfRenderWindow_isOpen(s->window)) {
        	if (fight_events(s))
                	break;
		for (int i = 0; i != 10; i += 1)
			update_projectile(s->fight.arrow[i]);
		update_kalash(s);
		update_axe(s);
		sfRenderWindow_clear(s->window, sfWhite);
		//printf("x = %f, y = %f\n", s->fight.arrow->obj->pos.x +
		//s->fight.arrow->obj->rect.width / 2, s->fight.arrow->obj->pos.y +
		//s->fight.arrow->obj->rect.height / 2);
		display_icons(s);
		display_arrows(s);
        	sfRenderWindow_display(s->window);
        }
        return (s->returnv);
}
