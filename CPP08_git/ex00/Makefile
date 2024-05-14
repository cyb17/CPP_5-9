# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:21:49 by yachen            #+#    #+#              #
#    Updated: 2024/05/14 19:24:23 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Easyfind

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\e[32m\n==================================="
		@echo "\e[32mCompilin Easyfind----------------"
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\e[32m---created with success  Easyfind"
		@echo "\e[32m===================================\n\e[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin Easyfind----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- Easyfind Cleaned"
	@echo "\e[32m=====================\n\e[0m"

fclean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin Easyfind----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- Easyfind Cleaned"
	@rm -rf $(NAME)
	@echo "\e[32m=====================\n\e[0m"

re: fclean all

-include $(DEPS)

.PHONY: clean fclean all re bonus
