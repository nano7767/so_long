#include "so_long.h"

char	*extract_file(char *filename, t_map *map)
{
	int	fd;
	int	i;
	char	*lines;
	char	*tmp;
	char	*next;

	lines = ft_strdup("");
	i = 0;
	map->height = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		tmp = lines;
		next = get_next_line(fd);
		if (next == NULL)
			break ;
		lines = ft_strjoin(tmp, next);
		free(tmp);
		tmp = NULL;
		map->height++;
		if (map->height == 1)
			map->width = ft_strlen(lines);
	}
	return (lines);
}


char	**create_grid(t_map *map)
{
	char	**grid;
	int	i;

	grid = malloc(sizeof(char *) * map->height);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		grid[i] = malloc((sizeof(char) * map->width) + 1);
		if (!grid[i])
			return (NULL);
		i++;
	}
	return (grid);
}
/*
void	fill_grid(char **grid, char *lines, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	map->player_count = 0;
	while (lines[k])
	{
		if (j == map->width)
		{
			i++;
			j = 0;
			k++;
		}
		grid[i][j] = lines[k];
		if (lines[k] == 'E')
			map->exit_count++;
		else if (lines[k] == 'C')
			map->collectible_count++;
		else if (lines[k] == 'P')
			map->player_count++;
		k++;
		j++;
	}
	map->grid = grid;
}
*/
void	fill_grid(char **grid, char *lines, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	map->player_count = 0;
	while (lines[k])
	{
		while (j < map->width)
		{
			if (lines[k] == 'E')
				map->exit_count++;
			else if (lines[k] == 'C')
				map->collectible_count++;
			else if (lines[k] == 'P')
				map->player_count++;
			grid[i][j] = lines[k];
			j++;
			k++;
		}
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
	map->grid = grid;
}

void	draw_map(t_map *map)
{
	void	*mlx;
	void	*win;
	int	i;
	int	j;
	int	cell_size;
	int	colour;

	cell_size = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, map->width * cell_size, map->height * cell_size, "Map");
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == '0')
				colour = 0x00FFFFFF;
			else if (map->grid[i][j] == '1')
				colour = 0x0000000;
			else if (map->grid[i][j] == 'C')
				colour = 0x00FFD700;
			else if (map->grid[i][j] == 'E')
				colour = 0x00FF0000;
			else if (map->grid[i][j] == 'P')
				colour =  0x0000FF00;
			mlx_pixel_put(mlx, win, j * cell_size, i * cell_size, colour);
			mlx_pixel_put(mlx, win, j * cell_size + cell_size - 1, i * cell_size, colour);
			mlx_pixel_put(mlx, win, j * cell_size, i * cell_size + cell_size - 1, colour);
			mlx_pixel_put(mlx, win, j * cell_size + cell_size - 1, i * cell_size + cell_size - 1, colour);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
