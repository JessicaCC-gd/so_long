# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 15:45:37 by jecarval          #+#    #+#              #
#    Updated: 2023/11/10 21:37:21 by jecarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
NAME = so_long

SRCS =	main.c \
		graphics_handler.c \
		movement_pt1.c \
		movement_pt2.c \
		map_handler.c \
		map_tests.c \
		map_fill_test.c \
		textures_handler.c \
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(MAKE) -C ./mlx
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -rf $(NAME)

re: fclean all

.SILENT:
