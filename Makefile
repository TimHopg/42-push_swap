# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:25:34 by thopgood          #+#    #+#              #
#    Updated: 2024/06/10 11:44:44 by thopgood         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/

SRC = 	src/deserialise.c \
		src/duplicate.c \
		src/list_utils.c \
		src/main.c \
		src/operations.c
		
OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

%.c%.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C ${LIBFT_DIR}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ} {NAME}
	@cd ${LIBFT_DIR} && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd ${LIBFT_DIR} && ${MAKE} fclean

re: clean all

.PHONY: all clean fclean re bonus