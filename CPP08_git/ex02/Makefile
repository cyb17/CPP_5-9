# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:21:49 by yachen            #+#    #+#              #
#    Updated: 2024/05/20 10:57:41 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutantStack

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp 

OBJ = $(SRC:.cpp=.o)

DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\e[32m\n==================================="
		@echo "\e[32mCompilin MutantStack----------------"
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\e[32m---created with success  MutantStack"
		@echo "\e[32m===================================\n\e[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin MutantStack----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- MutantStack Cleaned"
	@echo "\e[32m=====================\n\e[0m"

fclean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin MutantStack----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- MutantStack Cleaned"
	@rm -rf $(NAME)
	@echo "\e[32m=====================\n\e[0m"

re: fclean all

-include $(DEPS)

.PHONY: clean fclean all re bonus
