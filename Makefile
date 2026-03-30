
NAME		=	cube3D
CFLAGS		=	-Wall -Wextra -Werror -I. -g3 -c -lm
MLX_FLAG	=	-L$(MLX_DIR) -lm -lXext -lX11

# Name
NAME = cube3D

SRC_DIR		=	sources
LIB_DIR		=	library
MLX_DIR		=	$(LIB_DIR)/minilibx-linux

# Paths
SRC_DIR = sources
OBJ_DIR = obj
LIBFT_DIR = $(LIB_DIR)/mylibft

LIBFT = $(LIBFT_DIR)/libft.a

# Srcs
SRCS =	$(SRC_DIR)/parsing/.c\
OBJS =	$(SRCS:%.c=%.o)

%.c: %.o
	$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): minilibx libft $(OBJS)
	$(CC) $(OBJS) -o $@ library/*.a $(MLX_FLAG)

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

libft:
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/*.a library/

minilibx:
	rm -f minilibx-linux.tgz
	mkdir -p library
	wget https://cdn.intra.42.fr/document/document/46415/minilibx-linux.tgz
	tar xvfz minilibx-linux.tgz -C library
	make -C library/minilibx-linux
	mv $(MLX_DIR)/*.a $(LIB_DIR)

# Clean obj files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Complete clean
fclean: clean
	rm -rf $(LIB_DIR)/minilibx-linux
	rm -f library/*.a
	rm -f $(NAME)

# Complete recompilation
re: fclean all

# Rule .PHONY
.PHONY: all clean fclean re test leaks valgrind