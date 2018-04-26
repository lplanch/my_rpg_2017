/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_locked_spells_cd(st_rpg *s)
{
	if (s->player.tree.lock[s->player.tree.spell1 + 3])
		sfSprite_setTextureRect(s->f.cd[1]->sprite, create_rect(0, 0,
		sfSprite_getTextureRect(s->f.cd[1]->sprite).height,
		sfSprite_getTextureRect(s->f.cd[1]->sprite).height));
	if (s->player.tree.lock[s->player.tree.spell2 + 6])
		sfSprite_setTextureRect(s->f.cd[2]->sprite, create_rect(0, 0,
		sfSprite_getTextureRect(s->f.cd[2]->sprite).height,
		sfSprite_getTextureRect(s->f.cd[2]->sprite).height));
	if (s->player.tree.lock[s->player.tree.spell3 + 8])
		sfSprite_setTextureRect(s->f.cd[3]->sprite, create_rect(0, 0,
		sfSprite_getTextureRect(s->f.cd[3]->sprite).height,
		sfSprite_getTextureRect(s->f.cd[3]->sprite).height));
}

void display_locked_spells(st_rpg *s)
{
	if (s->player.tree.lock[s->player.tree.spell1 + 3])
		display_object(s->window, s->f.locks[0]);
	if (s->player.tree.lock[s->player.tree.spell2 + 6])
		display_object(s->window, s->f.locks[1]);
	if (s->player.tree.lock[s->player.tree.spell3 + 8])
		display_object(s->window, s->f.locks[2]);
}

void display_icons(st_rpg *s)
{
	display_locked_spells_cd(s);
	for (int i = 0; i != 4; i += 1) {
		sfRenderWindow_drawSprite(s->window,
		s->f.icons[i]->obj->sprite, NULL);
		sfRenderWindow_drawSprite(s->window, s->f.cd[i]->sprite,
		NULL);
		sfRenderWindow_drawText(s->window,
		s->f.icons[i]->text->text, NULL);
	} if (s->player.cdata.classe == 2 && s->player.tree.passive == 2) {
		if (s->f.rog.vanish > 0) {
			display_button(s->window, s->f.rog.backstab);
		}
	}
	display_locked_spells(s);
}

void destroy_icons(st_rpg *s)
{
	for (int i = 0; i != 4; i += 1)
		destroy_button(s->f.icons[i]);
	destroy_icons_cd(s);
	sfClock_destroy(s->f.cdt.clock);
}

char *which_spell(st_rpg *s, int spell)
{
	if (spell == 0)
		return ("auto");
	if (spell == 1) {
		return (my_strcat("m", int_to_str(s->player.tree.spell1 + 1)));
	} if (spell == 2) {
		return (my_strcat("e", int_to_str(s->player.tree.spell2 + 1)));
	} if (spell == 3) {
		return (my_strcat("r", int_to_str(s->player.tree.spell3 + 1)));
	}
	return (NULL);
}

char *get_spell_path(st_rpg *s, int spell)
{
	char *tmp;
	char *str = my_strcat("spells/", int_to_str(s->player.cdata.classe));

	tmp = my_strcat(str, "/");
	free(str);
	str = my_strcat(tmp, which_spell(s, spell));
	free(tmp);
	tmp = my_strcat(str, ".png");
	free(str);
	return (tmp);
}

void create_icons(st_rpg *s)
{
	s->f.icons[0] = create_button("M1",
	create_object(get_spell_path(s, 0),
	create_vector2f(200, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	25);
	s->f.icons[1] = create_button("M2",
	create_object(get_spell_path(s, 1),
	create_vector2f(300, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	25);
	s->f.icons[2] = create_button("E",
	create_object(get_spell_path(s, 2),
	create_vector2f(400, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	25);
	s->f.icons[3] = create_button("R",
	create_object(get_spell_path(s, 3),
	create_vector2f(500, 800), create_rect(0, 0, 128, 128), 0), sfWhite,
	25);
	create_icons_cd(s);
}
