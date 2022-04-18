# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 17:22:08 by wzouf             #+#    #+#              #
#    Updated: 2022/04/15 00:07:33 by wzouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM = 	utils.c \
		checkmap.c \
		so_long.c \
		mlx.c \
		extra.c \
		norm.c \

NAME = so_long

CFLAGS =-Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(SRCM) ./so_long.h
	$(CC) $(CFLAGS) $(SRCM) -o $(NAME)

all : $(NAME)

clean:
	rm -rf $(NAME)
fclean: clean
re : fclean all