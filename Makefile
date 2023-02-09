# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:23:43 by achane-l          #+#    #+#              #
#    Updated: 2023/02/09 15:02:19 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  test_unit/map_test/map_test.cpp\
		test_unit/vector_test/vector_test.cpp\
		test_unit/main_subject.cpp

COMPILER = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g3

OBJS = ${SRCS:.cpp=.o}

all: main

%.o: %.cpp
	@$(COMPILER) $(FLAGS) -c $< -o $@

main : ${OBJS}
	${COMPILER} ${FLAGS} -o main test_unit/main_subject.o

vector: ${OBJS}
	${COMPILER} ${FLAGS} -o vector_test test_unit/vector_test/vector_test.o

map: ${OBJS}
	${COMPILER} ${FLAGS} -o map_test test_unit/map_test/map_test.o

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f main vector_test map_test

re: fclean all

.PHONY: all clean fclean re