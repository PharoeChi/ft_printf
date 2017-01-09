# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbogar <lbogar@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 10:13:38 by lbogar            #+#    #+#              #
#    Updated: 2016/11/22 16:30:19 by lbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all lib

FILENAME = ft_parse_flag.c ft_manage_flag.c ft_main.c ft_printf.c
FILENAME += ft_itoa_base.c ft_conversion_number.c ft_conversion_text.c

SRCS = $(addprefix srcs/, $(FILENAME))
OBJS = $(addprefix build/, $(FILENAME:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGs += -I includes/ft_printf.h
LFLAGS = -L ./libft/ -lft

all:  test

test: $(OBJS) | lib
	@$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make clean -C ./libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./libft

build:
	@mkdir build/
