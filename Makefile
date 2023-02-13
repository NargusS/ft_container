# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:23:43 by achane-l          #+#    #+#              #
#    Updated: 2023/02/13 14:12:48 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  test_unit/main_subject.cpp\
		test_unit/map_test/map_test.cpp\
		test_unit/stack_test/stack_test.cpp\
		test_unit/vector_test/vector_test.cpp

VECTOR = vector_test
VECTOR_STD = vector_test_std

MAP = map_test
MAP_STD = map_test_std

STACK = stack_test
STACK_STD = stack_test_std

MAIN = main_subject

COMPILER = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g3
FLAGSSTD = -std=c++98 -Wall -Werror -Wextra -g3 -D lib_used=std

OBJS = $(SRCS:.cpp=.o)

all: main_subject vector_test map_test stack_test

%.o: %.cpp
	@$(COMPILER) $(FLAGS) -c $< -o $@
	@$(COMPILER) $(FLAGSSTD) -c $< -o $@

main_subject: test_unit/main_subject.o
	$(COMPILER) $(FLAGS) -o $(MAIN) test_unit/main_subject.o


vector_test: test_unit/vector_test/vector_test.o
	$(COMPILER) $(FLAGS) -o $(VECTOR) test_unit/vector_test/vector_test.o
	$(COMPILER) $(FLAGSSTD) -o $(VECTOR_STD) test_unit/vector_test/vector_test.o

map_test: test_unit/map_test/map_test.o
	$(COMPILER) $(FLAGS) -o $(MAP) test_unit/map_test/map_test.o
	$(COMPILER) $(FLAGSSTD) -o $(MAP_STD) test_unit/map_test/map_test.o

stack_test: test_unit/stack_test/stack_test.o
	$(COMPILER) $(FLAGS) -o $(STACK) test_unit/stack_test/stack_test.o
	$(COMPILER) $(FLAGSSTD) -o $(STACK_STD) test_unit/stack_test/stack_test.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f main_subject vector_test vector_test_std map_test map_test_std stack_test stack_test_std

re: fclean all


.PHONY: all clean fclean re