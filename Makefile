# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 11:04:15 by nclavel           #+#    #+#              #
#    Updated: 2026/04/17 19:32:17 by thlibers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME = cube3D

# Flags
# -O0 -g2 -ggdb
CC = cc
OFLAG = -O3
GFLAG = -g3 -ggdb
CFLAGS = -Wall -Wextra -Werror $(OFLAG) -I.
INCLUDES = -I./includes

# Flags Mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Paths
SRC_DIR = sources
OBJ_DIR = objects
LIB_DIR	= library

LIBFT_DIR = $(LIB_DIR)/mylibft
LIB =	$(LIB_DIR)/libmlx_Linux.a\
		$(LIB_DIR)/libmlx.a

LIBFT = $(LIBFT_DIR)/libft.a
MLX	= $(LIB_DIR)/minilibx-linux

# Srcs
SRCS =	$(SRC_DIR)/environement/door.c\
		$(SRC_DIR)/parsing/check.c\
		$(SRC_DIR)/parsing/map.c\
		$(SRC_DIR)/parsing/maps_utils.c\
		$(SRC_DIR)/parsing/texture.c\
		$(SRC_DIR)/player/events.c\
		$(SRC_DIR)/player/mouse.c\
		$(SRC_DIR)/player/movement.c\
		$(SRC_DIR)/raycasting/ray_utils.c\
		$(SRC_DIR)/raycasting/raycasting.c\
		$(SRC_DIR)/render/render.c\
		$(SRC_DIR)/render/shape.c\
		$(SRC_DIR)/render/tex_load.c\
		$(SRC_DIR)/ui/minimap/ui_minimap.c\
		$(SRC_DIR)/ui/minimap/ui_vision.c\
		$(SRC_DIR)/ui/weapon/ui_weapon.c\
		$(SRC_DIR)/ui/weapon/ui_weapon_animation.c\
		$(SRC_DIR)/ui/weapon/ui_weapon_render.c\
		$(SRC_DIR)/ui/ui_crosshair.c\
		$(SRC_DIR)/ui/ui_fps.c\
		$(SRC_DIR)/utils/clean.c\
		$(SRC_DIR)/utils/free.c\
		$(SRC_DIR)/utils/mlx_utils.c\
		$(SRC_DIR)/utils/time_based.c\
		$(SRC_DIR)/init.c\
		$(SRC_DIR)/main.c

# Obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \e[0;32m
RED = \e[0;31m
BLUE = \e[0;34m
RESET = \e[0m

all: $(NAME)

# Compilation program
$(NAME): MLX $(LIBFT) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(LIB) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compilation files obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation mylibft
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled!$(RESET)"

MLX:
	@rm -f minilibx-linux.tgz
	@mkdir -p $(LIB_DIR)
	@printf "$(GREEN)Downloading minilibx$(RESET)\n"
	@wget https://cdn.intra.42.fr/document/document/46415/minilibx-linux.tgz
	@tar xvfz minilibx-linux.tgz -C $(LIB_DIR)
	@printf "$(GREEN)Compiling minilibx$(RESET)\n"
	@make -C $(LIB_DIR)/minilibx-linux
	@mv $(MLX)/*.a $(LIB_DIR)

# Clean obj files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@if [ -d $(LIB_DIR)/minilibx-linux ]; then make -C library/minilibx-linux clean; rm -f $(LIB); fi
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Complete clean
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	@rm -rf $(MLX)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean completed!$(RESET)"

# Complete recompilation
re: fclean all

# Rule .PHONY
.PHONY: all clean fclean re test leaks valgrind MLX
