# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 13:01:57 by ssottori          #+#    #+#              #
#    Updated: 2025/04/13 14:40:19 by ssottori         ###   ########.fr        #
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

# ============== FILES ====================
NAME = ex00
SRC_DIR = src
INC_DIR = inc

SRCS = main.cpp \
		$(SRC_DIR)/Animal.cpp \
		$(SRC_DIR)/Dog.cpp \
		$(SRC_DIR)/Cat.cpp \
		$(SRC_DIR)/WrongAnimal.cpp \
		$(SRC_DIR)/WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

# ============== RULES ====================
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -o $(NAME)
	@echo "[$(GREEN)EX00$(NC)] Build complete!"

%.o: %.cpp
	@echo "[$(GREEN)Compiling$(NC)] $<"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# ============== CLEAN ====================
clean:
	@echo "[$(RED)Cleaning$(NC)] Object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)Cleaning$(NC)] Executable..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re