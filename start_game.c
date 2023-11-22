#include "so_long.h"

/* It changes the image of the collectible when the character reaches it and it decreases the
   number of the collectibles by one every time it is called */
void move_to_collectible(t_data *data, int x, int y)
{
    put_image(data, FLOOR, x, y);
    put_image(data, FLOOR, data->game->x_position, data->game->y_position);
    put_image(data, CHARACTER, x, y);
    data->game->collectible -= 1;
}

/* It moves the character based on the reached character. It handles every situation in different way and
   it also counts every moves which is done by the character */
void move_character(t_data *data, int x, int y)
{
    char c;

    c = data->game->map[y][x];
    if (c == '1')
        return;
    if (c == '0')
    {
        put_image(data, FLOOR, data->game->x_position, data->game->y_position);
        put_image(data, CHARACTER, x, y);
    }
    if (c == 'C')
        move_to_collectible(data, x, y);
    if (c == 'E' && data->game->collectible == 0)
        exit_check(data, 1);
    if (c == 'E' && data->game->collectible != 0)
    {
        exit_check(data, 0);
        return;
    }
    data->game->x_position = x;
    data->game->y_position = y;
    data->game->moves += 1;
    print_move_number(data);
}

/* This function will be called whenever a key release event occurs due to this function:
   mlx_key_hook(data->mlx_win, key_handling, data); and it will call other functions based on the
   key which is released */
int key_handling(int key, t_data *data)
{
    int x;
    int y;

    x = data->game->x_position;
    y = data->game->y_position;
    data->game->map[y][x] = '0';
    if (key == S)
        move_character(data, x, (y + 1));
    if (key == W)
        move_character(data, x, (y - 1));
    if (key == A)
        move_character(data, (x - 1), y);
    if (key == D)
        move_character(data, (x + 1), y);
    if (key == ESC)
    {
        ft_putstr_fd("The game is closed", 1);
        exit_game(data);
    }
    return (0);
}


/* This function uses MiniLibx functions to establish a connection between application and 
   underlying graphical system. It is the core function to make the whole application to work */
void init_game_mlx(t_data *data)
{
    int map_w;
    int map_h;

    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == (void *)0)
        free_map_and_print_error(data, "Error\n");
    map_w = data->game->width;
    map_h = data->game->height;
    data->mlx_win = mlx_new_window(data->mlx_ptr, map_w * 48, map_h * 48, "some_game");
    if (data->mlx_win == (void *)0)
        free_map_and_print_error(data, "Error\n");
    draw_window(data);
    mlx_key_hook(data->mlx_win, key_handling, data);
    mlx_hook(data->mlx_win, 17, 0, exit_game, data);
    mlx_loop(data->mlx_ptr);
}