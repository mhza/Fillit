# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 16:29:51 by mhaziza           #+#    #+#              #
#    Updated: 2016/11/24 15:11:46 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I.
RM		=   rm -f
SRCS	=   ft_memset.c \
			ft_bzero.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strstr.c \
			ft_atoi.c \
			ft_memalloc.c \
			ft_strnew.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_realloc.c \
			ft_strchr.c \
			ft_intlen_base.c \

OBJS	=   $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:     all clean fclean re
