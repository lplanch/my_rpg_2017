/*
** EPITECH PROJECT, 2018
** minimap_system.c
** File description:
** make minimap on screen
*/

#include "my.h"
#include "../../include/procedural.h"

void init_minimap(proc_t *proc)
{
	proc->minimap = malloc(sizeof(minimap_t));

	proc->minimap->f_background =
	framebuffer_create(WIDTH / 2.5, HEIGHT / 2.5);
	proc->minimap->fb_texture =
	sfTexture_create(WIDTH / 2.5, HEIGHT / 2.5);
	proc->minimap->fb_sprite = sfSprite_create();
	sfSprite_setTexture(
	proc->minimap->fb_sprite, proc->minimap->fb_texture, sfTrue);
	fill_minimap_screen(proc->minimap->f_background, sfBlack);

	proc->minimap->f_minimap =
	framebuffer_create(WIDTH / 3, HEIGHT / 3);
	proc->minimap->fm_texture =
	sfTexture_create(WIDTH / 3, HEIGHT / 3);
	proc->minimap->fm_sprite = sfSprite_create();
	sfSprite_setTexture(
	proc->minimap->fm_sprite, proc->minimap->fm_texture, sfTrue);
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
	sfRenderWindow_drawSprite(proc->gman->window, proc->minimap->fb_sprite, NULL);
	sfRenderWindow_drawSprite(proc->gman->window, proc->minimap->fm_sprite, NULL);
}

void verify_minimap(gage_t *gage)
{
	if (sfKeyboard_isKeyPressed(sfKeyTab) == sfTrue) {
		draw_minimap(gage->proc);
	}
}
