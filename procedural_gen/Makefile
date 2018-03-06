##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

NAME		=	proc

CC		=	cc

CFLAGS		+=	-g -I ../include/

LDFLAGS		+=	-L ../lib/my/ -lmy -l c_graph_prog

FILES		=	src/main_proc.c					\
			src/make_array/map_creation.c			\
			src/make_array/verify_collide.c			\
			src/make_array/corridors.c			\
			src/make_array/mandatory_blocks.c		\
			src/draw_map/main_draw_map.c			\

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
	@make -C ../lib/my/
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o:		%.c
	@echo -e '${GREEN} [ OK ]${NC} Building proc : $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)


clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@make clean -C ../lib/my/
	@echo -e '${RED}Clean proc${NC} : OK'

fclean:		clean
	@rm -rf $(NAME)
	@make fclean -C ../lib/my/
	@echo -e '${RED}Fclean proc${NC}: ./$(NAME) removed'

re:		fclean all
