SRCS = sources/main.cpp  \
		sources/Weapon.cpp  \
		sources/HumanA.cpp  \
		sources/HumanB.cpp

OBJS = $(SRCS:sources/%.cpp=objets/%.o)
DEPS = $(OBJS:.o=.d)

FLAGS = -Wall -Wextra -Werror -ggdb -std=c++98 -MMD -MP

NAME = attack

all: $(NAME)
$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

objets/%.o: sources/%.cpp
	mkdir -p objets
	c++ $(FLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f objets/*.o objets/*.d

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
