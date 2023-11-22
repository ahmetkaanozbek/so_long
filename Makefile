NAME = so_long
SRC_FILES =  main.c \
				utils.c \
				map_reading.c \
				error_handling.c \
				map_validating.c \
				wall_validating.c \
				start_game.c \
				draw_window.c \
				exit_handling.c \
				flood_fill.c \
				
OBJ_FILES = $(SRC_FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIB = ./mlx/libmlx.a ./includes/libft/libft.a
MAKE_MLX = make -C ./mlx
MAKE_LIBFT = make -C ./includes/libft

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@$(MAKE_LIBFT)
	@$(MAKE_MLX)
	@cc $(OBJ_FILES) $(FLAGS) $(LIB) -framework OpenGL -framework Appkit -o $(NAME)

clean :
	rm -f $(OBJ_FILES)
	rm -f ./mlx/*.o
	rm -f ./includes/libft/*.o

fclean : clean
	rm -f $(NAME)
	rm -f ./mlx/*.a
	rm -f ./includes/libft/*.a

re : fclean all

.PHONY : all clean fclean re