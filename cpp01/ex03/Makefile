# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:24:25 by ssottori          #+#    #+#              #
#    Updated: 2024/12/04 16:26:22 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============COLORS=================
MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

# ===============FLAGS=================
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = violence

INC = inc
IFLAGS = -I$(INC)

# ================SRCS=================
SRCS = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \

OBJS = $(SRCS:.cpp=.o)

# ===============BUILD==================
all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(IFLAGS) -o $(NAME)
	@echo "[$(GREEN)VIOLENCE$(NC)] - $<"

%.o: %.c
	echo "[$(GREEN)VIOLENCE$(NC)] - $<"
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

# ===============CLEAN==================
clean:
	@echo "[$(RED)VIOLENCE$(NC)] Cleaning object files..."
			@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)VIOLENCE$(NC)] Cleaning executable file..."
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re