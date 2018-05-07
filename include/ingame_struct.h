/*
** EPITECH PROJECT, 2018
** ingame_struct.h
** File description:
** file to stock all struct about game
*/

#ifndef ING_STRUCT_H_
#define ING_STRUCT_H_

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

//INVENTORY
typedef struct inventory_item
{
	sfSprite *sprite;
	unsigned int id;
	unsigned int stacks;
	unsigned int pos;
	struct inventory_item *next;
} item_t;

typedef struct fast_inventory
{
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f created_pos;
	int created;
} ing_finv_t;

typedef struct ingame_inventory_manager
{
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect rect;
	unsigned int size;
	unsigned int money;
	item_t *first_slot;
	item_t *armor;
	item_t *weapon;
} ing_inv_t;

#endif
