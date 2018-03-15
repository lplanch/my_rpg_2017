/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing file for my_rpg
*/

#include "my.h"
#include "my_rpg.h"

int tab_circle(char **tab, int i, files_t *fi, int circle)
{
	fi->colcircle[circle].rayon_circle = ((str_to_int(tab[i]) / 100) / 2) * 5;
	i++;
	fi->colcircle[circle].center_circle_x =
	((str_to_int(tab[i]) / 100) * 5) + fi->colcircle[circle].rayon_circle;
	i++;
	fi->colcircle[circle].center_circle_y =
	((str_to_int(tab[i]) / 100) * 5)+ fi->colcircle[circle].rayon_circle;
	i++;
	return (i);
}

int tab_square(char **tab, int i, files_t *fi, int square)
{
	fi->colsquare[square].pos.x = (str_to_int(tab[i]) / 100) * 5;
	i++;
	fi->colsquare[square].pos.y = (str_to_int(tab[i]) / 100) * 5;
	i++;
	fi->colsquare[square].width = (str_to_int(tab[i]) / 100) * 5;
	i++;
	fi->colsquare[square].height = (str_to_int(tab[i]) / 100) * 5;
	i++;
	return (i);
}

void tab_to_struct(files_t *fi, char **tab, int y)
{
	int compter = 0;
	int circle = 0;
	int square = 0;
	int i = 0;

	while (compter != 145) { //633
		if (my_strcmp("yes", tab[i]) == 0) {
			i++;
			i = tab_circle(tab, i, fi, circle);
			circle++;
		} else if (my_strcmp("no", tab[i]) == 0) {
			i++;
			i = tab_square(tab, i, fi, square);
			square++;
		}
		compter++;
	}
	free_tab(tab, y);
}

void parsing2(int y, files_t *fi, char *str)
{
	int i = 0;
	int x = 0;
	int a = 0;
	char **tab = my_calloc(sizeof(char *) * y + 1);

	while (a != y) {
		x = 0;
		tab[a] = my_calloc(sizeof(char) * 6 + 1);
		while (str[i] != '\n' && str[i] != 0) {
			tab[a][x] = str[i];
			i++;
			x++;
		}
		tab[a][x] = '\0';
		i++;
		a++;
	}
	free (str);
	tab_to_struct(fi, tab, y);
}

void parsing(struct stat a, files_t *fi)
{
	int i = 0;
	int y = 0;
	int k = 0;
	int len = 0;
	int file = open("TestMap/parsing", O_RDONLY);
	char *buff = my_calloc(sizeof(char) * a.st_size + 1);
	char *str = my_calloc(sizeof(char) * a.st_size + 1);

	while ((len = read(file, buff, a.st_size))) {
		buff[len] = 0;
		if (len == 0)
			break;
		for (int i = 0; buff[i]; i++) {
			str[k++] = buff[i];
			if (buff[i] == 10)
				y++;
		}
	}
	str[k] = 0;
	parsing2(y, fi, str);
	free (buff);
}
