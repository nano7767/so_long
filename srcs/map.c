#include "so_long.h"

char	*extract_file(char *filename, t_vars *v)
{
	int	fd;
	int	i;
	char	*lines;
	char	*tmp;
	char	*next;

	lines = ft_strdup("");
	i = 0;
	v->map->height = 0;
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
		v->map->height++;
		if (v->map->height == 1)
			v->map->width = ft_strlen(lines);
	}
	return (lines);
}


char	**create_grid(t_vars *v)
{
	char	**grid;
	int	i;

	grid = malloc(sizeof(char *) * v->map->height);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < v->map->height)
	{
		grid[i] = malloc((sizeof(char) * v->map->width) + 1);
		if (!grid[i])
			return (NULL);
		i++;
	}
	return (grid);
}

void	fill_grid(char **grid, char *lines, t_vars *v)
{
	int	i;
	int	j;
	int	k;
//	t_player	coord;

	i = 0;
	j = 0;
	k = 0;
	v->map->exit_count = 0;
	v->map->collectible_count = 0;
	v->map->player_count = 0;
	while (lines[k])
	{
		while (j < v->map->width)
		{
			if (lines[k] == 'E')
				v->map->exit_count++;
			else if (lines[k] == 'C')
				v->map->collectible_count++;
			else if (lines[k] == 'P')
			{
				v->map->player_count++;
				v->coord->x = j;
				v->coord->y = i;
			}
				
			grid[i][j] = lines[k];
			j++;
			k++;
		}
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
	v->map->grid = grid;
}

void	draw_map(t_vars *v)
{
	//t_vars	vars;
	void	*wall;
	void	*collectibles;
	void	*monster;
	void	*player;
	void	*exit;
	int		i;
	int		j;
	int		cell_size;

	wall = mlx_xpm_file_to_image(v->mlx, WALL_IMG, &cell_size, &cell_size);
	collectibles = mlx_xpm_file_to_image(v->mlx, COLLECTIBLES_IMG, &cell_size, &cell_size);
	monster = mlx_xpm_file_to_image(v->mlx, MONSTER_IMG, &cell_size, &cell_size);
	player = mlx_xpm_file_to_image(v->mlx, PLAYER_IMG, &cell_size, &cell_size);
	exit = mlx_xpm_file_to_image(v->mlx, EXIT_IMG, &cell_size, &cell_size);
	i = 0;
	while (i < v->map->height)
	{
		j = 0;
		while (j < v->map->width)
		{
			if (v->map->grid[i][j] == '1')
				mlx_put_image_to_window(v->mlx, v->win, wall, j * CELL_SIZE, i * CELL_SIZE);
			else if (v->map->grid[i][j] == 'C')
				mlx_put_image_to_window(v->mlx, v->win, collectibles,  j * CELL_SIZE, i * CELL_SIZE);
			else if (v->map->grid[i][j] == 'M')
				mlx_put_image_to_window(v->mlx, v->win, monster, j * CELL_SIZE, i * CELL_SIZE);
			else if (v->map->grid[i][j] == 'E')
				mlx_put_image_to_window(v->mlx, v->win, exit, j * CELL_SIZE, i * CELL_SIZE);
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(v->mlx, v->win, player, v->coord->x * CELL_SIZE, v->coord->y * CELL_SIZE);
	mlx_key_hook(v->win, key_hook, v);
	mlx_loop(v->mlx);
}
