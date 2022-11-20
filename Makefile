# Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
NAME = ft_containers
HEADERS = ./headers/
SOURCE = main.cpp
OBJECTS_DIR = ./objects/
OBJECTS = $(SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
VPATH = ./tests/
CC = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98
MAKEFLAGS = --no-print-directory


ENABLE_IF_TEST_FT = enable_if_test_ft
ENABLE_IF_TEST_FT_SOURCE = enable_if_test_ft.cpp
ENABLE_IF_TEST_FT_OBJECTS = $(ENABLE_IF_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)


INTRA_TEST_FT = intra_test_ft
INTRA_TEST_STD = intra_test_std

INTRA_TEST_FT_SOURCE = intra_test_ft.cpp
INTRA_TEST_STD_SOURCE = intra_test_std.cpp

INTRA_TEST_FT_OBJECTS = $(INTRA_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
INTRA_TEST_STD_OBJECTS = $(INTRA_TEST_STD_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)



VECTOR_PERFOMANCE_TEST_FT = vector_perfomance_test_ft
VECTOR_PERFOMANCE_TEST_STD = vector_perfomance_test_std

VECTOR_UNIT_TEST_FT = vector_unit_test_ft
VECTOR_UNIT_TEST_STD = vector_unit_test_std

VECTOR_PERFOMANCE_TEST_FT_SOURCE = vector_perfomance_test_ft.cpp
VECTOR_UNIT_TEST_FT_SOURCE = vector_unit_test_ft.cpp

VECTOR_PERFOMANCE_TEST_STD_SOURCE = vector_perfomance_test_std.cpp
VECTOR_UNIT_TEST_STD_SOURCE = vector_unit_test_std.cpp

VECTOR_PERFOMANCE_TEST_FT_OBJECTS = $(VECTOR_PERFOMANCE_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
VECTOR_UNIT_TEST_FT_OBJECTS = $(VECTOR_UNIT_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)

VECTOR_PERFOMANCE_TEST_STD_OBJECTS = $(VECTOR_PERFOMANCE_TEST_STD_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
VECTOR_UNIT_TEST_STD_OBJECTS = $(VECTOR_UNIT_TEST_STD_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)



MAP_PERFOMANCE_TEST_FT = map_perfomance_test_ft
MAP_PERFOMANCE_TEST_STD = map_perfomance_test_std

MAP_UNIT_TEST_FT = map_unit_test_ft
MAP_UNIT_TEST_STD = map_unit_test_std

MAP_PERFOMANCE_TEST_FT_SOURCE = map_perfomance_test_ft.cpp
MAP_UNIT_TEST_FT_SOURCE = map_unit_test_ft.cpp

MAP_PERFOMANCE_TEST_STD_SOURCE = map_perfomance_test_std.cpp
MAP_UNIT_TEST_STD_SOURCE = map_unit_test_std.cpp

MAP_PERFOMANCE_TEST_FT_OBJECTS = $(MAP_PERFOMANCE_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
MAP_UNIT_TEST_FT_OBJECTS = $(MAP_UNIT_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)

MAP_PERFOMANCE_TEST_STD_OBJECTS = $(MAP_PERFOMANCE_TEST_STD_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
MAP_UNIT_TEST_STD_OBJECTS = $(MAP_UNIT_TEST_STD_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)



STACK_PERFOMANCE_TEST_FT = stack_perfomance_test_ft
STACK_PERFOMANCE_TEST_STD = stack_perfomance_test_std

STACK_UNIT_TEST_FT = stack_unit_test_ft
STACK_UNIT_TEST_STD = stack_unit_test_std

STACK_PERFOMANCE_TEST_FT_SOURCE = stack_perfomance_test_ft.cpp
STACK_UNIT_TEST_FT_SOURCE = stack_unit_test_ft.cpp

STACK_PERFOMANCE_TEST_STD_SOURCE = stack_perfomance_test_std.cpp
STACK_UNIT_TEST_STD_SOURCE = stack_unit_test_std.cpp

STACK_PERFOMANCE_TEST_FT_OBJECTS = $(STACK_PERFOMANCE_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
STACK_UNIT_TEST_FT_OBJECTS = $(STACK_UNIT_TEST_FT_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)

STACK_PERFOMANCE_TEST_STD_OBJECTS = $(STACK_PERFOMANCE_TEST_STD_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)
STACK_UNIT_TEST_STD_OBJECTS = $(STACK_UNIT_TEST_STD_SOURCE:%.cpp=$(OBJECTS_DIR)%.o)



all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) -o $@



enable_if: SHELL := /bin/bash
enable_if: $(ENABLE_IF_TEST_FT)
		./$(ENABLE_IF_TEST_FT)

$(ENABLE_IF_TEST_FT): $(OBJECTS_DIR) $(ENABLE_IF_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(ENABLE_IF_TEST_FT_OBJECTS) -o $@


intra: SHELL := /bin/bash
intra: $(INTRA_TEST_FT) $(INTRA_TEST_STD)
		diff <(./$(INTRA_TEST_FT) 42) <(./$(INTRA_TEST_STD) 42) | wc -l
		@echo ""
		./$(INTRA_TEST_FT) 42
		@echo ""
		./$(INTRA_TEST_STD) 42

$(INTRA_TEST_FT): $(OBJECTS_DIR) $(INTRA_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(INTRA_TEST_FT_OBJECTS) -o $@

$(INTRA_TEST_STD): $(OBJECTS_DIR) $(INTRA_TEST_STD_OBJECTS)
	@$(CC) $(FLAGS) $(INTRA_TEST_STD_OBJECTS) -o $@



vector: SHELL := /bin/bash
vector: $(VECTOR_PERFOMANCE_TEST_FT) $(VECTOR_PERFOMANCE_TEST_STD) $(VECTOR_UNIT_TEST_FT) $(VECTOR_UNIT_TEST_STD)
		./$(VECTOR_PERFOMANCE_TEST_FT)
		@echo ""
		./$(VECTOR_PERFOMANCE_TEST_STD)
		@echo ""
		diff <(./$(VECTOR_UNIT_TEST_FT)) <(./$(VECTOR_UNIT_TEST_STD)) | wc -l
		@echo ""
		diff -y <(./$(VECTOR_UNIT_TEST_FT)) <(./$(VECTOR_UNIT_TEST_STD))

$(VECTOR_PERFOMANCE_TEST_FT): $(OBJECTS_DIR) $(VECTOR_PERFOMANCE_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(VECTOR_PERFOMANCE_TEST_FT_OBJECTS) -o $@

$(VECTOR_PERFOMANCE_TEST_STD): $(OBJECTS_DIR) $(VECTOR_PERFOMANCE_TEST_STD_OBJECTS)
	@$(CC) $(FLAGS) $(VECTOR_PERFOMANCE_TEST_STD_OBJECTS) -o $@

$(VECTOR_UNIT_TEST_FT): $(OBJECTS_DIR) $(VECTOR_UNIT_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(VECTOR_UNIT_TEST_FT_OBJECTS) -o $@

$(VECTOR_UNIT_TEST_STD): $(OBJECTS_DIR) $(VECTOR_UNIT_TEST_STD_OBJECTS)
	@$(CC) $(FLAGS) $(VECTOR_UNIT_TEST_STD_OBJECTS) -o $@



map: SHELL := /bin/bash
map: $(MAP_PERFOMANCE_TEST_FT) $(MAP_PERFOMANCE_TEST_STD) $(MAP_UNIT_TEST_FT) $(MAP_UNIT_TEST_STD)
		./$(MAP_PERFOMANCE_TEST_FT)
		@echo ""
		./$(MAP_PERFOMANCE_TEST_STD)
		@echo ""
		diff <(./$(MAP_UNIT_TEST_FT)) <(./$(MAP_UNIT_TEST_STD)) | wc -l
		@echo ""
		diff -y <(./$(MAP_UNIT_TEST_FT)) <(./$(MAP_UNIT_TEST_STD))

$(MAP_PERFOMANCE_TEST_FT): $(OBJECTS_DIR) $(MAP_PERFOMANCE_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(MAP_PERFOMANCE_TEST_FT_OBJECTS) -o $@

$(MAP_PERFOMANCE_TEST_STD): $(OBJECTS_DIR) $(MAP_PERFOMANCE_TEST_STD_OBJECTS)
	@$(CC) $(FLAGS) $(MAP_PERFOMANCE_TEST_STD_OBJECTS) -o $@

$(MAP_UNIT_TEST_FT): $(OBJECTS_DIR) $(MAP_UNIT_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(MAP_UNIT_TEST_FT_OBJECTS) -o $@

$(MAP_UNIT_TEST_STD): $(OBJECTS_DIR) $(MAP_UNIT_TEST_STD_OBJECTS)
	@$(CC) $(FLAGS) $(MAP_UNIT_TEST_STD_OBJECTS) -o $@



stack: SHELL := /bin/bash
stack: $(STACK_PERFOMANCE_TEST_FT) $(STACK_PERFOMANCE_TEST_STD) $(STACK_UNIT_TEST_FT) $(STACK_UNIT_TEST_STD)
		./$(STACK_PERFOMANCE_TEST_FT)
		@echo ""
		./$(STACK_PERFOMANCE_TEST_STD)
		@echo ""
		diff <(./$(STACK_UNIT_TEST_FT)) <(./$(STACK_UNIT_TEST_STD)) | wc -l
		@echo ""
		diff -y <(./$(STACK_UNIT_TEST_FT)) <(./$(STACK_UNIT_TEST_STD))

$(STACK_PERFOMANCE_TEST_FT): $(OBJECTS_DIR) $(STACK_PERFOMANCE_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(STACK_PERFOMANCE_TEST_FT_OBJECTS) -o $@

$(STACK_PERFOMANCE_TEST_STD): $(OBJECTS_DIR) $(STACK_PERFOMANCE_TEST_STD_OBJECTS)
	@$(CC) $(FLAGS) $(STACK_PERFOMANCE_TEST_STD_OBJECTS) -o $@

$(STACK_UNIT_TEST_FT): $(OBJECTS_DIR) $(STACK_UNIT_TEST_FT_OBJECTS)
	@$(CC) $(FLAGS) $(STACK_UNIT_TEST_FT_OBJECTS) -o $@

$(STACK_UNIT_TEST_STD): $(OBJECTS_DIR) $(STACK_UNIT_TEST_STD_OBJECTS)
	@$(CC) $(FLAGS) $(STACK_UNIT_TEST_STD_OBJECTS) -o $@



$(OBJECTS_DIR)%.o: %.cpp $(HEADERS)
	@$(CC) -c $(FLAGS) $< -I$(HEADERS) -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	

clean:
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(ENABLE_IF_TEST_FT)
	@rm -f $(INTRA_TEST_FT)
	@rm -f $(INTRA_TEST_STD)
	@rm -f $(VECTOR_PERFOMANCE_TEST_FT)
	@rm -f $(VECTOR_PERFOMANCE_TEST_STD)
	@rm -f $(VECTOR_UNIT_TEST_FT)
	@rm -f $(VECTOR_UNIT_TEST_STD)
	@rm -f $(MAP_PERFOMANCE_TEST_FT)
	@rm -f $(MAP_PERFOMANCE_TEST_STD)
	@rm -f $(MAP_UNIT_TEST_FT)
	@rm -f $(MAP_UNIT_TEST_STD)
	@rm -f $(STACK_PERFOMANCE_TEST_FT)
	@rm -f $(STACK_PERFOMANCE_TEST_STD)
	@rm -f $(STACK_UNIT_TEST_FT)
	@rm -f $(STACK_UNIT_TEST_STD)

re: fclean all
