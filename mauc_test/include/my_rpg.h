/*
** EPITECH PROJECT, 2017
** my_rpg.h
** File description:
** .h file to stock all functions from our screensaver librairy
*/

#include <dirent.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include "struct.h"

static const float speed = 3;
int prog(void);
int game(files_t *fi);
void destroy(files_t *fi);

void draw(files_t *fi);
void draw_pnj(files_t *fi);
void draw_all(files_t *fi);
void draw_dialog_box(files_t *fi);
void draw_loading(files_t *fi);
void draw_choice_menu(files_t *fi, int compter);

sfVector2f create_vector2f(float x, float y);
sfIntRect create_rect(int top, int left, int width, int height);
void characters_setup(files_t *fi);
void setup_camera(files_t *fi);
void setup_variable(files_t *fi);
void setup_loading(files_t *fi);
void setup_col(files_t *fi);
void pnj_setup(files_t *fi);
void get_all_pnj(files_t *fi, char *path);

void move(files_t *fi);
void move_camera(files_t *fi);
void move_ok(files_t *fi);
void move_up(files_t *fi);
void move_down(files_t *fi);
void move_right(files_t *fi);
void move_left(files_t *fi);
void move_allpts(files_t *fi);
void move_ID_player(files_t *fi);

int collision(files_t *fi);
int check_colcircle(files_t *fi, int nbr);
int check_colsquare(files_t *fi, int nbr);
void check_pnj(files_t *fi);
int collision_ID(files_t *fi);

int **get_layer(char *name, files_t *fi);
void create_map(files_t *fi);
void parsing(struct stat a, files_t *fi);
void update_player_position(files_t *fi);

void free_tab(char **tab, int y);
void free_all(files_t *fi);

void dialog_box(files_t *fi);
void choice_box(files_t *fi, int fd);
void destroy_button(st_button *button);
st_button *create_button(char *str, g_object *object, sfColor c, int size);
int mouse_in_object(g_object *obj, sfRenderWindow *window, files_t *fi);

#ifndef MY_COOK_
#define MY_COOK_

#endif
