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

int prog(void);
int game(files_t *fi);
void draw(files_t *fi);

sfVector2f create_vector2f(float x, float y);
void characters_setup(files_t *fi);
void setup_camera(files_t *fi);
void setup_col(files_t *fi);

void move(files_t *fi);
void move_ok(files_t *fi);
void move_up(files_t *fi);
void move_down(files_t *fi);
void move_right(files_t *fi);
void move_left(files_t *fi);
void move_ID_player(files_t *fi);

int collision(files_t *fi);
int check_colcircle(files_t *fi, int nbr);
int check_colsquare(files_t *fi, int nbr);
int collision_ID(files_t *fi);

int **get_layer(char *name);
void create_map(files_t *fi);
void parsing(struct stat a, files_t *fi);

void free_tab(char **tab, int y);
void free_all(files_t *fi);

#ifndef MY_COOK_
#define MY_COOK_

#endif
