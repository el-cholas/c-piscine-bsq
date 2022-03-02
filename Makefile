# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 21:13:27 by xcarroll          #+#    #+#              #
#    Updated: 2022/03/02 21:35:46 by xcarroll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc -c
CFLAGS = -Wall -Wextra -Werror
SRC = array_helper.c conversions.c display.c file.c main.c map_helper.c map_validator.c map.c string.c

$(NAME):
	$(CC) $(CFLAGS) $(NAME) -o $(SRC)
all: $(NAME)
clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
