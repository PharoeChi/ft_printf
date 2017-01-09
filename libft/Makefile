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

NAME = libft.a

SOURCES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c
SOURCES += ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c
SOURCES += ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c
SOURCES += ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c
SOURCES += ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isspace.c ft_isdigit.c
SOURCES += ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
SOURCES += ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c
SOURCES += ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c
SOURCES += ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c
SOURCES += ft_strsplit.c ft_itoa.c
SOURCES += ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c
SOURCES += ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SOURCES += ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c
SOURCES += ft_lstmap.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDES = -I libft.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(INCLUDES) $(CFLAGS) $(SOURCES)
	@ar rc $(NAME) $(OBJECTS)

clean: 
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re