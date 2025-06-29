FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook
 #a changer

all: $(NAME)
$(NAME):
	c++ $(FLAGS) Contact.cpp PhoneBook.cpp main.cpp -o $(NAME)

clean:
	rm -f Contact.o PhoneBook.o main.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
