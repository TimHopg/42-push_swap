# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:27:57 by thopgood          #+#    #+#              #
#    Updated: 2024/04/23 16:55:54 by thopgood         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBC		= ar -rcs
NAME		= libft.a
HEADER		= ../include/libft.h
SRC_DIR		= src
RM			= rm -rf

SRC			= $(addprefix $(SRC_DIR)/, \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c)

EXTRA_SRC	= $(addprefix $(SRC_DIR)/,\
				ft_isspace.c \
				ft_putbase_fd.c \
				ft_abs.c)

BONUS_SRC	= $(addprefix $(SRC_DIR)/,\
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c)

OBJ			= $(SRC:.c=.o) $(EXTRA_SRC:.c=.o)

BONUS_OBJ	= $(BONUS_SRC:.c=.o)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n ""${BLUE}$(NAME)""${NC}Archiving... ""
	@$(LIBC) $(NAME) $(OBJ)
	@echo ""${GREEN}OK""$(NC)""

bonus: $(BONUS_OBJ) $(OBJ)
	@echo -n ""${BLUE}$(NAME)" "$(YELLOW)[bonus]""${NC}Archiving... ""
	@if make OBJ="$(OBJ) $(BONUS_OBJ)" all \
	| grep -q "Nothing"; then \
	echo "\nmake: Nothing to be done for 'bonus'."; \
	else \
		echo ""${GREEN}OK${NC}""; \
	fi

clean:
	@$(RM) $(BONUS_SRC:.c=.o) $(SRC:.c=.o) $(EXTRA_SRC:.c=.o)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus

# Colours
WHITE	=	'\033[0;37m'
YELLOW	=	'\033[0;33m'
BLUE	=	'\033[0;34m'
GREEN	=	'\033[0;32m'
RED		=	'\033[0;31m'
NC		=	'\033[0m' # no colour
#> /dev/null