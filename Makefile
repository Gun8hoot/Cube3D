NAME		=	so_long
CFLAGS		=	-Wall -Wextra -Werror -I. -g3 -c -lm
MLX_FLAG	=	-L$(MLX_DIR) -lm -lXext -lX11

SRC			=	$(SRC_DIR)/cube3d.c
OBJS		=	$(SRC:%.c=%.o)

SRC_DIR		=	src
LIB_DIR		=	lib
MLX_DIR		=	external/minilibx-linux

all: $(NAME)

%.c: %.o
	$(CC) $(CFLAGS) $< -o $@

PRINTF:
	make -C external/printf
	mv external/printf/*.a lib/

LIBFT:
	make -C external/libft
	mv external/libft/*.a lib/

minilibx:
	rm -f minilibx-linux.tgz
	wget https://cdn.intra.42.fr/document/document/46415/minilibx-linux.tgz
	tar xvfz minilibx-linux.tgz -C library
	make -C library/minilibx-linux
	mv library/minilibx-linux/*.a lib/

$(NAME): minilibx PRINTF LIBFT $(OBJS)
	$(CC) $(GNL) $(OBJS) -o $@ lib/*.a $(MLX_FLAG)

clean:
	if [ -d external/minilibx-linux ]; then make -C external/minilibx-linux clean; fi
	make -C external/libft clean
	rm -f $(OBJS)
	rm -f minilibx-linux.tgz

fclean: clean
	rm -rf external/minilibx-linux
	rm -f lib/*.a
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all
