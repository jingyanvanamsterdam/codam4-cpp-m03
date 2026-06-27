# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdong <jdong@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2026/05/20 18:34:22 by jdong         #+#    #+#                  #
#    Updated: 2026/06/27 12:33:19 by jingyandong   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME = run

HEADER =  ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp

SRC =  ClapTrap.cpp main.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJ = $(SRC:%.cpp=%.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):$(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all, clean, fclean