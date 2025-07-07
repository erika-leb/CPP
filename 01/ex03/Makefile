SRCS = sources/main.cpp  \
		sources/Weapon.cpp  \
		sources/HumanA.cpp  \
		sources/HumanB.cpp

OBJS = objets/main.o  \
		objets/Weapon.o  \
		objets/HumanA.o  \
		objets/HumanB.o

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = weapon

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
