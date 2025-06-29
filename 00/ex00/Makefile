
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex00

all: $(NAME)
$(NAME):
	c++ $(FLAGS) Megaphone.cpp -o $(NAME)

clean:
	rm -f Megaphone.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
