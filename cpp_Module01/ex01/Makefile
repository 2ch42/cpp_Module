NAME = test
DEFFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98
CC = c++
SRCS = Zombie.cpp zombieHorde.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(DEFFLAGS) $(CPPFLAGS) $^ -o $@

$(OBJS):	$(SRCS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
