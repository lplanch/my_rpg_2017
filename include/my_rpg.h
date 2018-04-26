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
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "game_object.h"
#include "projectile.h"

typedef struct struct_music
{
	sfMusic *music;
	int volume;
} st_music;

typedef struct struct_button
{
	t_object *text;
	g_object *obj;
} st_button;

typedef struct s_clock
{
	sfClock *clock;
	sfTime tmp;
	float seconds;
} clockz_t;

typedef struct s_pnj
{
	char *name;
	st_button *name_box;
	st_button *dialog_box;
	g_object *pnj;
	g_object *choice_box_edge[2];
	g_object *cursor;
	st_button **choice_box;
} pnj_t;

typedef struct s_pos
{
	int x;
	int y;
} pos_t;

typedef struct s_map
{
	int x;
	int x2;
	int y;
	int **tab_tileset;
	int *layer_background;
	int *layer_relief;
	int *layer_col;
	int *layer_colID;
	int *layer_prof;
	sfImage *image;
	sfImage *map_backgound;
	sfImage *map_relief;
	sfImage *map_col;
	sfImage *map_colID;
	sfImage *map_prof;
	sfSprite *sprite;
	sfTexture *texture;
	sfSprite *sprite2;
	sfTexture *texture2;
	sfSprite *sprite3;
	sfTexture *texture3;
	sfSprite *sprite4;
	sfTexture *texture4;
	sfSprite *sprite5;
	sfTexture *texture5;
	sfIntRect square;
	sfColor color;
} map_t;

typedef struct s_rewards
{
	char **objects;
	int money;
	int xp;
} rewards_t;

typedef struct s_farm_quests
{
	char *name_item;
	int nbr_item;
} farm_quests_t;

typedef struct s_kill_quests
{
	char *name_kill;
	int nbr_kill;
} kill_quests_t;

typedef struct s_go_quests
{
	char *name_place;
} go_quests_t;

typedef struct s_speak_quests
{
	char *name_character;
} speak_quests_t;

typedef struct s_quests_list
{
	int type;
	farm_quests_t farm_quests;
	kill_quests_t kill_quests;
	go_quests_t go_quests;
	speak_quests_t speak_quests;
	struct s_quests_list *next;
} quests_list_t;

typedef struct s_quests
{
	char *title;
	char *path;
	int nbr_quests;
	int status;

	rewards_t rewards;
	quests_list_t *quests_list;
} quests_t;

typedef struct s_colsquare
{
	pos_t pos;
	int width;
	int height;
} colsquare_t;

typedef struct s_quests_box
{
	int nb_quests;
	int status;
	st_button *quests_box;
	st_button *quests_des;
} quests_box_t;

typedef struct s_colcircle
{
	int rayon_circle;
	int center_circle_x;
	int center_circle_y;
} colcircle_t;

typedef struct s_files
{
	int direction;
	int nbr_colcircle;
	int nbr_colsquare;
	int camera_pos;
	int dialog_box_isopen;
	int nb_pnj;
	int max_pnj;
	int choice_cursor;
	int var_choice;
	int nb_choice_pre;
	int loading_timer;
	int pre_var;
	int relief;
	sfClock *clock;
	sfView *view;
	quests_t **quests;
	g_object *character;
	g_object *ID_character;
	g_object *loading;
	quests_box_t quests_box;
	sfVector2f camera;
	sfVector2f camera_prec;
	sfVector2f speed;
	sfVector2f velocity;
	sfVector2f invers;
	sfVector2f maxspeed;
	sfVector2f vect_ID_player;
	pnj_t pnj[4];
	pos_t pos[10];
	colcircle_t colcircle[42];
	colsquare_t colsquare[204];
	map_t map;
	clockz_t time;
	st_music music;
} files_t;

typedef struct struct_animation
{
	int height;
	int width;
	int c;
	int li;
	g_object *obj;
	st_time t;
	int hor;
	int ver;
	float speed;
} st_anim;

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
	st_anim *anim;
	char *effect;
	float dmg;
	float dmgratio;
	float duration;
	float count;
} aoe_t;

typedef struct effect
{
	float duration;
	float count;
	char *type;
	int amount;
} effect_t;

typedef struct struct_archer_spells
{
	aoe_t *barrage;
	aoe_t *heal;
	effect_t *leaf;
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
	sfCircleShape *explo;
	float grenadespeed;
	st_anim *explosion;
	st_anim *expbullet;
	sfCircleShape *expbt;
	float delay;
	st_time blitzt;
	proj_t *bullet[10];
	int current;
	int ult;
	proj_t *ultb[10];
	g_object *trait[10];
	sfVector2f ultrat;
	int dmg;
	int origin;
} gunner_t;

typedef struct struct_melee_swing
{
	float begin;
	float angle;
	float count;
	float speed;
	int dmg;
	int dmgratio;
	int able;
	int shot;
	int sens;
	sfVector2f scale;
	st_time t;
} swing_t;

typedef struct struct_rogue_spells
{
	proj_t *dagger[30];
	aoe_t *zone;
	float vanish;
	float ultangle;
	int side;
	int auto_bool;
	int current;
	int ultcount;
	int ulting;
	float ultspeed;
	int bstab;
	float bcount;
	st_button *backstab;
	sfVector2f bpos[2];
	sfVector2f brat;
	float bdmg;
	st_time ultt;
	proj_t *dance;
	swing_t *auto_a[2];
} rogue_t;

typedef struct struct_warrior_spells
{
	swing_t *auto_a;
	swing_t *whirl;
	proj_t *hasagi;
	sfVector2f hpos;
	sfVector2f hrat;
	float hdmg;
	aoe_t *shield;
	int estoc;
	float count;
} warrior_t;

typedef struct fight_tree
{
	int lock[10];
	int passive;
	int spell1;
	int spell2;
	int spell3;
	int skillp;
} tree_t;

typedef struct struct_stat_entity
{
	int pvm;
	int pva;
	int frc;
	int def;
	int prc;
	int vit;
	int cha;
	int exp;
	int lvl;
} stat_t;

typedef struct fight_bars
{
	g_object *bars;
	g_object *life;
	g_object *xp;
	t_object *values[3];
} bars_t;

typedef struct enemy
{
	g_object *obj;
	g_object *life;
	stat_t *stat;
} enemy_t;

typedef struct main_fight
{
	enemy_t *mob;
	st_button *icons[4];
	g_object *cd[4];
	g_object *locks[3];
	float cdcount[4];
	float cds[4];
	int cast;
	st_time cdt;
	st_time proc;
	archer_t arc;
	rogue_t rog;
	gunner_t gun;
	warrior_t war;
} fight_t;

typedef struct struct_status_menu
{
	int show;
	g_object *window;
	g_object *face;
	st_button *classe;
	st_button *stats[6];
	t_object *lvl;
	t_object *exp;
	t_object *name;
} status_menu_t;

typedef struct status_tree_menu
{
	char **spells;
	int status;
	g_object *window;
	st_button *classe;
	t_object *skillp;
	g_object *pas[3];
	g_object *m2[3];
	g_object *e[2];
	g_object *r[2];
	g_object *select[4];
	g_object *lock[10];
	t_object *sp[4];
} tree_menu_t;

typedef struct struct_main_menu
{
	sfMusic *music;
	int menu;
	int create;
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
	g_object *guy;
	g_object *title;
} st_menu;

typedef struct struct_pause_menu
{
	int sens;
	int menu;
	int option;
	st_button *title;
	st_button *button[5];
	g_object *cursor;
	g_object *window;
} pause_menu_t;

typedef struct struct_player_info
{
	stat_t *stat;
	tree_t tree;
	st_cdata cdata;
	g_object *obj;
	g_object *weapon[2];
} player_t;

typedef struct struct_rpg
{
	fight_t f;
	bars_t bar;
	player_t player;
	status_menu_t statm;
	tree_menu_t treem;
	pause_menu_t pausm;
	g_object *center;
	g_object *loading;
	int returnv;
	st_custom cust;
	st_menu mainm;
	int save;
	files_t *fi;
	sfRenderWindow *window;
} st_rpg;

void my_set_string(sfText *text, char *str);
char *get_stat_string(int i);
char *get_stat_value(st_rpg *s, int i);
void update_status_menu(st_rpg *s);
void display_locked_spells(st_rpg *s);
void display_locked_spells_cd(st_rpg *s);
void update_cursor_pos_pause(st_rpg *s);
void set_colors_pause(st_rpg *s);
void which_update(st_rpg *s);
void display_fight(st_rpg *s);
void cursor_animation_pause(st_rpg *s, int min, int max);
void update_status_menu(st_rpg *s);
int pause_main(st_rpg *s);
void which_display(st_rpg *s);
int left_clicked_on_pause(st_rpg *s, sfEvent event);
int which_pause_menu(st_rpg *s);
void update_pause_menu(st_rpg *s);
void display_pause_menu(st_rpg *s);
void destroy_pause_menu(st_rpg *s);
void generate_pause_menu(st_rpg *s);
char *get_tree_path(st_rpg *s, int spell, int number);
void select_spell(st_rpg *s, int lock);
char **get_spinfo(st_rpg *s);
void tree_set_rects(st_rpg *s);
void update_tree_pos(st_rpg *s);
void generate_tree_menu(st_rpg *s);
void tree_proceed(st_rpg *s, int lock);
void display_object(sfRenderWindow *window, g_object *object);
void game_update(st_rpg *s);
void update_tree_menu(st_rpg *s);
char *get_class_string(int i);
void generate_tree_menu(st_rpg *s);
void destroy_tree_menu(st_rpg *s);
void display_tree_menu(st_rpg *s);
int prog(st_rpg *s);
void update_menu_stat_mouse_over(st_rpg *s);
void destroy_status_menu(st_rpg *s);
void display_status_menu(st_rpg *s);
void generate_status_menu(st_rpg *s);
void display_button(sfRenderWindow *window, st_button *button);
char *get_save_path(st_rpg *s);
void save_stat(stat_t *stat, char *path);
void save_game(st_rpg *s);
void write_a_value(int fd, char *value, int len);
void save_tree(tree_t tree, char *path);
void rogue_backstab(st_rpg *s);
void handle_invulnerability_lifesteal(st_rpg *s, float amount, char *effect);
void handle_explosive(st_rpg *s, proj_t *proj);
void handle_bounce(proj_t *proj);
void handle_pierce(proj_t *proj);
void rogue_update_auto_attack(st_rpg *s);
void update_pos_weapon(st_rpg *s);
void destroy_player(st_rpg *s);
int check_double_class(st_rpg *s);
void display_player(st_rpg *s);
void create_player_from_cust(st_rpg *s);
void proc_effects(st_rpg *s);
void proc_effect(effect_t *effect);
void destroy_effect(effect_t *effect);
effect_t *create_effect(char *type, int amount, float duration);
void warrior_update_hasagi(st_rpg *s);
void gunner_update_ultimate(st_rpg *s);
void warrior_update_auto_attack(st_rpg *s);
void swing_damage_enemy(st_rpg *s, swing_t *swing, enemy_t *mob);
swing_t *create_swing_from_file(char *path);
void destroy_swing(swing_t *swing);
void update_swing(st_rpg *s, swing_t *swing, g_object *obj);
void launch_swing(sfRenderWindow *window, swing_t *swing, g_object *obj);
void create_weapon(st_rpg *s);
void update_effects(st_rpg *s);
void apply_aoe(st_rpg *s, aoe_t *aoe, enemy_t *mob);
void proc_aoe(st_rpg *s, aoe_t *aoe);
void proc_aoes(st_rpg *s);
aoe_t *create_aoe_from_file(char *path);
void apply_projectile(st_rpg *s, proj_t *proj, enemy_t *mob);
void projectile_damage_enemy(st_rpg *s, proj_t *proj, enemy_t *mob);
int circle_hitbox(sfCircleShape *circle, g_object *target);
int hitbox(g_object *attack, g_object *target);
void update_projectiles(st_rpg *s);
void create_mob_example(st_rpg *s);
void update_mob_example(st_rpg *s);
void destroy_mob_example(st_rpg *s);
void display_mob_example(st_rpg *s);
void load_tree(st_rpg *s, char *path);
void heal(st_rpg *s, int amount);
void load_save(st_rpg *s);
int launch_main_menu_load_slots(st_rpg *s);
void create_first_tree(st_rpg *s);
stat_t *load_stat(char *path);
stat_t *create_first_stat(void);
void update_bars(st_rpg *s);
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
void cust_menu_togo_name(st_rpg *s);
void cust_menu_togo_classes(st_rpg *s);
void cust_menu_togo_sex(st_rpg *s);
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
void main_menu_togo_main(st_rpg *s);
void main_menu_togo_slots(st_rpg *s);
void main_menu_togo_saves(st_rpg *s);
void main_menu_togo_options(st_rpg *s);
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
