NAME = PmergeMe
CC = c++
CFLAGS =

SRC = 	./src/main.cpp \
		./src/PmergeMe.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing .o files"
	@rm -f $(OBJ)

fclean: clean
	@echo "Cleaning up the workspace"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re