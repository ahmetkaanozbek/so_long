#include "so_long.h"

/* This function checks if the map file has .ber extension */
int check_map_ext(char *map_file)
{
    int i;

    i = 0;
    while(map_file[i])
        i++;
    i--;
    if (map_file[i] == 'r' && map_file[i-1] == 'e' && map_file[i-2] == 'b' && map_file[i-3] == '.')
        return (1);
    else
        return (0);
}

/* It calculates the height of the map and stores it in the data->game->height*/
void get_height(t_data *data, char *map_file)
{
    int fd;
    char *line;

    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        error_handling(data, "Error\nCouldn't open the file\n");
    while (42)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        data->game->height += 1;
        free(line);
    }
    close(fd);
}

/* Parses the map and allocating memory for each row */
void parse_map(t_data *data, char *map_file)
{
    int height;
    int fd;
    char *line;

    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        error_handling(data, "Error\nCouldn't open the file\n");
    height = data->game->height;
    data->game->map = (char **)malloc(sizeof(char *) * (height + 1));
    if (data->game->map == NULL)
        error_handling(data, "Error\nMalloc error");
    height = 0;
    while (42)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        data->game->map[height] = ft_strdup(line);
        height++;
        free(line);
    }
    data->game->map[height] = 0;
    close(fd);
}

/* It reads and parses the map and checks if the given map fulfills the requirements */
void read_map(t_data *data, char *map_file)
{
    if (!(check_map_ext(map_file)))
        error_handling(data, "Error\nExtension of the map file should be .ber\n");
    get_height(data, map_file);
    if (data->game->height == 0)
        error_handling(data, "Error\nThere is no map\n");
    parse_map(data, map_file);
    validate_map(data);
}
