#include "so_long.h"

/* It calls suitable mlx function to convert a xpm file to a usable one for mlx library function and
   put the image on the window with using mlx_put_image_to_window() */
void put_image(t_data *data, char *img, int x, int y)
{
    int w;
    int h;

    x *= 48;
    y *= 48;

    data->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img, &w, &h);
    if (data->mlx_img == (void *)0)
        free_map_and_print_error(data, "Error\nAn error occurred when opening the image file");
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, x, y);
}

/* This function iterates the whole window and calls a function to put a background image on every
   pixel on the window */
void draw_background(t_data *data, char *img)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < data->game->height)
    {
        while (x < data->game->width)
        {
            put_image(data, img, x, y);
            x++;
        }
        x = 0;
        y++;
    }
}

/* This function calls put_image() function with related arguments based on the present argument which
   passed in to it */
void draw_map(t_data *data, char c, int x, int y)
{
    if (c == '1')
        put_image(data, WALL, x, y);
    if (c == 'E')
        put_image(data, EXIT, x, y);
    if (c == 'C')
        put_image(data, COLLECT, x, y);
    if (c == 'P')
        put_image(data, CHARACTER, x, y);
}

/* It calls various functions to put every character on the map as an image. Also it calls 
   draw_background() function to create background image */
void draw_window(t_data *data)
{
    int w;
    int h;
    char c;

    draw_background(data, FLOOR);
    w = 0;
    h = 0;
    while (h < data->game->height)
    {
        while (w < data->game->width)
        {
            draw_map(data, data->game->map[h][w], w, h);
            w++;
        }
        w = 0;
        h++;
    }
}

