##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

NAME		=	my_rpg

CC		=	cc

CFLAGS		+=	-g -I include/

LDFLAGS		+=	-L lib/my/ -lmy -l c_graph_prog -lm

FILES		=	main.c				\
			src/collision.c			\
			src/collision_prog.c		\
			src/game.c			\
			src/move.c			\
			src/move_prog.c			\
			src/prog.c			\
			src/setup.c			\
			src/setup2.c			\
			src/tileset.c			\
			src/parsing.c			\
			src/lib_func.c			\
			src/get_layer.c			\
			src/free.c			\
			src/player_movement.c		\

SRCS		=	$(FILES)

OBJ		=	$(SRCS:.c=.o) $(MAIN:.c=.o)

all:			$(NAME)


.PHONY: fclean clean all re

RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BG_COLOR	=	\033[46m

$(NAME):	$(OBJ)
	@echo -e '${BG_COLOR}Flags: $(LDFLAGS) $(CFLAGS)${NC}'
	@echo -e '${RED}Create${NC}: ${GREY}./$(NAME)${NC}'
	@make -C lib/my/
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o:		%.c
	@echo -e '${GREEN} [ OK ]${NC} Build $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)


clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@echo -e '${RED}Clean${NC} : OK'
	@make clean -C lib/my/

fclean:		clean
	@rm -rf $(NAME)
	@echo -e '${RED}Fclean${NC}: ./$(NAME) removed'
	@make fclean -C lib/my/

re:		fclean all
