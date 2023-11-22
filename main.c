#include "so_long.h"

/* main function to initialize and allocate memory and also it checks if there is more than two
   command line arguments (Program's name is also an argument)*/
int main(int argc, char **argv)
{
    t_data data;

    if (argc == 2)
    {
        data.game = malloc(sizeof(t_game));
        init_game_struct(&data);
        read_map(&data, argv[1]);
        flood_fill(&data, argv[1]);
        init_game_mlx(&data);
    }
    else
    {
        ft_print_str("Wrong amount of arguments: only one argument.\n");
        exit(1);
    }
}