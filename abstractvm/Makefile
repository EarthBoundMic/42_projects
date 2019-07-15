#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 13:12:44 by mkass             #+#    #+#              #
#    Updated: 2019/02/09 13:12:45 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = avm

CFLAGS = -Wall -Wextra -Werror
INC = -I includes
SRCDIR = src/

SRC = AbstractVM.cpp Exceptions.cpp Operands.cpp Parser.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: $(SRCDIR)%.cpp
	@echo "Making $@..."
	@clang++ $(CFLAGS) $(INC) -c $<

$(NAME): $(OBJ)
	@echo "Making $(NAME)..."
	@clang++ $(OBJ) -o $(NAME)

clean:
	@echo "Cleaning..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "...Deep"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
