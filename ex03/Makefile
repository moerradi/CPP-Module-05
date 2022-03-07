NAME=Intern
FLAGS=-Wall -Wextra -Werror
SRCS=Bureaucrat.cpp Form.cpp main.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp Intern.cpp

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o
	rm -rf *_shrubbery
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re