/*
** EPITECH PROJECT, 2018
** ingame_struct.h
** File description:
** file to stock all struct about game
*/

//INVENTORY
typedef struct inventory_item
{
	unsigned int id;
	unsigned int stacks;
	item_t *next;
} item_t;

typedef struct ingame_inventory_manager
{
	unsigned int size;
	unsigned int money;
	item_t *first_slot;
	item_t *armor;
} ing_inv_t;

//PLAYER INGAME STATUS
typedef struct ingame_player_status
{
	unsigned int healing;
	unsigned int poison;
	unsigned int stun;
	unsigned int acceleration;
	unsigned int invincible;
	unsigned int vanish;
} ing_status_t;

//PLAYER INGAME MANAGER
typedef struct ingame_player
{
	unsigned int hpm;
	unsigned int exp;
	unsigned int level;
	ing_status_t status;
	unsigned int attack;
	unsigned int armor;
	unsigned int luck;
	unsigned int speed;
} ing_player_t;

typedef struct ingame_struct
{
	ing_player_t player;
	ing_inv_t inventory;
} ingame_t;
