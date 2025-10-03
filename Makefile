NAME = game

F =	main\
	Controller\
	UI/AWidget\
	UI/AClickableWidget\
	UI/Panel\
	UI/Menu\
	UI/Text\
	UI/Button\
	utils/Coord

S = $(foreach f, $(F), srcs/$(f).cpp)
OBJ = $(S:.cpp=.o)

GFLAGS = -Wall -Werror -Wextra -Iheaders -g `sdl2-config --cflags --libs` -lSDL2_ttf -g

all: $(NAME)
r: re
	./$(NAME)

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(GFLAGS) -o $(NAME)

.cpp.o:
	c++ -o $@ -c $< $(GFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all