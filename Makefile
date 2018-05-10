##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

NAME		=	my_rpg

CC		=	cc

CFLAGS		+=	-g -Iinclude -W -Wall -Wextra

LDFLAGS		+=	-L lib/my/ -lmy -l c_graph_prog -lm -fdiagnostics-color=always

FILES		=	source/main.c							\
			source/graphic/create_particle.c				\
			source/graphic/particle.c					\
			source/graphic/create_rect.c					\
			source/graphic/game_object.c					\
			source/graphic/mouse_in_object.c				\
			source/graphic/create_circle.c					\
			source/graphic/st_time.c					\
			source/graphic/create_shader.c					\
			source/graphic/animation.c					\
			source/graphic/get_angles.c					\
			source/main_menu/main.c						\
			source/main_menu/cutscene.c					\
			source/main_menu/togo.c						\
			source/main_menu/launcher.c					\
			source/main_menu/base.c						\
			source/main_menu/events.c					\
			source/main_menu/shader.c					\
			source/custom/main.c						\
			source/custom/get_buttons.c					\
			source/custom/base.c						\
			source/custom/togo.c						\
			source/custom/to_player.c					\
			source/custom/launch.c						\
			source/custom/cursor.c						\
			source/fight/main.c						\
			source/fight/damage/damage_show.c				\
			source/fight/damage/apply_damage.c				\
			source/fight/icons/icons.c					\
			source/fight/icons/icons_cd.c					\
			source/fight/display_class.c					\
			source/fight/update_class.c					\
			source/fight/destroy_class_sound.c				\
			source/fight/get_cooldowns.c					\
			source/fight/aoe.c						\
			source/fight/create_aoe.c					\
			source/fight/dash.c						\
			source/fight/cosmetic/diplay_player_shader.c			\
			source/fight/cosmetic/set_shader.c				\
			source/fight/projectile/projectile.c				\
			source/fight/projectile/apply_projectiles.c			\
			source/fight/projectile/display_projectile.c			\
			source/fight/projectile/update_projectiles.c			\
			source/fight/projectile/projectile_effects.c			\
			source/fight/heal.c						\
			source/fight/hitbox.c						\
			source/fight/enemies/enemy.c					\
			source/fight/enemies/aggro.c					\
			source/fight/enemies/enemy_effects.c				\
			source/fight/enemies/collisions.c				\
			source/fight/enemies/loot_enemy.c				\
			source/fight/enemies/animation.c				\
			source/fight/enemies/generate_enemy.c				\
			source/fight/enemies/base_enemies.c				\
			source/fight/effect/handle_effects.c				\
			source/fight/effect/update_effects.c				\
			source/fight/effect/handle_status.c				\
			source/fight/effect/effect.c					\
			source/fight/effect/proc_effects.c				\
			source/fight/cosmetic/update_particles.c			\
			source/fight/cosmetic/update_particles_class.c			\
			source/fight/proc_aoes.c					\
			source/fight/levelup.c						\
			source/fight/create_weapon.c					\
			source/fight/update_weapon_pos.c				\
			source/fight/swing.c						\
			source/spells/create_spells.c					\
			source/spells/launch_spells.c					\
			source/spells/locked_spells.c					\
			source/spells/create_spells_archer.c				\
			source/spells/create_spells_gunner.c				\
			source/spells/create_spells_rogue.c				\
			source/spells/create_spells_warrior.c				\
			source/spells/destroy_spells.c					\
			source/spells/auto_attacks.c					\
			source/spells/archer_1.c					\
			source/spells/archer_2.c					\
			source/spells/archer_3.c					\
			source/spells/gunner_1.c					\
			source/spells/gunner_2.c					\
			source/spells/gunner_3.c					\
			source/spells/rogue_1.c						\
			source/spells/rogue_2.c						\
			source/spells/rogue_3.c						\
			source/spells/warrior_1.c					\
			source/spells/warrior_2.c					\
			source/spells/warrior_3.c					\
			source/spells/update_archer_1.c					\
			source/spells/update_gunner_1.c					\
			source/spells/update_rogue_1.c					\
			source/spells/update_warrior_1.c				\
			source/interface/life_bar.c					\
			source/interface/main_particles.c				\
			source/interface/status_menu.c					\
			source/interface/status_info.c					\
			source/interface/tree_menu.c					\
			source/interface/update_tree.c					\
			source/interface/pause_menu.c					\
			source/interface/pause_main.c					\
			source/interface/pause_events.c					\
			source/interface/pause_launch.c					\
			source/interface/pause_design.c					\
			source/interface/tree_proceed.c					\
			source/interface/generate_tree_menu.c				\
			source/interface/button_generator.c				\
			source/save/create_stat.c					\
			source/save/create_tree.c					\
			source/save/write_save.c					\
			source/save/load_save.c						\
			source/game_map/collision.c					\
			source/game_map/collision_prog.c				\
			source/game_map/collision_id.c					\
			source/game_map/game.c						\
			source/game_map/move.c						\
			source/game_map/move_prog.c					\
			source/game_map/prog.c						\
			source/game_map/setup.c						\
			source/game_map/setup2.c					\
			source/game_map/remalloc_tab.c					\
			source/game_map/tileset.c					\
			source/game_map/set_shader_map.c				\
			source/game_map/parsing_tab_to.c				\
			source/game_map/set_pixeltoimage.c				\
			source/game_map/parsing.c					\
			source/game_map/lib_func.c					\
			source/game_map/draw.c						\
			source/game_map/check_pnj.c					\
			source/game_map/zone_text_create.c				\
			source/game_map/check_pos_camera.c				\
			source/game_map/get_layer.c					\
			source/game_map/free.c						\
			source/game_map/get_pnj.c					\
			source/game_map/transfer_pixel.c				\
			source/game_map/transfer_pixel_all.c				\
			source/game_map/move_pnj.c					\
			source/game_map/draw_dialog.c					\
			source/game_map/zone_text.c					\
			source/game_map/choice_box.c					\
			source/game_map/choice_box_quit.c				\
			source/game_map/choicebox_create_event.c			\
			source/game_map/setpixel_to_image.c				\
			source/game_map/mouse_in_object_dialogbox.c			\
			source/game_map/create_music.c					\
			source/game_map/mouse_in_object_quest_box.c			\
			source/game_map/destroy.c					\
			source/game_map/move_infos.c					\
			source/game_map/name_top_head.c					\
			source/quests/create_difquests.c				\
			source/quests/get_quests_rewards.c				\
			source/quests/get_all_quests.c					\
			source/quests/check_quests.c					\
			source/quests/get_quests.c					\
			source/quests/quests.c						\
			source/quests/check_pnj_for_quests.c				\
			source/scenes/night.c						\
			source/scenes/background_with_text.c				\
			source/scenes/death_zach.c					\
			source/scenes/move_pnj_zach.c					\
			source/scenes/move_player_to_zach.c				\
			source/player/player.c						\
			source/player/player_movement_map.c				\
			source/player/player_animation_village.c			\
			source/player/player_movement.c					\
			source/player/player_animations.c				\
			source/player/verify_collisions.c				\
			source/dungeon/main_proc.c					\
			source/dungeon/update_origin/icons.c				\
			source/dungeon/update_origin/life_bar.c				\
			source/dungeon/make_array/map_creation.c			\
			source/dungeon/make_array/verify_collide.c			\
			source/dungeon/make_array/corridors.c				\
			source/dungeon/make_array/mandatory_blocks.c			\
			source/dungeon/make_array/make_map_better.c			\
			source/dungeon/make_array/make_map_border.c			\
			source/dungeon/make_array/get_blocks_positions.c		\
			source/dungeon/make_sprite_map/main_draw_map.c			\
			source/dungeon/make_sprite_map/create_blocks.c			\
			source/dungeon/make_sprite_map/create_blocks_corner.c		\
			source/dungeon/make_sprite_map/create_blocks_icorner.c		\
			source/dungeon/make_sprite_map/create_blocks_deadlock.c		\
			source/dungeon/launch_game/launch_dungeon.c			\
			source/dungeon/launch_game/dungeon_loop.c			\
			source/dungeon/launch_game/camera_manager.c			\
			source/dungeon/launch_game/input_manager.c			\
			source/dungeon/launch_game/free_dungeon.c			\
			source/dungeon/launch_game/init_dungeon.c			\
			source/dungeon/restart_game/restart_game.c			\
			source/dungeon/restart_game/text_anims.c			\
			source/dungeon/minimap_system/main_minimap.c			\
			source/dungeon/minimap_system/fill_screen.c			\
			source/dungeon/minimap_system/put_pixel.c			\
			source/dungeon/minimap_system/update_minimap.c			\
			source/dungeon/minimap_system/draw_minimap.c			\
			source/dungeon/draw_geometry/draw_rect.c			\
			source/dungeon/draw_geometry/draw_circle.c			\
			source/dungeon/inventory_system/handle_inventory.c		\
			source/dungeon/inventory_system/draw_inventory.c		\
			source/dungeon/inventory_system/create_inventory.c		\
			source/dungeon/inventory_system/create_fast_inventory.c		\
			source/dungeon/inventory_system/draw_fast_inventory.c		\
			source/dungeon/inventory_system/inv_handle_mouse.c		\
			source/dungeon/inventory_system/inventory_items_handling.c	\
			source/dungeon/ground_item_system/create_items_on_ground.c	\
			source/dungeon/npc/ennemies_dungeon.c				\

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
