#include "so_long.h"

/* It frees dynamically allocated memory area of game */
void error_handling(t_data *data, char *error_type)
{
    int i;

    i = 0;
    while (error_type[i])
    {
        write(1, &error_type[i], 1);
        i++;
    }
    free(data->game);
    exit(EXIT_FAILURE);
}


/* We have to free dynamically allocated memory area of map and it's each element */
void free_map_and_print_error(t_data *data, char *error_type)
{
    int i;

    i = 0;
    while (i < data->game->height)
    {
        free(data->game->map[i]);
        i++;
    }
    free(data->game->map);
    error_handling(data, error_type);
}