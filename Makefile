NAME = game

F =	main\
	UI/Button\
	utils/Coord

S = $(foreach f, $(F), srcs/$(f).cpp)
OBJ = $(S:.cpp=.o)

GFLAGS = -Wall -Werror -Wextra -Iheaders -g
CFLAGS = `sdl2-config --libs`

all: $(NAME)
r: re
	./$(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(GFLAGS) $(CFLAGS) -o $(NAME)

.cpp.o:
	c++ -o $@ -c $< $(GFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all