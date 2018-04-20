/*
** EPITECH PROJECT, 2018
** set_pixeltoimage.c
** File description:
** set_pixeltoimage.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void set_background(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture =
	sfTexture_createFromImage(fi->map.map_backgound, NULL);
	fi->map.sprite = sfSprite_create();
	sfSprite_scale(fi->map.sprite, invers);
	sfSprite_setTextureRect(fi->map.sprite, fi->map.square);
	sfSprite_setTexture(fi->map.sprite, fi->map.texture, sfTrue);
}

void set_relief(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture5 = sfTexture_createFromImage(fi->map.map_relief, NULL);
	fi->map.sprite5 = sfSprite_create();
	sfSprite_scale(fi->map.sprite5, invers);
	sfSprite_setTextureRect(fi->map.sprite5, fi->map.square);
	sfSprite_setTexture(fi->map.sprite5, fi->map.texture5, sfTrue);
}

void set_col(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture2 = sfTexture_createFromImage(fi->map.map_col, NULL);
	fi->map.sprite2 = sfSprite_create();
	sfSprite_scale(fi->map.sprite2, invers);
	sfSprite_setTextureRect(fi->map.sprite2, fi->map.square);
	sfSprite_setTexture(fi->map.sprite2, fi->map.texture2, sfTrue);
}

void set_colid(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture3 = sfTexture_createFromImage(fi->map.map_colID, NULL);
	fi->map.sprite3 = sfSprite_create();
	sfSprite_scale(fi->map.sprite3, invers);
	sfSprite_setTextureRect(fi->map.sprite3, fi->map.square);
	sfSprite_setTexture(fi->map.sprite3, fi->map.texture3, sfTrue);
}

void set_prof(files_t *fi)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	fi->map.texture4 = sfTexture_createFromImage(fi->map.map_prof, NULL);
	fi->map.sprite4 = sfSprite_create();
	sfSprite_scale(fi->map.sprite4, invers);
	sfSprite_setTextureRect(fi->map.sprite4, fi->map.square);
	sfSprite_setTexture(fi->map.sprite4, fi->map.texture4, sfTrue);
}
