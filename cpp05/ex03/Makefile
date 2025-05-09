# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 17:01:28 by ssottori          #+#    #+#              #
#    Updated: 2025/05/10 00:05:13 by ssottori         ###   ########.fr        #
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
NAME = ex03
SRC_DIR = src
INC_DIR = inc

SRCS = main.cpp \
		$(SRC_DIR)/Bureaucrat.cpp \
		$(SRC_DIR)/AForm.cpp \
		$(SRC_DIR)/ShrubberyCreationForm.cpp \
		$(SRC_DIR)/RobotomyRequestForm.cpp \
		$(SRC_DIR)/PresidentialPardonForm.cpp \
		$(SRC_DIR)/Intern.cpp \

OBJS = $(SRCS:.cpp=.o)

# ============== RULES ====================
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -o $(NAME)
	@echo "[$(GREEN)EX03$(NC)] Build complete!"

%.o: %.cpp
	@echo "[$(GREEN)EX03$(NC)] Compiling...$<"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# ============== CLEAN ====================
clean:
	@echo "[$(RED)EX03$(NC)] Object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)EX03$(NC)] Executable..."
	@$(RM) $(NAME)

re: fclean all

leaks:
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re