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

	gman->minimap->f_background = framebuffer_create(WIDTH / 3, HEIGHT / 3);
	gman->minimap->fb_texture = sfTexture_create(WIDTH / 3, HEIGHT / 3);
	gman->minimap->fb_sprite = sfSprite_create();

	sfSprite_setTexture(
	gman->minimap->fb_sprite, gman->minimap->fb_texture, sfTrue);

	fill_minimap_screen(gman->minimap->f_background, sfBlack);
	gman->minimap->f_minimap = framebuffer_create(WIDTH, HEIGHT);
}

void draw_minimap(gmanager_t *gman)
{
	sfVector2f player_pos = gman->player.pos;

	player_pos.x -= WIDTH / 6;
	player_pos.y -= HEIGHT / 6;
	sfTexture_updateFromPixels(gman->minimap->fb_texture,
	gman->minimap->f_background->pixels, WIDTH / 3, HEIGHT / 3, 0, 0);
	sfSprite_setPosition(gman->minimap->fb_sprite, player_pos);
	sfRenderWindow_drawSprite(gman->window, gman->minimap->fb_sprite, NULL);
}

void verify_minimap(gage_t *gage)
{
	if (sfKeyboard_isKeyPressed(sfKeyTab) == sfTrue) {
		draw_minimap(gage->proc->gman);
	}
}
