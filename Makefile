# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:23:43 by achane-l          #+#    #+#              #
#    Updated: 2023/01/30 18:55:06 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unit_test

FUNCTION = test_unit/std_function.cpp
VECTOR = test_unit/vector_test.cpp
STD_MAP = test_unit/test.cpp

COMPILER = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g3

OBJS_FUNCTION = ${FUNCTION:.cpp=.o}
OBJS_VECTOR = ${VECTOR:.cpp=.o}
OBJS_STD_MAP = ${STD_MAP:.cpp=.o}

all: function vector

function: ${OBJS_FUNCTION}
		${COMPILER} ${FLAGS} ${OBJS_FUNCTION} -I includes -o unit_test_function

vector: ${OBJS_VECTOR}
		${COMPILER} ${FLAGS} ${OBJS_VECTOR} -I includes -o unit_test_vector

map: ${OBJS_STD_MAP}
		${COMPILER} ${FLAGS} ${OBJS_STD_MAP} -I includes -o unit_test_ft_map -D ft
		${COMPILER} ${FLAGS} ${OBJS_STD_MAP} -I includes -o unit_test_std_map -D std
		./unit_test_ft_map
		./unit_test_std_map

clean:
	rm -f ${OBJS_FUNCTION} ${OBJS_VECTOR} ${OBJS_STD_MAP}

fclean: clean
	rm -f unit_test_function unit_test_vector unit_test_ft_map unit_test_std_map

re: fclean all

%.o: %.cpp
	${COMPILER} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY: all clean fclean re