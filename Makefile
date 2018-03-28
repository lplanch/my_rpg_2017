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
			source/projectile.c			\
			source/get_angles.c			\
			source/fight.c				\
			source/fight_create_spells.c		\
			source/fight_destroy_spells.c		\
			source/fight_icons.c			\
			source/fight_icons_cd.c			\
			source/fight_display_class.c		\
			source/fight_update_class.c		\
			source/fight_auto_attacks.c		\
			source/fight_launch_spells.c		\
			source/fight_get_cooldowns.c		\
			source/spells_archer_1.c		\
			source/spells_archer_2.c		\
			source/spells_archer_3.c		\
			source/spells_gunner_1.c		\
			source/spells_gunner_2.c		\
			source/spells_gunner_3.c		\
			source/spells_rogue_1.c			\
			source/spells_rogue_2.c			\
			source/spells_rogue_3.c			\
			source/spells_warrior_1.c		\
			source/spells_warrior_2.c		\
			source/spells_warrior_3.c		\
			source/update_spells_archer_1.c		\
			source/update_spells_gunner_1.c		\
			source/update_spells_rogue_1.c		\
			source/life_bar.c			\
			source/aoe.c				\
			source/create_circle.c			\
			source/display_projectile.c		\
			source/create_stat.c			\
			source/create_tree.c			\
			source/heal.c				\
			source/load_save.c			\
			source/mob_example.c			\
			source/hitbox.c				\
			source/update_effects.c			\
			source/update_projectiles.c		\
			source/apply_damage.c			\
			source/proc_aoes.c

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
	@echo -e '${GREEN}Create${NC}: ${GREY}./$(NAME)${NC}'
	@make --no-print-directory -C lib/my/
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
