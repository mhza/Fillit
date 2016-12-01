# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 11:18:18 by mhaziza           #+#    #+#              #
#    Updated: 2016/11/30 20:27:24 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I.
RM		=   rm -f
SRCS	=	ft_findtet.c \
			ft_place_tet.c \
			main.c \

OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= ./libft

all:	$(NAME)

$(NAME):$(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAG) $(SRCS) -L./libft -lft -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re
