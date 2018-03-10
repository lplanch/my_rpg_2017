#include <stdlib.h>

int is_num(char a)
{
       if (a > 47 && a < 58)
              return (1);
       return (0);
}

int my_getnbr_i(char const *str, int i)
{
	int f = 0;

	while (str[i] != '\0' && str[i] != '\n' && is_num(str[i]) != 0) {
		if (47 < str[i] && str[i] < 58) {
			f = (10 * f) + (str[i] - 48);
			i++;
		}
	}
	return (f);
}

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

char *my_strcat(char *str1, char *str2)
{
       int len = my_strlen(str1);
       int comp = 0;

       while(str2[comp] != '\0') {
              str1[len] = str2[comp];
              len++;
              comp++;
       }
       str1[len] = '\0';
       return (str1);
}

void my_strcpy(char *dest, char *src)
{
	int comp = 0;

	while (src[comp] != '\0') {
		dest[comp] = src[comp];
		comp = comp + 1;
	}
	dest[comp] = '\0';
}

char *my_strcat_dup(char *str1, char *str2)
{
       char *res = malloc(sizeof(char) *
my_strlen(str1) + my_strlen(str2) + 1);

       my_strcpy(res, str1);
       res = my_strcat(res, str2);
       return (res);
}
