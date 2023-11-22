#ifndef SO_LONG_H
#define SO_LONG_H

    #include <stdlib.h>
    #include <unistd.h>
    #include "mlx/mlx.h"
    #include <fcntl.h>
    #include "includes/libft/libft.h"

    /* Defining keycodes of keys but it could be vary depeding on keybord layout */
    #define ESC 53
    #define W  13
    #define A 0
    #define S 1
    #define D 2

    /* Assets */
    #define FLOOR "assets/floor.xpm"
    #define CHARACTER "assets/character.xpm"
    #define WALL "assets/wall.xpm"
    #define COLLECT "assets/collect.xpm"
    #define EXIT "assets/exit.xpm"

    typedef struct s_game {
        int height;
        int width;
        char **map;
        int x_position;
        int y_position;
        int collectible;
        int moves;
        int temp;
        int exit_number;
    }   t_game;

    typedef struct s_data {
        void *mlx_ptr;
        void *mlx_win;
        void *mlx_img;
        t_game *game;
    } t_data;

    /* utils.c */
    void ft_print_str(char *str);
    int ft_strlennl(char *str);
    void init_game_struct(t_data *data);
    void print_move_number(t_data *data);
    void free_cpy_map(t_data *data, char **map_cpy);
    /* utils.c but get_next_line*/
    #define BUFFER_SIZE 1
    char	*move_line(char *r_line);
    char	*read_line(char *r_line);
    char	*get_next_line(int fd);
    size_t	ft_strlen(const char *s);
    char	*ft_strchr(const char *s, int c);
    char	*ft_join(char *s1, char *s2, int bytes);
    char	*ft_strcpy(char *dest, char *src);

    /* read_map.c */
    void read_map(t_data *data, char *map_file);
    int check_map_ext(char *map_file);

    /* error_handling.c */
    void error_handling(t_data *data, char *error_type);
    void free_map_and_print_error(t_data *data, char *error_type);

    /* map_validating.c */
    void validate_map(t_data *data);
    void check_map_chars(t_data *data, int height, int width);
    int validate_every_char(t_data *data, int height, int width);
    int validate_char_number(t_data *data, int height, int width, char map_char);
    void character_first_position(t_data *data);

    /* wall_validating.c */
    void top_bottom_wall_validate(t_data *data, int height, int width);
    void side_wall_validate(t_data *data, int height, int width);

    /* flood_fill.c */
    void flood_fill(t_data *data, char *map_file);
    char **copy_map(t_data *data, char *map_file);
    void flood(t_data *data, char **map_cpy, int x, int y);
    int flood_path_exit_block(t_data *data, char **map_cpy, int x, int y);

    /* start_game.c */
    void init_game_mlx(t_data *data);
    int key_handling(int key, t_data *data);
    void move_character(t_data *data, int x, int y);
    void move_to_collectible(t_data *data, int x, int y);

    /* draw_window.c */
    void draw_window(t_data *data);
    void draw_background(t_data *data, char *img);
    void put_image(t_data *data, char *img, int x, int y);
    void draw_map(t_data *data, char c, int x, int y);

    /* exit_handling.c */
    void exit_check(t_data *data, int val);
    void free_map(t_data *data);
    int exit_game(t_data *data);

#endif
