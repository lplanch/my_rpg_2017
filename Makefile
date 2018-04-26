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

FILES		=	source/main.c					\
			source/graphic/create_rect.c			\
			source/graphic/game_object.c			\
			source/graphic/mouse_in_object.c		\
			source/graphic/create_circle.c			\
			source/graphic/st_time.c			\
			source/graphic/animation.c			\
			source/graphic/get_angles.c			\
			source/main_menu/main.c				\
			source/main_menu/cutscene.c			\
			source/main_menu/togo.c				\
			source/main_menu/launcher.c			\
			source/main_menu/base.c				\
			source/main_menu/events.c			\
			source/custom/main.c				\
			source/custom/get_buttons.c			\
			source/custom/base.c				\
			source/custom/togo.c				\
			source/custom/to_player.c			\
			source/custom/launch.c				\
			source/custom/cursor.c				\
			source/fight/main.c				\
			source/fight/projectile.c			\
			source/fight/create_spells.c			\
			source/fight/destroy_spells.c			\
			source/fight/icons.c				\
			source/fight/icons_cd.c				\
			source/fight/display_class.c			\
			source/fight/update_class.c			\
			source/fight/auto_attacks.c			\
			source/fight/launch_spells.c			\
			source/fight/locked_spells.c			\
			source/fight/get_cooldowns.c			\
			source/fight/aoe.c				\
			source/fight/display_projectile.c		\
			source/fight/heal.c				\
			source/fight/mob_example.c			\
			source/fight/hitbox.c				\
			source/fight/update_effects.c			\
			source/fight/update_projectiles.c		\
			source/fight/apply_damage.c			\
			source/fight/proc_aoes.c			\
			source/fight/create_weapon.c			\
			source/fight/update_weapon_pos.c		\
			source/fight/swing.c				\
			source/fight/effect.c				\
			source/fight/proc_effects.c			\
			source/fight/projectile_effects.c		\
			source/spells/archer_1.c			\
			source/spells/archer_2.c			\
			source/spells/archer_3.c			\
			source/spells/gunner_1.c			\
			source/spells/gunner_2.c			\
			source/spells/gunner_3.c			\
			source/spells/rogue_1.c				\
			source/spells/rogue_2.c				\
			source/spells/rogue_3.c				\
			source/spells/warrior_1.c			\
			source/spells/warrior_2.c			\
			source/spells/warrior_3.c			\
			source/spells/update_archer_1.c			\
			source/spells/update_gunner_1.c			\
			source/spells/update_rogue_1.c			\
			source/spells/update_warrior_1.c		\
			source/interface/life_bar.c			\
			source/interface/status_menu.c			\
			source/interface/tree_menu.c			\
			source/interface/update_tree.c			\
			source/interface/pause_menu.c			\
			source/interface/pause_main.c			\
			source/interface/pause_launch.c			\
			source/interface/pause_design.c			\
			source/interface/tree_proceed.c			\
			source/interface/generate_tree_menu.c		\
			source/interface/button_generator.c		\
			source/save/create_stat.c			\
			source/save/create_tree.c			\
			source/save/write_save.c			\
			source/save/load_save.c				\
			source/player.c					\
			source/game_map/collision.c			\
			source/game_map/collision_prog.c		\
			source/game_map/collision_id.c			\
			source/game_map/game.c				\
			source/game_map/move.c				\
			source/game_map/move_prog.c			\
			source/game_map/prog.c				\
			source/game_map/setup.c				\
			source/game_map/setup2.c			\
			source/game_map/remalloc_tab.c			\
			source/game_map/tileset.c			\
			source/game_map/parsing_tab_to.c		\
			source/game_map/set_pixeltoimage.c		\
			source/game_map/parsing.c			\
			source/game_map/lib_func.c			\
			source/game_map/draw.c				\
			source/game_map/check_pnj.c			\
			source/game_map/zone_text_create.c		\
			source/game_map/check_pos_camera.c		\
			source/game_map/get_layer.c			\
			source/game_map/free.c				\
			source/game_map/get_pnj.c			\
			source/game_map/transfer_pixel.c		\
			source/game_map/transfer_pixel_all.c		\
			source/game_map/player_movement.c		\
			source/game_map/draw_dialog.c			\
			source/game_map/zone_text.c			\
			source/game_map/choice_box.c			\
			source/game_map/choicebox_create_event.c	\
			source/game_map/setpixel_to_image.c		\
			source/game_map/mouse_in_object_dialogbox.c	\
			source/game_map/destroy.c			\
			source/quests/create_difquests.c		\
			source/quests/get_quests_rewards.c		\
			source/quests/display_quest_with_printf.c	\
			source/quests/get_all_quests.c			\
			source/quests/check_quests.c			\
			source/quests/get_quests.c

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
