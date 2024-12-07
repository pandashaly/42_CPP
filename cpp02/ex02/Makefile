# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 02:26:53 by ssottori          #+#    #+#              #
#    Updated: 2024/12/07 02:35:04 by ssottori         ###   ########.fr        #
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
		Fixed.cpp \

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