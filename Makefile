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

NAME = libftprintf.a

LIBFT =		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isspace.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_max.c \
			ft_min.c \
			ft_strset.c

PRINTF =	ft_printf.c \
			ft_parse_flag.c \
			ft_parse_width.c \
			ft_parse_precision.c \
			ft_parsing_helpers.c \
			ft_width_only.c \
			ft_manage_flag.c \
			ft_format_output.c \
			ft_conversion_number.c \
			ft_conversion_string.c \
			ft_conversion_escape.c \
			ft_conversion_char.c \
			ft_conversion_wstring.c \
			ft_wstring_functions.c \
			ft_conversion_pointer.c \
			ft_conversion_long.c \
			ft_conversion_helpers.c \
			ft_process_unterminated.c \
			ft_width_only.c

MAIN =		srcs/ft_test.c

OBJS = $(addprefix build/, $(LIBFT:.c=.o))
OBJS += $(addprefix build/, $(PRINTF:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/
LFLAGS = -L . -lftprintf

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

test: $(NAME)
	@$(CC) -I includes/ -o $@ $(MAIN) $(LFLAGS)
	@./test

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

build/%.o: libft/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

build:
	@mkdir build/

clean:
	@rm -rf build/

fclean: clean
	@rm -f $(NAME)
	@rm -f test

re: fclean all

.PHONY: all clean fclean re lib
