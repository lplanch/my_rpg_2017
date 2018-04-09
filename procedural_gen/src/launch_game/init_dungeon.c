/*
** EPITECH PROJECT, 2018
** init_dungeon.c
** File description:
** file to stock all functions about init struct dungeon
*/

#include "my.h"
#include "../../include/procedural.h"

void init_window(gmanager_t *gman, proc_t *proc)
{
	gman->mode.width = WIDTH;
	gman->mode.height = HEIGHT;
	gman->mode.bitsPerPixel = 32;
	gman->window = sfRenderWindow_create(gman->mode, window_name, sfClose,
	NULL);
	sfRenderWindow_setFramerateLimit(gman->window, 120);
}

void init_player(gmanager_t *gman, proc_t *proc)
{
	sfVector2f zoom = {1, 1};
	sfTexture *player_texture = sfTexture_createFromFile(
	"ressources/car2.png", NULL);

	gman->player.texture = player_texture;
	gman->player.sprite = sfSprite_create();
	gman->player.pos = get_entry_pos(proc);
	gman->player.last_pos = gman->player.pos;
	gman->player.rect.left = 0;
	gman->player.rect.top = 0;
	gman->player.rect.width = 48;
	gman->player.rect.height = 48;
	sfSprite_setTexture(gman->player.sprite, player_texture, sfTrue);
	sfSprite_setTextureRect(gman->player.sprite, gman->player.rect);
	sfSprite_setPosition(gman->player.sprite, gman->player.pos);
	sfSprite_setScale(gman->player.sprite, zoom);
}

void init_player_movement(gmanager_t *gman, proc_t *proc)
{
	gman->player.acceleration.x = 0;
	gman->player.acceleration.y = 0;
	gman->player.max_speed = 200;
	gman->player.nbr_frame.x = 0;
	gman->player.nbr_frame.y = 0;
}

void init_player_camera(gmanager_t *gman, proc_t *proc)
{
	gman->camera_pos = gman->player.pos;
	gman->camera = sfRenderWindow_getDefaultView(gman->window);
	sfView_zoom(gman->camera, 0.5);
	sfView_setCenter(gman->camera, gman->camera_pos);
	sfRenderWindow_setView(gman->window, gman->camera);
}

gmanager_t *init_dungeon_game(proc_t *proc, gage_t *gage)
{
	gmanager_t *gman = malloc(sizeof(gmanager_t));

	init_window(gman, proc);
	init_player(gman, proc);
	init_player_movement(gman, proc);
	init_player_camera(gman, proc);
	init_minimap(gage, proc);
	gman->ing = create_ingame_player();
	gman->clock = sfClock_create();
	gman->dt = 1.;
	return (gman);
}
