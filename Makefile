# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 11:04:36 by yonuma            #+#    #+#              #
#    Updated: 2024/05/11 12:36:25 by skohtake         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = cc -c

CFRAGS = -Wall -Wextra -Werror

RM = rm -f

INCLUDES = -I libft


$(NAME) : $(OBJS)
	ar rc $@ $^
	ranlib $(NAME)

all : $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

# removing required below
test : $(NAME)
	cc test_main.c -o TEST $(NAME)