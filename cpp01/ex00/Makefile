# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 23:52:41 by ssottori          #+#    #+#              #
#    Updated: 2024/12/03 01:22:39 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============COLORS=================
MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

# ===============FLAGS=================
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -rf
NAME = braiiiiiiinnnzzzz

INC = inc
IFLAGS = -I$(INC)

# ================SRCS=================
SRCS = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \

OBJS = $(SRCS:.cpp=.o)

# ===============BUILD==================
all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(IFLAGS) -o $(NAME)
	@echo "[$(GREEN)BRAINZ$(NC)] - $<"

%.o: %.c
	echo "[$(GREEN)BRAINZ$(NC)] - $<"
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

# ===============CLEAN==================
clean:
	@echo "[$(RED)BRAINZ$(NC)] Cleaning object files..."
			@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)BRAINZ$(NC)] Cleaning executable file..."
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re