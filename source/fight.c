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
	s->fight.icons[3] = create_button("T",
	create_object("spells/archer/Barrage.png",
	create_vector2f(500, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
}

void display_icons(st_rpg *s)
{
	for (int i = 0; i != 4; i += 1) {
		sfRenderWindow_drawSprite(s->window,
			s->fight.icons[i]->obj->sprite, NULL);
		sfRenderWindow_drawText(s->window,
			s->fight.icons[i]->text->text, NULL);
	}
}

void destroy_icons(st_rpg *s)
{
	for (int i = 0; i != 4; i += 1)
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
	s->fight.barrage.shot = 0;
	s->fight.barrage.duration = 5;
	s->fight.barrage.t = create_st_time();
	s->fight.kalash = 0;
	s->fight.kalashspeed = 0.05;
	s->fight.barrage.circle = sfCircleShape_create();
	sfCircleShape_setRadius(s->fight.barrage.circle, 100);
	sfCircleShape_setOutlineColor(s->fight.barrage.circle, sfRed);
	sfCircleShape_setOutlineThickness(s->fight.barrage.circle, 5);
}

void update_aoe_barrage(st_rpg *s)
{
	s->fight.barrage.t.time = sfClock_getElapsedTime(s
		->fight.barrage.t.clock);
	s->fight.barrage.t.sec = s->fight.barrage.t.time.microseconds /
	1000000.0;
	if (s->fight.barrage.t.sec > s->fight.barrage.duration &&
		s->fight.barrage.shot == 1) {
		s->fight.barrage.shot = 0;
		s->fight.barrage.t.sec = 0;
		sfClock_restart(s->fight.barrage.t.clock);
	}
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
	sfClock_destroy(s->fight.barrage.t.clock);
	sfCircleShape_destroy(s->fight.barrage.circle);
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
	if (sfKeyboard_isKeyPressed(sfKeyT)) {
		sfCircleShape_setPosition(s->fight.barrage.circle,
	create_vector2f(sfMouse_getPositionRenderWindow(s->window).x - 100,
	sfMouse_getPositionRenderWindow(s->window).y - 100));
		sfClock_restart(s->fight.barrage.t.clock);
		s->fight.barrage.t.sec = 0.0;
		s->fight.barrage.shot = 1;
	}
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
	if (s->fight.barrage.shot)
		sfRenderWindow_drawCircleShape(s->window,
			s->fight.barrage.circle, NULL);
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
		update_aoe_barrage(s);
		sfRenderWindow_clear(s->window, sfWhite);
		display_icons(s);
		display_arrows(s);
        	sfRenderWindow_display(s->window);
        }
        return (s->returnv);
}
