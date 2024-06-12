# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:25:34 by thopgood          #+#    #+#              #
#    Updated: 2024/06/12 13:48:37 by thopgood         ###   ########.fr        #
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
		list_utils.c \
		list_utils2.c \
		operations.c \
		operations2.c \
		sort.c \
		sortfive.c \
		main.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INCLUDE = -L ./libft -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@echo ""${BLUE}$(NAME)""${NC}Compiling... "\c"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)
	@echo ""${GREEN}Complete""$(NC)""

all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@echo ""${BLUE}$(NAME)""${NC}Cleaning..."\c"
	@$(RM) $(OBJ_DIR)
	@echo ""${GREEN}Complete""$(NC)""

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# Colours
WHITE	=	'\033[0;37m'
YELLOW	=	'\033[0;33m'
BLUE	=	'\033[0;34m'
GREEN	=	'\033[0;32m'
RED		=	'\033[0;31m'
NC		=	'\033[0m' # no colour
#> /dev/null