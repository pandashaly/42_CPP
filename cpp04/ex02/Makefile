# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 13:04:50 by ssottori          #+#    #+#              #
#    Updated: 2025/04/13 15:06:11 by ssottori         ###   ########.fr        #
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
NAME = ex02

INC = inc
IFLAGS = -I$(INC)

# ================SRCS=================
SRCS = main.cpp \
		AAnimal.cpp \
		Animal.cpp \
		Brain.cpp \
		Abstract.cpp \

OBJS = $(SRCS:.cpp=.o)

# ===============BUILD==================
all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(IFLAGS) -o $(NAME)
	@echo "[$(GREEN)EX02$(NC)] - $<"

%.o: %.c
	echo "[$(GREEN)EX02$(NC)] - $<"
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

# ===============CLEAN==================
clean:
	@echo "[$(RED)EX02$(NC)] Cleaning object files..."
			@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)EX02$(NC)] Cleaning executable file..."
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re