# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 11:04:36 by yonuma            #+#    #+#              #
#    Updated: 2024/05/24 14:00:30 by skohtake         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c

SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = cc -c

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

AR = ar rc

LIBFT = libft/libft.a

$(NAME) : $(OBJS)
	make -C libft
    cp $(LIBFT) $(NAME)
	$(AR) $@ $^

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