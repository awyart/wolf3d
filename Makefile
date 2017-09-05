# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awyart <awyart@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 22:10:59 by awyart            #+#    #+#              #
#    Updated: 2017/09/05 18:08:12 by awyart           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = wolf3D
GRAPH = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wall -Wextra
SRC1 = main.c\
		init.c

SRC2 = ft_putchar.c \
	ft_putstr.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strnew.c \
	ft_strsub.c \
	get_next_line.c\
	ft_memalloc.c \
	ft_putnbr.c

SRC3 = ft_launch.c \
		img.c \
		putpx.c

SRC4 = ft_exit.c \
		ft_mv.c \
		mouse.c\
		event.c

SRC5 = read.c

SRC = $(SRC1) \
	  $(patsubst %,srcs/utility/%,$(SRC2)) \
	  $(patsubst %,srcs/launch/%,$(SRC3)) \
	  $(patsubst %,srcs/event/%,$(SRC4)) \
	  $(patsubst %,srcs/texture/%,$(SRC5)) \

IPATH = includes
VPATH = srcs

LIB = /usr/local/lib/libmlx.a

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $^ $(LIB) -I $(IPATH) $(GRAPH) -g

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)
