NAME = test
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g
CXX = c++
SRCS = Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS):	$(SRCS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
