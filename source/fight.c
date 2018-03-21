/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_icons_cd(st_rpg *s)
{
	for (int i = 0; i != 4; i += 1)
		destroy_object(s->f.cd[i]);
}

void update_cdcount_icons(st_rpg *s, int i)
{
	if (s->f.cdcount[i] > 0) {
		s->f.cdcount[i] -= 0.05;
	}
	if (s->f.cdcount[i] < 0) {
		s->f.cdcount[i] = 0;
	}
}

void update_icons_cd(st_rpg *s)
{
	s->f.cdt.time = sfClock_getElapsedTime(s->f.cdt.clock);
	s->f.cdt.sec = s->f.cdt.time.microseconds / 1000000.0;
	if (s->f.cdt.sec > 0.05) {
		for (int i = 0; i != 4; i += 1) {
			update_cdcount_icons(s, i);
			s->f.cd[i]->rect.width = 128 * s->f.cdcount[i] /
			s->f.cds[i];
			sfSprite_setTextureRect(s->f.cd[i]->sprite,
			s->f.cd[i]->rect);
			sfClock_restart(s->f.cdt.clock);
		}
	}
}

void create_icons_cd(st_rpg *s)
{
	for (int i = 0; i != 4; i += 1)
		s->f.cd[i] = create_object("images/semiblack.png",
	create_vector2f(200 + 100 * i, 800), create_rect(0, 0, 128, 128), 0);
}

void create_icons_archer(st_rpg *s)
{
	s->f.icons[0] = create_button("M1",
	create_object("spells/0/auto.png",
	create_vector2f(200, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
	s->f.icons[1] = create_button("E",
	create_object("spells/0/m1.png",
	create_vector2f(300, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
	s->f.icons[2] = create_button("R",
	create_object("spells/0/r2.png",
	create_vector2f(400, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
	s->f.icons[3] = create_button("T",
	create_object("spells/0/r1.png",
	create_vector2f(500, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	30);
	create_icons_cd(s);
}

void display_icons(st_rpg *s)
{
	for (int i = 0; i != 4; i += 1) {
		sfRenderWindow_drawSprite(s->window,
			s->f.icons[i]->obj->sprite, NULL);
		sfRenderWindow_drawSprite(s->window, s->f.cd[i]->sprite,
			NULL);
		sfRenderWindow_drawText(s->window,
			s->f.icons[i]->text->text, NULL);
	}
}

void destroy_icons(st_rpg *s)
{
	for (int i = 0; i != 4; i += 1)
		destroy_button(s->f.icons[i]);
	destroy_icons_cd(s);
}

void create_spells_archer(st_rpg *s)
{
	create_icons_archer(s);
	for (int i = 0; i != 10; i += 1) {
		s->f.arc.arrow[i] = create_projectile("projectile/Arrow");
	}
	s->f.arc.axe = create_projectile("projectile/Axe");
	s->f.arc.kal = create_st_time();
	s->f.cdt = create_st_time();
	s->f.arc.current = 0;
	s->f.arc.barrage.shot = 0;
	s->f.arc.barrage.duration = 5;
	s->f.arc.barrage.t = create_st_time();
	s->f.arc.kalash = 0;
	s->f.arc.axeangle = 0;
	s->f.arc.kalashspeed = 0.05;
	s->f.arc.barrage.circle = sfCircleShape_create();
	sfCircleShape_setRadius(s->f.arc.barrage.circle, 100);
	sfCircleShape_setOutlineColor(s->f.arc.barrage.circle, sfRed);
	sfCircleShape_setFillColor(s->f.arc.barrage.circle, sfTransparent);
	sfCircleShape_setOutlineThickness(s->f.arc.barrage.circle, 5);
}

void create_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {create_spells_archer, create_spells_archer,
	create_spells_archer, create_spells_archer};

	(list[s->cust.cdata.classe])(s);
}

void create_main_fight(st_rpg *s)
{
	s->f.buffer = -1;
	s->f.cdcount[0] = 0;
	s->f.cdcount[1] = 0;
	s->f.cdcount[2] = 0;
	s->f.cdcount[3] = 0;
	s->f.cds[0] = 0.3;
	s->f.cds[1] = 5;
	s->f.cds[2] = 10;
	s->f.cds[3] = 20;
	create_class(s);
}

void update_aoe_barrage(st_rpg *s)
{
	s->f.arc.barrage.t.time = sfClock_getElapsedTime(s
		->f.arc.barrage.t.clock);
	s->f.arc.barrage.t.sec = s->f.arc.barrage.t.time.microseconds /
	1000000.0;
	if (s->f.arc.barrage.t.sec > s->f.arc.barrage.duration &&
		s->f.arc.barrage.shot == 1) {
		s->f.arc.barrage.shot = 0;
		s->f.arc.barrage.t.sec = 0;
		sfClock_restart(s->f.arc.barrage.t.clock);
	}
}

void update_axe(st_rpg *s)
{
	sfVector2f ratios;

	s->f.arc.axe->angle += 15;
	s->f.arc.axeangle += 5;
	ratios = get_ratios(s->f.arc.axe->angle);
	s->f.arc.axe->ratios = get_ratios(s->f.arc.axeangle);
	s->f.arc.axe->rpos.x += s->f.arc.axe->ratios.x * s->f.arc.axe->obj
	->speed;
	s->f.arc.axe->rpos.y += s->f.arc.axe->ratios.y * s->f.arc.axe->obj
	->speed;
	s->f.arc.axe->used -= hypot(s->f.arc.axe->ratios.x * s->f.arc.axe->obj
	->speed, s->f.arc.axe->ratios.y * s->f.arc.axe->obj->speed);
	if (s->f.arc.axe->used <= 0)
		s->f.arc.axe->shot = 0;
	s->f.arc.axe->obj->pos.x = s->f.arc.axe->rpos.x - ratios.x * s
	->f.arc.axe->obj->rect.width / 2 + ratios.y * s->f.arc.axe->obj
	->rect.height / 2;
	s->f.arc.axe->obj->pos.y = s->f.arc.axe->rpos.y - ratios.y * s
	->f.arc.axe->obj->rect.width / 2 - ratios.x * s->f.arc.axe->obj
	->rect.height / 2;
	sfSprite_setPosition(s->f.arc.axe->obj->sprite, s->f.arc.axe->obj->pos);
	sfSprite_setRotation(s->f.arc.axe->obj->sprite, s->f.arc.axe->angle);
}

void destroy_spells_archer(st_rpg *s)
{
	destroy_icons(s);
	for (int i = 0; i != 10; i += 1)
		destroy_projectile(s->f.arc.arrow[i]);
	destroy_projectile(s->f.arc.axe);
	sfClock_destroy(s->f.arc.kal.clock);
	sfClock_destroy(s->f.cdt.clock);
	sfClock_destroy(s->f.arc.barrage.t.clock);
	sfCircleShape_destroy(s->f.arc.barrage.circle);
}

void update_current_arrow(st_rpg *s)
{
	if (s->f.arc.current > 9)
		s->f.arc.current = 0;
}

void update_kalash(st_rpg *s)
{
	s->f.arc.kal.time = sfClock_getElapsedTime(s->f.arc.kal.clock);
	s->f.arc.kal.sec = s->f.arc.kal.time.microseconds / 1000000.0;
	if (s->f.arc.kal.sec > s->f.arc.kalashspeed && s->f.arc.kalash == 1) {
		s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window);
		launch_projectile(s->f.arc.arrow[s->f.arc.current],
		s->f.arc.arrow[s->f.arc.current]->angle);
		s->f.arc.current += 1;
		if (s->f.arc.current > 9)
			s->f.arc.kalash = 0;
		update_current_arrow(s);
		sfClock_restart(s->f.arc.kal.clock);
	}
}

void fight_bufferisation(st_rpg *s)
{
	if (sfMouse_isButtonPressed(sfMouseLeft) && s->f.cdcount[0] >= 0)
		s->f.buffer = 0;
	if (sfKeyboard_isKeyPressed(sfKeyE) && s->f.cdcount[1] >= 0)
		s->f.buffer = 1;
	if (sfKeyboard_isKeyPressed(sfKeyR) && s->f.cdcount[2] >= 0)
		s->f.buffer = 2;
	if (sfKeyboard_isKeyPressed(sfKeyT) && s->f.cdcount[3] >= 0)
		s->f.buffer = 3;
}

void archer_auto_attack(st_rpg *s)
{
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window);
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
}

void archer_salve(st_rpg *s)
{
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window);
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window) + 15;
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window) - 15;
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window) - 5;
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window) + 5;
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window) - 10;
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s->window) + 10;
	launch_projectile(s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	s->f.arc.current += 1;
	update_current_arrow(s);
}

void archer_axe(st_rpg *s)
{
	s->f.arc.axe->rpos = create_vector2f(920, 540);
	s->f.arc.axe->angle = get_angle(s->window);
	s->f.arc.axeangle = s->f.arc.axe->angle - 70;
	launch_projectile(s->f.arc.axe, s->f.arc.axe->angle - 70);
}

void archer_kalash(st_rpg *s)
{
	s->f.arc.current = 0;
	s->f.arc.kalash = 1;
}

void archer_barrage(st_rpg *s)
{
	sfCircleShape_setPosition(s->f.arc.barrage.circle,
	create_vector2f(sfMouse_getPositionRenderWindow(s->window).x - 100,
	sfMouse_getPositionRenderWindow(s->window).y - 100));
	sfClock_restart(s->f.arc.barrage.t.clock);
	s->f.arc.barrage.t.sec = 0.0;
	s->f.arc.barrage.shot = 1;
}

void fight_manage_events(st_rpg *s)
{
	fight_bufferisation(s);
	if (sfMouse_isButtonPressed(sfMouseLeft) && s->f.cdcount[0] <= 0) {
		s->f.cdcount[0] = s->f.cds[0];
		archer_auto_attack(s);
	} if (sfKeyboard_isKeyPressed(sfKeyE) && s->f.cdcount[1] <= 0) {
		s->f.cdcount[1] = s->f.cds[1];
		archer_salve(s);
	} if (sfKeyboard_isKeyPressed(sfKeyR) && s->f.cdcount[2] <= 0) {
		s->f.cdcount[2] = s->f.cds[2];
		archer_axe(s);
	} if (sfKeyboard_isKeyPressed(sfKeyT) && s->f.cdcount[3] <= 0) {
		s->f.cdcount[3] = s->f.cds[3];
		archer_barrage(s);
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
	}
	fight_manage_events(s);
	return (0);
}

void display_arrows(st_rpg *s)
{
	if (s->f.arc.barrage.shot)
		sfRenderWindow_drawCircleShape(s->window,
			s->f.arc.barrage.circle, NULL);
	for (int i = 0; i != 10; i += 1) {
		if (s->f.arc.arrow[i]->shot) {
			sfRenderWindow_drawSprite(s->window,
				s->f.arc.arrow[i]->obj->sprite, NULL);
		}
	}
	if (s->f.arc.axe->shot)
		sfRenderWindow_drawSprite(s->window,
			s->f.arc.axe->obj->sprite, NULL);
}

int fight_instance(st_rpg *s)
{
	create_main_fight(s);
        while (sfRenderWindow_isOpen(s->window)) {
        	if (fight_events(s))
                	break;
		for (int i = 0; i != 10; i += 1)
			update_projectile(s->f.arc.arrow[i]);
		update_kalash(s);
		update_icons_cd(s);
		update_axe(s);
		update_aoe_barrage(s);
		sfRenderWindow_clear(s->window, sfWhite);
		display_icons(s);
		display_arrows(s);
        	sfRenderWindow_display(s->window);
        }
        return (s->returnv);
}
