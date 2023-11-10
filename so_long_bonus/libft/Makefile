# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:45:21 by jecarval          #+#    #+#              #
#    Updated: 2023/11/10 21:33:41 by jecarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_split.c ft_strlcat.c ft_strchr.c ft_strlcpy.c \
	  ft_strncmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_strrchr.c \
	  ft_substr.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_lstnew.c \
	  ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	  ft_lstmap.c ft_lstadd_back.c ft_lstsize.c get_next_line.c get_next_line_utils.c\
	  Printf/ft_printf_pt1.c Printf/ft_printf_pt2.c Printf/ft_printf_pt3.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@cc $(FLAG) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re, bonus
