NAME = convert

SRC_DIR = src/
OBJ_DIR = objs/
INC_DIR = includes/

INCS = -I$(INC_DIR)

SRC =	main.cpp \
		Tokenizer.cpp \
		Parser.cpp \
		Generator.cpp

OBJ := $(SRC:%.cpp=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=gnu++2b

all: $(NAME)

$(NAME): $(SRCS) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@$(CC) $(CXXFLAGS) $(INCS) $< -c -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)