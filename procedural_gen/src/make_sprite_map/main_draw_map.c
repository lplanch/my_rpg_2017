/*
** EPITECH PROJECT, 2018
** main_draw_map.c
** File description:
** main file to stock all functions about drawing map
*/

#include "my.h"
#include "../../include/procedural.h"

smap_t *generate_block(sfTexture *blocks, char chr, smap_t *smap)
{
	switch (chr) {
	case 'E':
	case ' ':
		make_ground_block(blocks, smap);
		break;
	case 'S':
		make_exit_block(blocks, smap);
		break;
	default:
		free(smap);
		smap = NULL;
		break;
	}
	return (smap);
}

smap_t ***create_sprite_map(proc_t *proc, char **map)
{
	smap_t ***smap = my_calloc(sizeof(smap_t **) * (count_lines(map) + 1));
	sfTexture *blocks = sfTexture_createFromFile(
	"ressources/0x72_16x16DungeonTileset.v1.png", NULL);

	proc->blocks_texture = blocks;
	for (int y = 0; map[y] != NULL; y++) {
		smap[y] = my_calloc(sizeof(smap_t *) * (my_strlen(map[y]) + 1));
		for (int x = 0; map[y][x] != '\0'; x++) {
			smap[y][x] = malloc(sizeof(smap_t));
			smap[y][x]->pos.x = x * 16;
			smap[y][x]->pos.y = y * 16;
			smap[y][x] = generate_block(blocks, map[y][x],
			smap[y][x]);
		}
	}
	return (smap);
}

void draw_map(gage_t *gage)
{
	gage->proc->smap = create_sprite_map(gage->proc, gage->proc->map);

	launch_dungeon_game(gage);
}
