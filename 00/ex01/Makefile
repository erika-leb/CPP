SRCS = sources/Contact.cpp  \
		sources/PhoneBook.cpp  \
		sources/main.cpp

OBJS = objets/Contact.o  \
		objets/PhoneBook.o  \
		objets/main.o

FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = phonebook

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
