#include "so_long.h"

/* This is a typical flood_fill algorithm which tries to access every '0' character which is not blocked 
   by any walls ('1') and 'X' characters (characters which has been accessed already by the character)
   and it decrements the number of the collectibles and exit every time it reaches them to understand is 
   there a way to finish the game successfully which means is there any valid path */
void flood(t_data *data, char **map_cpy, int x, int y)
{
    while(map_cpy[y][x] != '1' && map_cpy[y][x] != 'X')
    {
        if (map_cpy[y][x] == 'E')
            data->game->exit_number--;
        if (map_cpy[y][x] == 'C')
            data->game->temp--;
        map_cpy[y][x] = 'X';
        flood(data, map_cpy, (x + 1), y);
        flood(data, map_cpy, (x - 1), y);
        flood(data, map_cpy, x, (y + 1));
        flood(data, map_cpy, x, (y - 1));
    }
}

/* This function copies the original map to a new one to make the original one protected by any changes 
   due to changes which is done by flood_fill algorithm */
char **copy_map(t_data *data, char *map_file)
{
    char **map_cpy;
    int h;
    int fd;
    char *line;

    h = data->game->height;
    map_cpy = (char **)malloc(sizeof(char*) * (h + 1));
    fd = open(map_file, O_RDONLY);
    h = 0;
    while (42)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        map_cpy[h] = ft_strdup(line);
        h++;
        free(line);
    }
    map_cpy[h] = 0;
    close(fd);
    return (map_cpy);
}

/* It checks if exit character blocks collectibles to be collected by the character. It has to be done
   in a diffent flood_fill function because exit character should be treated like a block */
int flood_path_exit_block(t_data *data, char **map_cpy, int x, int y)
{
    while(map_cpy[y][x] != '1' && map_cpy[y][x] != 'X' && map_cpy[y][x] != 'E')
    {
        if (map_cpy[y][x] == 'C')
            data->game->temp--;
        map_cpy[y][x] = 'X';
        flood_path_exit_block(data, map_cpy, (x + 1), y);
        flood_path_exit_block(data, map_cpy, (x - 1), y);
        flood_path_exit_block(data, map_cpy, x, (y + 1));
        flood_path_exit_block(data, map_cpy, x, (y - 1));
    }
    if (data->game->temp != 0)
        return (1);
    return (0);
}

/* It calls various flood_fill functions and copy map functions to check if there is any valid path
   in the map to finish the game successfully. It also calls free_map_and_print_error() function in
   different kind of error situations and it also frees copied maps */
void flood_fill(t_data *data, char *map_file)
{
    char **map_cpy;
    int x;
    int y;

    y = data->game->y_position;
    x = data->game->x_position;
    map_cpy = copy_map(data, map_file);
    data->game->temp = data->game->collectible;
    flood(data, map_cpy, x, y);
    free_cpy_map(data, map_cpy);
    map_cpy = copy_map(data, map_file);
    if (data->game->temp)
        free_map_and_print_error(data, "Error\nNo valid path: Walls prevent collectibles from being collected");
    if (data->game->exit_number)
        free_map_and_print_error(data, "Error\nNo valid path: Walls prevent all ways to exit");
    data->game->temp = data->game->collectible;
    if (flood_path_exit_block(data, map_cpy, x, y))
    {    
        free_cpy_map(data, map_cpy);
        free_map_and_print_error(data, "Error\nNo valid path: Exit prevents collectibles from being collected");
    }
    free_cpy_map(data, map_cpy);
}