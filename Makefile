# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:23:43 by achane-l          #+#    #+#              #
#    Updated: 2023/02/08 18:55:00 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  test_unit/map_test/map_test.cpp\
		test_unit/map_test/map_test1.cpp\
		test_unit/vector_test/vector_test.cpp\
		test_unit/vector_test/vector_test1.cpp\
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
	${COMPILER} ${FLAGS} -o vector_test1 test_unit/vector_test/vector_test1.o

map: ${OBJS}
	${COMPILER} ${FLAGS} -o map_test test_unit/map_test/map_test.o
	${COMPILER} ${FLAGS} -o map_test1 test_unit/map_test/map_test1.o

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f main vector_test vector_test1 map_test map_test1

re: fclean all

.PHONY: all clean fclean re