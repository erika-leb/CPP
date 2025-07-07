SRCS = sources/main.cpp  \
		sources/Zombie.cpp  \
		sources/zombieHorde.cpp

OBJS = objets/main.o  \
		objets/Zombie.o  \
		objets/zombieHorde.o

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = horde

all: $(NAME)
$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

objets/%.o: sources/%.cpp
	mkdir -p objets
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f objets/*.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
