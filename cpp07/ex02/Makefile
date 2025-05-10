# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 01:02:49 by ssottori          #+#    #+#              #
#    Updated: 2025/05/10 01:03:12 by ssottori         ###   ########.fr        #
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
NAME = ex02
SRC_DIR = src
INC_DIR = inc

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

# ============== RULES ====================
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -o $(NAME)
	@echo "[$(GREEN)EX02$(NC)] Build complete!"

%.o: %.cpp
	@echo "[$(GREEN)EX02$(NC)] Compiling...$<"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# ============== CLEAN ====================
clean:
	@echo "[$(RED)EX02$(NC)] Object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)EX02$(NC)] Executable..."
	@$(RM) $(NAME)

re: fclean all

leaks:
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re