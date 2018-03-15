/*
** EPITECH PROJECT, 2018
** minimap_system.c
** File description:
** make minimap on screen
*/

#include "my.h"
#include "../../include/procedural.h"

void init_minimap(gmanager_t *gman)
{
	gman->minimap = malloc(sizeof(minimap_t));

	gman->minimap->f_background = framebuffer_create(WIDTH / 2.5, HEIGHT / 2.5);
	gman->minimap->fb_texture = sfTexture_create(WIDTH / 2.5, HEIGHT / 2.5);
	gman->minimap->fb_sprite = sfSprite_create();
	sfSprite_setTexture(
	gman->minimap->fb_sprite, gman->minimap->fb_texture, sfTrue);
	fill_minimap_screen(gman->minimap->f_background, sfBlack);

	gman->minimap->f_minimap = framebuffer_create(WIDTH, HEIGHT);
	gman->minimap->fm_texture = sfTexture_create(WIDTH / 3, HEIGHT / 3);
	gman->minimap->fm_sprite = sfSprite_create();
	sfSprite_setTexture(
	gman->minimap->fm_sprite, gman->minimap->fm_texture, sfTrue);
	fill_minimap_screen(gman->minimap->f_minimap, sfWhite);
}

void draw_minimap(gmanager_t *gman)
{
	sfVector2f player_pos_b = gman->player.pos;
	sfVector2f player_pos_m = gman->player.pos;

	player_pos_b.x -= WIDTH / 5;
	player_pos_b.y -= HEIGHT / 5;
	player_pos_m.x -= WIDTH / 6;
	player_pos_m.y -= HEIGHT / 6;
	sfTexture_updateFromPixels(gman->minimap->fb_texture,
	gman->minimap->f_background->pixels, WIDTH / 2.5, HEIGHT / 2.5, 0, 0);
	sfTexture_updateFromPixels(gman->minimap->fm_texture,
	gman->minimap->f_minimap->pixels, WIDTH / 3, HEIGHT / 3, 0, 0);
	sfSprite_setPosition(gman->minimap->fb_sprite, player_pos_b);
	sfSprite_setPosition(gman->minimap->fm_sprite, player_pos_m);
	sfRenderWindow_drawSprite(gman->window, gman->minimap->fb_sprite, NULL);
	sfRenderWindow_drawSprite(gman->window, gman->minimap->fm_sprite, NULL);
}

void verify_minimap(gage_t *gage)
{
	if (sfKeyboard_isKeyPressed(sfKeyTab) == sfTrue) {
		draw_minimap(gage->proc->gman);
	}
}
