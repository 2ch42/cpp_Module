NAME = test
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
CXX = c++
SRCS = Fixed.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

$(OBJS):	$(SRCS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
