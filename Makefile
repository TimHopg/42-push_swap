# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:25:34 by thopgood          #+#    #+#              #
#    Updated: 2024/06/10 19:29:38 by thopgood         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -Iinclude # MAIN
# CFLAGS = -Wall -Wextra -Werror -Iinclude -g -O0 # for valgrind
# CFLAGS = -Wall -Wextra -Werror -Iinclude -g -fsanitize=address # for fsanitize

SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/

SRC = 	deserialise.c \
		duplicate.c \
		list_utils.c \
		operations.c \
		main.c

# OBJ = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INCLUDE = -L ./libft -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFT_DIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus