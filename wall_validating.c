#include "so_long.h"

/* Checks if the bottom and the top sides of the map consist of char 1*/
void top_bottom_wall_validate(t_data *data, int height, int width)
{
    int i;
    int last_row;

    i = 0;
    last_row = (height - 1);
    while (i < width)
    {
        if (data->game->map[0][i] != '1')
            free_map_and_print_error(data, "Error\nTop side of the map should be a wall\n");
        i++;
    }
    i = 0;
    while (i < width)
    {
        if (data->game->map[last_row][i] != '1')
            free_map_and_print_error(data, "Error\nBottom side of the map should be a wall\n");
        i++;
    }
}

/* Checks if the left and the right sides of the map consist of char 1*/
void side_wall_validate(t_data *data, int height, int width)
{
    int i;
    int last_column;
    
    i = 0;
    last_column = (width - 1);
    while (i < height)
    {
        if (data->game->map[i][0] != '1')
            free_map_and_print_error(data, "Error\nLeft side of the map should be a wall\n");
        i++;
    }
    i = 0;
    while (i < height)
    {
        if(data->game->map[i][last_column] != '1')
            free_map_and_print_error(data, "Error\nRigth side of the map should be a wall\n");
        i++;
    }
}