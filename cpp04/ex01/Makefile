# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 13:03:27 by ssottori          #+#    #+#              #
#    Updated: 2025/05/08 15:59:03 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============== COLORS =================
MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

# ============== COMPILER/FLAGS ============
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -rf

# ============== NAME/FILES ====================
NAME = ex01
SRC_DIR = src
INC_DIR = inc

SRCS = main.cpp \
		$(SRC_DIR)/Animal.cpp \
		$(SRC_DIR)/Dog.cpp \
		$(SRC_DIR)/Cat.cpp \
		$(SRC_DIR)/Brain.cpp \

OBJS = $(SRCS:.cpp=.o)

# ============== BUILD ====================
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -o $(NAME)
	@echo "[$(GREEN)EX01$(NC)] Build complete!"

%.o: %.cpp
	@echo "[$(GREEN)Compiling$(NC)] $<"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# ============== CLEAN ====================
clean:
	@echo "[$(RED)EX01$(NC)] Cleaning object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)EX01$(NC)] Cleaning executable..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

leaks:
	valgrind --leak-check=full ./$(NAME)
