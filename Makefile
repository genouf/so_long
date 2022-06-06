# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: genouf <genouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 22:28:16 by genouf            #+#    #+#              #
#    Updated: 2022/06/06 19:39:50 by genouf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	gnl/get_next_line_utils.c	\
		gnl/get_next_line.c			\
		sources/so_long.c			\
		sources/utils.c				\
		sources/arg_check.c			\
		sources/map.c				\
		sources/parsing_map.c		\
		sources/draw_map.c			\
		
OBJS = ${SRCS:.c=.o}
OBJDIR = exec

INC = 	includes/get_next_line.h	\
		includes/so_long.h			\
		
NAME = so_long

RM = rm -f

CC = gcc
CLFAGS = -Wall -Wextra -Werror

MAKE = make -C libft
LIBA = libft/libft.a
LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

all: ${NAME}

${LIBA}:
		${MAKE}

${NAME}: ${OBJS} ${LIBA}
		cd mlx/ && ./configure
		${CC} -fsanitize=address ${CFLAGS} -o $@ ${SRCS} ${LIB}

/%.o:	%.c
		${CC} ${CFLAGS} -c $@ $<

skiperror:
		${CC} -o ${NAME} ${SRCS} -g ${LIB}

clean:
		${RM} ./${OBJS}
		${MAKE} clean
		@echo "cleaning .o files"

fclean: clean
		${RM} ${NAME}
		${MAKE} fclean
		
re:		fclean all		