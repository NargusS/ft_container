# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:23:43 by achane-l          #+#    #+#              #
#    Updated: 2023/01/18 19:06:27 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unit_test

FUNCTION = test_unit/std_function.cpp
VECTOR = test_unit/vector_test.cpp

COMPILER = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

OBJS_FUNCTION = ${FUNCTION:.cpp=.o}
OBJS_VECTOR = ${VECTOR:.cpp=.o}

all: function vector

function: ${OBJS_FUNCTION}
		${COMPILER} ${FLAGS} ${OBJS_FUNCTION} -I includes -o unit_test_function

vector: ${OBJS_VECTOR}
		${COMPILER} ${FLAGS} ${OBJS_VECTOR} -I includes -o unit_test_vector

clean:
	rm -f ${OBJS_FUNCTION} ${OBJS_VECTOR}

fclean:
	rm -f ${OBJS_FUNCTION} unit_test_function unit_test_vector

re: fclean all

%.o: %.cpp
	${COMPILER} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY: all clean fclean re