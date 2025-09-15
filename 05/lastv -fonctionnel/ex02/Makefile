NAME = test

SRCS = ./sources/main.cpp \
		./sources/Bureaucrat.cpp \
		./sources/AForm.cpp \
		./sources/ShrubberyCreationForm.cpp \
		./sources/RobotomyRequestForm.cpp \
		./sources/PresidentialPardonForm.cpp

OBJS = $(SRCS:./sources/%.cpp=./objects/%.o)
DEPS = $(OBJS:.o=.d)

CC = c++
CFLAGS = -Wall -Wextra -Werror -ggdb -std=c++98 -I./includes -MMD -MP

all: $(NAME)

./objects:
	mkdir -p ./objects

./objects/%.o: ./sources/%.cpp | ./objects
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

-include $(DEPS)

clean:
	@$(RM) -r ./objects

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
