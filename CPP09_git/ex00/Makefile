# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:21:49 by yachen            #+#    #+#              #
#    Updated: 2024/05/24 12:28:15 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ_DIR = obj

SRC_DIR = src/

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

DEPS = $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\e[32m\n==================================="
		@echo "\e[32mCompilin btc----------------"
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\e[32m---created with success  btc"
		@echo "\e[32m===================================\n\e[0m"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin btc----"
	@rm -rf $(OBJ_DIR)
	@echo "\e[32m--- btc Cleaned"
	@echo "\e[32m=====================\n\e[0m"

fclean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin btc----"
	@rm -rf $(OBJ_DIR)
	@echo "\e[32m--- btc Cleaned"
	@rm -rf $(NAME)
	@echo "\e[32m=====================\n\e[0m"

re: fclean all

-include $(DEPS)

.PHONY: clean fclean all re bonus
