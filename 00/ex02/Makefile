SRCS = sources/tests.cpp  \
		sources/Account.cpp

OBJS = objets/tests.o  \
		objets/Account.o

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = log

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
