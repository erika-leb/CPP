SRCS = main.cpp  \

OBJS = main.o  \

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = brain

all: $(NAME)
$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
