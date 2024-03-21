# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:21:49 by yachen            #+#    #+#              #
#    Updated: 2024/03/21 15:08:10 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrate

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

FILE_NAME =  main Bureaucrate ShrubberyCreationForm AForm RobotomyRequestForm PresidentialPardonForm Intern
			 
SRC = $(addsuffix .cpp, $(addprefix srcs/, $(FILE_NAME)))

OBJ = $(SRC:.cpp=.o)

DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\e[32m\n==================================="
		@echo "\e[32mCompilin Bureaucrate----------------"
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\e[32m---created with success  Bureaucrate"
		@echo "\e[32m===================================\n\e[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin Bureaucrate----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- Bureaucrate Cleaned"
	@echo "\e[32m=====================\n\e[0m"

fclean:
	@echo "\e[32m\n====================="
	@echo "\e[32mCleanin Bureaucrate----"
	@rm -rf $(OBJ) $(DEPS)
	@echo "\e[32m--- Bureaucrate Cleaned"
	@rm -rf $(NAME)
	@echo "\e[32m=====================\n\e[0m"

re: fclean all

-include $(DEPS)

.PHONY: clean fclean all re bonus
