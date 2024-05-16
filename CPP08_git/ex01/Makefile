# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:21:49 by yachen            #+#    #+#              #
#    Updated: 2024/05/16 10:56:49 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)

DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\e[32m\n==================================="
		@echo "\e[32mCompilin Span----------------"
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\e[32m---created with success  Span"
		@echo "\e[32m===================================\n\e[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin Span----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- Span Cleaned"
	@echo "\e[32m=====================\n\e[0m"

fclean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin Span----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- Span Cleaned"
	@rm -rf $(NAME)
	@echo "\e[32m=====================\n\e[0m"

re: fclean all

-include $(DEPS)

.PHONY: clean fclean all re bonus
