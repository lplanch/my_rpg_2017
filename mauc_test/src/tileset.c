/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

void create_layers(files_t *fi)
{
	fi->map.tab_tileset = get_layer("TestMap/layers", fi);
	fi->map.layer_background = fi->map.tab_tileset[0];
	fi->map.layer_relief = fi->map.tab_tileset[1];
	fi->map.layer_colID = fi->map.tab_tileset[2];
	fi->map.layer_col = fi->map.tab_tileset[3];
	fi->map.layer_prof = fi->map.tab_tileset[4];
}

void create_images(files_t *fi)
{
	fi->map.x2 = 0;
	fi->map.image = sfImage_createFromFile("TestMap/gg.png");
	fi->map.map_backgound = sfImage_create(1920, 3200);
	fi->map.map_relief = sfImage_create(1920, 3200);
	fi->map.map_col = sfImage_create(1920, 3200);
	fi->map.map_colID = sfImage_create(1920, 3200);
	fi->map.map_prof = sfImage_create(1920, 3200);
	fi->map.square.left = 0;
	fi->map.square.top = 0;
	fi->map.square.height = 640;
	fi->map.square.width = 640;
	create_layers(fi);
}

void create_map(files_t *fi)
{
	create_images(fi);
	transfer_pixel(fi);
	set_background(fi);
	set_relief(fi);
	set_col(fi);
	set_colid(fi);
	set_prof(fi);
}
