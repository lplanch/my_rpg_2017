/*
** EPITECH PROJECT, 2018
** minimap_system.c
** File description:
** make minimap on screen
*/

#include "my.h"
#include "procedural.h"

void init_minimap_framebuffers(minimap_t *minimap)
{
	minimap->f_background =
	framebuffer_create(WIDTH / 2.5, HEIGHT / 2.5);
	minimap->fb_texture =
	sfTexture_create(WIDTH / 2.5, HEIGHT / 2.5);
	minimap->fb_sprite = sfSprite_create();
	sfSprite_setTexture(
	minimap->fb_sprite, minimap->fb_texture, sfTrue);
	fill_minimap_screen(minimap->f_background, sfBlack);
	minimap->f_minimap =
	framebuffer_create(WIDTH / 3, HEIGHT / 3);
	minimap->fm_texture =
	sfTexture_create(WIDTH / 3, HEIGHT / 3);
	minimap->fm_sprite = sfSprite_create();
	sfSprite_setTexture(
	minimap->fm_sprite, minimap->fm_texture, sfTrue);
	reset_screen(minimap->f_minimap);
}

void init_minimap(gage_t *gage, proc_t *proc)
{
	char *cur_level = int_to_str(gage->pvar.current_floor);
	char *level_string = my_strcat("Floor ", cur_level);
	sfColor trans_white = {255, 255, 255, 128};

	proc->minimap = malloc(sizeof(minimap_t));
	proc->minimap->current_level_font =
	sfFont_createFromFile("ressources/OpenSans.ttf");
	proc->minimap->current_level_text = sfText_create();
	sfText_setString(proc->minimap->current_level_text, level_string);
	sfText_setFont(proc->minimap->current_level_text,
	proc->minimap->current_level_font);
	sfText_setColor(proc->minimap->current_level_text, trans_white);
	sfText_setCharacterSize(proc->minimap->current_level_text, 12);
	init_minimap_framebuffers(proc->minimap);
	free(cur_level);
	free(level_string);
}

void draw_minimap(proc_t *proc)
{
	sfVector2f player_pos_b = proc->gman->player.pos;
	sfVector2f player_pos_m = proc->gman->player.pos;

	player_pos_b.x -= WIDTH / 5;
	player_pos_b.y -= HEIGHT / 5;
	player_pos_m.x -= WIDTH / 6;
	player_pos_m.y -= HEIGHT / 6;
	sfTexture_updateFromPixels(proc->minimap->fb_texture,
	proc->minimap->f_background->pixels, WIDTH / 2.5, HEIGHT / 2.5, 0, 0);
	sfTexture_updateFromPixels(proc->minimap->fm_texture,
	proc->minimap->f_minimap->pixels, WIDTH / 3, HEIGHT / 3, 0, 0);
	sfSprite_setPosition(proc->minimap->fb_sprite, player_pos_b);
	sfSprite_setPosition(proc->minimap->fm_sprite, player_pos_m);
	sfRenderWindow_drawSprite(
	proc->gman->window, proc->minimap->fb_sprite, NULL);
	sfRenderWindow_drawSprite(
	proc->gman->window, proc->minimap->fm_sprite, NULL);
	sfRenderWindow_drawText(
	proc->gman->window, proc->minimap->current_level_text, NULL);
}

void verify_minimap(gage_t *gage)
{
	if (sfKeyboard_isKeyPressed(key_map) == sfTrue) {
		draw_minimap(&gage->proc);
	}
}
