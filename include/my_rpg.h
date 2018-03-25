/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** structurates
*/

#ifndef ST_RPG_
	#define ST_RPG_
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "game_object.h"
#include "projectile.h"

typedef struct struct_animation
{
	int height;
	int width;
	int c;
	int l;
	g_object *obj;
	st_time t;
	int hor;
	int ver;
	float speed;
} st_anim;

typedef struct struct_button
{
	t_object *text;
	g_object *obj;
} st_button;

typedef struct custom_data
{
	int sex;
	char *name;
	int classe;
} st_cdata;

typedef struct struct_st_custom
{
	st_cdata cdata;
	int option;
	float sens;
	int menu;
	float rot;
	int cmin;
	int cmax;
	int pos;
	int chosen;
	g_object *face;
	g_object *cursor;
	st_button *bt[5];
	g_object *circle;
	g_object *back;
} st_custom;

typedef struct aoe
{
	sfCircleShape *circle;
	int shot;
	st_time t;
	st_anim *anim;
	float duration;
} aoe_t;

typedef struct struct_archer_spells
{
	aoe_t *barrage;
	aoe_t *heal;
	int kalash;
	int current;
	float kalashspeed;
	int kalashcount;
	proj_t *arrow[20];
	proj_t *axe;
	float axeangle;
	st_anim *anim;
	st_time kal;
} archer_t;

typedef struct struct_gunner_spells
{
	int auto_a;
	int autocount;
	float autospeed;
	st_time t;
	proj_t *blitz;
	proj_t *grenade;
	float grenadespeed;
	st_anim *explosion;
	float delay;
	st_time blitzt;
	proj_t *bullet[10];
	int current;
} gunner_t;

typedef struct struct_rogue_spells
{
	proj_t *dagger[10];
	int current;
	int ultcount;
	int ulting;
	float ultspeed;
	st_time ultt;
} rogue_t;

typedef struct fight_tree
{
	int passive;
	int spell1;
	int spell2;
	int spell3;
} tree_t;

typedef struct fight_bars
{
	g_object *bars;
	g_object *life;
	g_object *xp;
} bars_t;

typedef struct main_fight
{
	st_button *icons[4];
	g_object *cd[4];
	float cdcount[4];
	float cds[4];
	st_time cdt;
	archer_t arc;
	rogue_t rog;
	gunner_t gun;
	tree_t tree;
} fight_t;

typedef struct struct_main_menu
{
	sfMusic *music;
	int menu;
	st_time t;
	int option;
	int sens;
	st_button *button[4];
	g_object *cursor;
	g_object *rope;
	g_object *first;
	g_object *abyss[2];
	g_object *rockback[2];
	g_object *rock2[2];
} st_menu;

typedef struct struct_rpg
{
	fight_t f;
	bars_t bar;
	g_object *loading;
	int returnv;
	st_custom cust;
	st_menu mainm;
	sfRenderWindow *window;
} st_rpg;

void rogue_update_storm(st_rpg *s);
void display_projectile(sfRenderWindow *window, proj_t *proj);
sfCircleShape *create_circle(int radius, int thickness, sfColor color);
void launch_aoe(sfRenderWindow *window, aoe_t *aoe);
void display_aoe(sfRenderWindow *window, aoe_t *aoe);
void update_aoe(aoe_t *aoe);
void destroy_aoe(aoe_t *aoe);
aoe_t *create_aoe(sfCircleShape *circle, st_anim *anim, float duration);
void update_life_bar(st_rpg *s);
void display_life_bar(st_rpg *s);
void destroy_life_bar(st_rpg *s);
void create_life_bar(st_rpg *s);
void gunner_update_blitz(st_rpg *s);
void gunner_update_grenade(st_rpg *s);
void get_cooldowns(st_rpg *s);
void archer_auto_attack(st_rpg *s);
void gunner_auto_attack(st_rpg *s);
void rogue_auto_attack(st_rpg *s);
void warrior_auto_attack(st_rpg *s);
void gunner_update_auto_attack(st_rpg *s);
void update_axe(st_rpg *s);
void update_aoe_barrage(st_rpg *s);
void update_kalash(st_rpg *s);
void update_current_arrow(st_rpg *s);
void destroy_class(st_rpg *s);
void launch_spells(st_rpg *s);
void choose_spell1_archer(st_rpg *s);
void choose_spell2_archer(st_rpg *s);
void choose_spell3_archer(st_rpg *s);
void choose_spell1_gunner(st_rpg *s);
void choose_spell2_gunner(st_rpg *s);
void choose_spell3_gunner(st_rpg *s);
void choose_spell1_rogue(st_rpg *s);
void choose_spell2_rogue(st_rpg *s);
void choose_spell3_rogue(st_rpg *s);
void choose_spell1_warrior(st_rpg *s);
void choose_spell2_warrior(st_rpg *s);
void choose_spell3_warrior(st_rpg *s);
void update_class(st_rpg *s);
void display_class(st_rpg *s);
void destroy_icons_cd(st_rpg *s);
void update_cdcount_icons(st_rpg *s, int i);
void update_icons_cd(st_rpg *s);
void create_icons_cd(st_rpg *s);
void create_class(st_rpg *s);
void destroy_spells_gunner(st_rpg *s);
void destroy_spells_archer(st_rpg *s);
void display_icons(st_rpg *s);
void destroy_icons(st_rpg *s);
char *which_spell(st_rpg *s, int spell);
char *get_spell_path(st_rpg *s, int spell);
void create_icons(st_rpg *s);
sfVector2f get_ratios(float angle);
float get_angle(sfRenderWindow *window);
int fight_instance(st_rpg *s);
void launch_projectile(proj_t *proj, float angle);
void loading(st_rpg *s);
int cust_left_clicked(st_rpg *s, sfEvent event);
void cust_menu_goto_name(st_rpg *s);
void cust_menu_goto_classes(st_rpg *s);
void cust_menu_goto_sex(st_rpg *s);
int cust_menu_backto_main(st_rpg *s);
void display_cust(st_rpg *s);
void destroy_cust_buttons(st_rpg *s);
void custom_destroy(st_rpg *s);
void create_st_custom(st_rpg *s);
void custom_manage_cursor_events_mouse(st_rpg *s);
void custom_manage_cursor_events_key(st_rpg *s, sfEvent event);
void cust_cursor_animation(st_rpg *s);
void get_cursor_pos_classes(st_rpg *s);
void get_cursor_pos(st_rpg *s);
int custom_launch(st_rpg *s, sfEvent event);
int cust_get_buttons(int menu);
int cust_minx_buttons(int menu);
int cust_maxx_buttons(int menu);
int cust_miny_buttons(int menu);
int cust_maxy_buttons(int menu);
int custom_main(st_rpg *s);
int event_main_menu(st_rpg *s);
int launch_main_menu_options(st_rpg *s);
int launch_main_menu_create_slots(st_rpg *s);
int launch_main_menu_main(st_rpg *s);
int launch_main_menu_saves(st_rpg *s);
void main_menu_goto_main(st_rpg *s);
void main_menu_goto_slots(st_rpg *s);
void main_menu_goto_saves(st_rpg *s);
void main_menu_goto_options(st_rpg *s);
int get_max_buttons(st_rpg *s);
void destroy_main_menu(st_rpg *s);
void initialize_menu(st_rpg *s);
int left_clicked_on_buttons(st_rpg *s, sfEvent event);
st_time create_st_time(void);
void destroy_anim(st_anim *anim);
st_anim *create_anim(g_object *obj, sfVector2i max, float speed);
void clocked_animation(st_anim *anim);
int mouse_in_object(g_object *obj, sfRenderWindow *window);
st_button *create_button(char *str, g_object *object, sfColor c, int size);
st_button *create_vbutton(char *str, sfVector2f pos, sfColor c, int size);
void destroy_button(st_button *button);
void movement_mainm(st_rpg *s);
void destroy_main_menu(st_rpg *s);
int main_menu(st_rpg *s);
void display_menu_background(st_rpg *s);
int main_menu_cutscene(st_rpg *s);
sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f create_vector2f(float x, float y);
sfVector2i create_vector2i(int x, int y);

#endif
