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

void	fill_grid(char **grid, char *lines, t_map *map, t_player *coord)
{
	int	i;
	int	j;
	int	k;
//	t_player	coord;

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
			{
				map->player_count++;
				coord->x = j;
				coord->y = i;
			}
				
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

void	draw_map(t_map *map, t_player *coord)
{
	t_vars	v;
	void	*wall;
	void	*collectibles;
	void	*enemy;
	void	*player;
	int		i;
	int		j;
	int		cell_size;

	cell_size = 50;
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, map->width * cell_size, map->height * cell_size, "Map");
	wall = mlx_xpm_file_to_image(v.mlx, WALL_IMG, &cell_size, &cell_size);
	collectibles = mlx_xpm_file_to_image(v.mlx, COLLECTIBLES_IMG, &cell_size, &cell_size);
	enemy = mlx_xpm_file_to_image(v.mlx, ENEMY_IMG, &cell_size, &cell_size);
	player = mlx_xpm_file_to_image(v.mlx, PLAYER_IMG, &cell_size, &cell_size);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == '1')
				mlx_put_image_to_window(v.mlx, v.win, wall, j * cell_size * 0.75, i * cell_size * 0.75);
			else if (map->grid[i][j] == 'C')
				mlx_put_image_to_window(v.mlx, v.win, collectibles,  j * cell_size * 0.75, i * cell_size * 0.75);
			else if (map->grid[i][j] == 'E')
				mlx_put_image_to_window(v.mlx, v.win, enemy, j * cell_size * 0.75, i * cell_size * 0.75);
			//else if (map->grid[i][j] == 'P')
				//mlx_put_image_to_window(v.mlx, v.win, player, j *cell_size * 0.75, i * cell_size * 0.75);
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(v.mlx, v.win, player, coord->x * cell_size * 0.75, coord->y * cell_size * 0.75);
	/*v.coord->x = coord->x;
	v.coord->y = coord->y;
	v.map->grid = map->grid;*/
	v.coord = coord;
	v.map = map;
	mlx_key_hook(v.win, key_hook, &v);
	mlx_loop(v.mlx);
}
