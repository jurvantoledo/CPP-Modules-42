NAME 	= btc
CC 		= c++
CFLAGS 	= -Wall -Werror -Wextra -std=c++98

SRC 	= main.cpp BitcoinExchange.cpp
DEPS	= BitcoinExchange.hpp

OBJ = ${SRC:%.cpp=%.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re