#include "so_long.h"

/* It checks if all collectibles are collected by character if it is, it exits from the game with printing
   total moves made by character if it's not it prints how many are collectibles left */
void exit_check(t_data *data, int val)
{
    if (val == 1)
    {   
        ft_putstr_fd("You have collected all the keys! You are free to go :(\n", 1);
        ft_putstr_fd("Total number of moves: ", 1);
        ft_putnbr_fd(data->game->moves, 1);
        exit_game(data);
    }
    if (val == 0)
    {
        ft_putstr_fd("You are not free yet! You have to collect all the keys.\n", 1);
        ft_putstr_fd("Remaining number of keys: ", 1);
        ft_putnbr_fd(data->game->collectible, 1);
        write(1, "\n", 1);
    }
}

/* It frees dynamic memory allocated map before exiting the program */
void free_map(t_data *data)
{
    int i;

    i = 0;
    while(i < data->game->height)
    {
        free(data->game->map[i]);
        i++;
    }
    free(data->game->map);
}

/* This function terminates the whole program with using exit() function but before doing that it frees
   all the dynamically allocated memory */
int exit_game(t_data *data)
{
    free_map(data);
    free(data->game);
    exit(EXIT_SUCCESS);
}