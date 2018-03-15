##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

NAME		=	my_rpg

CC		=	cc

CFLAGS		+=	-g -Iinclude -W -Wall -Wextra

LDFLAGS		+=	-L lib/my/ -lmy -l c_graph_prog -lm

FILES		=	source/main.c				\
			source/game_object.c			\
			source/create_rect.c			\
			source/main_menu_cutscene.c		\
			source/main_menu.c			\
			source/button_generator.c		\
			source/mouse_in_object.c		\
			source/st_time.c			\
			source/animation.c			\
			source/main_menu_goto.c			\
			source/main_menu_launcher.c		\
			source/main_menu_base.c			\
			source/main_menu_events.c		\
			source/custom_main.c			\
			source/custom_get_buttons.c		\
			source/custom_base.c			\
			source/custom_goto.c			\
			source/custom_launch.c			\
			source/custom_cursor.c			\
			source/projectile.c

SRCS		=	$(FILES)

OBJ		=	$(SRCS:.c=.o) $(MAIN:.c=.o)

.PHONY: fclean clean all re debug

RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BG_COLOR	=	\033[46m

all:			$(NAME)

$(NAME):	$(OBJ)
	@echo -e '${BG_COLOR}Flags: $(LDFLAGS) $(CFLAGS)${NC}'
	@echo -e '${RED}Create${NC}: ${GREY}./$(NAME)${NC}'
	@make -C lib/my/
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o:		%.c
	@echo -e '${GREEN} [ OK ]${NC} Building : $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)


clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@make clean -C lib/my/
	@echo -e '${RED}Clean${NC} : OK'

fclean:		clean
	@rm -rf $(NAME)
	@make fclean -C lib/my/
	@echo -e '${RED}Fclean${NC}: ./$(NAME) removed'

re:		fclean all
