#include "so_long.h"

/* Checks if the map's chars are one of these characters: '1', '0', 'E', 'P', 'C' */
int validate_every_char(t_data *data, int height, int width)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < height)
    {
        while (j < width)
        {
            if (ft_strchr("10EPC", data->game->map[i][j]) == NULL)
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

/* Checks if there is one exit, one starting point and at least one collectible */
int validate_char_number(t_data *data, int height, int width, char map_char)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (i < height)
    {
        while(j < width)
        {
            if (data->game->map[i][j] == map_char)
                count++;
            j++;
        }
        j = 0;
        i++;
    }
    if ((map_char == 'P' || map_char == 'E') && (count == 1))
        return (1);
    if ((map_char == 'C') && (count > 0))
    {
        data->game->collectible = count;
        return (1);
    }
    return (0);
}

/* It checks if all characters exist on the map. Also it checks if they appear in right number */
void check_map_chars(t_data *data, int height, int width)
{
    if (!(validate_every_char(data, height, width)))
        free_map_and_print_error(data, "Error\nMap can only consists of these chars: '1', '0', 'E', 'P', 'C'");
    if (!(validate_char_number(data, height, width, 'E')))
        free_map_and_print_error(data, "Error\nThere can be only one exit in the map\n");
    if (!(validate_char_number(data, height, width, 'P')))
        free_map_and_print_error(data, "Error\nThere can be only one starting point in the map\n");
    if (!(validate_char_number(data, height, width, 'C')))
        free_map_and_print_error(data, "Error\nThere should be at least one collectible in the map\n");
}

/* Finds the character's first position on the map */
void character_first_position(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < data->game->height)
    {
        while (x < data->game->width)
        {
            if (data->game->map[y][x] == 'P')
            {
                data->game->x_position = x;
                data->game->y_position = y;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

/* Checks if the map has rectangular shape and also all sides of the map consist of 1s */
void validate_map(t_data *data)
{
    int width;
    int row;
    
    row = 0;
    width = ft_strlennl(data->game->map[0]);
    while (row < data->game->height)
    {
        if (width != ft_strlennl(data->game->map[row]))
            free_map_and_print_error(data, "Error\nMap doesn't have the rectangular shape\n");
        row++;
    }
    data->game->width = width;
    top_bottom_wall_validate(data, data->game->height, width);
    side_wall_validate(data, data->game->height, width);
    check_map_chars(data, data->game->height, width);
    character_first_position(data);
}