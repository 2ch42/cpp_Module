NAME = btc
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
CXX = c++
SRCS = BitcoinExchange.cpp main.cpp
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
