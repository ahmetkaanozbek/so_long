#include "so_long.h"

/* It exists to print error reasons */
void ft_print_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

/* Not a usual strlen function because get_next_line puts new line to end of the each line */
int ft_strlennl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

/* It frees the copied map which is used for flood_fill algorithm */
void free_cpy_map(t_data *data, char **map_cpy)
{
    int i;

    i = 0;
    while(i < data->game->height)
    {
        free(map_cpy[i]);
        i++;
    }
    free(map_cpy);
}

/* Initializes t_game struct variables to prevent any unwanted results in the program */
void init_game_struct(t_data *data)
{
	data->game->height = 0;
	data->game->width = 0;
	data->game->x_position = 0;
	data->game->y_position = 0;
	data->game->collectible = 0;
	data->game->moves = 0;
	data->game->temp = 0;
	data->game->exit_number = 1;
}

/* It prints the total number of the moves every time a move is occurred */
void print_move_number(t_data *data)
{
	ft_putstr_fd("Current number of the moves which the player made: ", 1);
	ft_putnbr_fd(data->game->moves, 1);
	write(1, "\n", 1);
}

/* get_next_line.c This program returns a line, which ends with '\n' or '\0', of the file 
   every time it is called until end of file */
char	*move_line(char *r_line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (r_line[i] != '\0' && r_line[i] != '\n')
		i++;
	if (r_line[i] == '\0')
	{
		free(r_line);
		return (NULL);
	}
	if (r_line[i] == '\n')
		i++;
	new_line = (char *)malloc((ft_strlen(r_line) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	ft_strcpy(new_line, r_line + i);
	free(r_line);
	return (new_line);
}

char	*read_line(char *r_line)
{
	int		i;
	char	*a_line;

	i = 0;
	if (!r_line || !r_line[0])
		return (NULL);
	while (r_line[i] != '\0' && r_line[i] != '\n')
		i++;
	if (r_line[i] == '\n')
		i++;
	a_line = (char *)malloc((1 + i) * sizeof(char));
	if (!a_line)
		return (NULL);
	i = 0;
	while (r_line[i] != '\0' && r_line[i] != '\n')
	{
		a_line[i] = r_line[i];
		i++;
	}
	if (r_line[i] == '\n')
		a_line[i++] = '\n';
	a_line[i] = '\0';
	return (a_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!(ft_strchr(buffer, '\n')) && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			free(buffer);
			return (buffer = NULL);
		}
		buffer = ft_join(buffer, tmp, bytes);
	}
	free(tmp);
	tmp = read_line(buffer);
	buffer = move_line(buffer);
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_join(char *s1, char *s2, int bytes)
{
	char	*res;
	int		i;

	i = 0;
	s2[bytes] = '\0';
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	ft_strcpy((res + i), s2);
	free(s1);
	return (res);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/* get_next_line.c */