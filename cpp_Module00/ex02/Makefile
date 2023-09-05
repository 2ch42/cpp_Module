NAME = megaphone
DEFFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98
CC = c++
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(DEFFLAGS) $(CPPFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
