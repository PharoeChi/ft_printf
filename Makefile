# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbogar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 14:48:13 by lbogar            #+#    #+#              #
#    Updated: 2016/10/31 14:48:15 by lbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

FILENAMES =	ft_printf.c \
			ft_parse_flag.c \
			ft_manage_flag.c \
			ft_conversion_number.c \
			ft_conversion_text.c \
			ft_conversion_helpers.c \
			ft_width_precision.c \
			ft_format_output.c \
			ft_main.c \

OBJS = $(addprefix build/, $(FILENAMES:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS = -I includes/
LFLAGS = -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJS) | lib
	@$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

lib:
	@make -C ./libft

build:
	@mkdir build/

clean:
	@rm -rf build/
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re lib
