NAME = game

F =	main\
	UI/AWidget\
	UI/AClickableWidget\
	UI/Menu\
	UI/Button\
	utils/Coord

S = $(foreach f, $(F), srcs/$(f).cpp)
OBJ = $(S:.cpp=.o)

GFLAGS = -Wall -Werror -Wextra -Iheaders -g `sdl2-config --cflags --libs`

all: $(NAME)
r: re
	./$(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(GFLAGS) -o $(NAME)

.cpp.o:
	c++ -o $@ -c $< $(GFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all