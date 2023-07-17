/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:41:14 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/17 13:22:22 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_legality(t_vars *v)
{
	file_validity(v);
	map_ting(v);
	path_validity(v);
	if (v->error->invalid_file == 1 || v->error->file_ext == 1)
	{
		ft_printf("Error\n");
		ft_printf("invalid file\n");
		exit(1);
	}
	if (v->error->rectangular == 1 || v->error->walls == 1
		|| v->error->character == 1 || v->error->path == 1)
	{
		ft_printf("Error\n");
		ft_printf("invalid map\n");
		exit(1);
	}
	if (v->map->exit_count != 1 || v->map->collect_count < 1
		|| v->map->player_count != 1)
	{
		ft_printf("Error\n");
		ft_printf("invalid object counts\n");
		exit(1);
	}
}

void	file_validity(t_vars *v)
{
	char	*ext;
	int		indx;
	int		fd;

	fd = open(v->filename, O_RDONLY);
	if (fd == -1)
		v->error->invalid_file = 1;
	ext = v->filename;
	indx = (int)ft_strlen(v->filename) - 4;
	if (ft_strncmp((ext + indx), ".ber", 4) != 0)
		v->error->file_ext = 1;
}

void	map_ting(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->map->height)
	{
		if (ft_strlength(v->map->grid[i]) != v->map->width - 1)
			v->error->rectangular = 1;
		if (v->map->grid[i][0] != '1' ||
		v->map->grid[i][v->map->width - 2] != '1')
			v->error->walls = 1;
		j = 0;
		while (j < v->map->width - 1)
		{
			if (v->map->grid[i][j] != '1' && v->map->grid[i][j] != '0'
				&& v->map->grid[i][j] != 'C' && v->map->grid[i][j] != 'M'
				&& v->map->grid[i][j] != 'E' && v->map->grid[i][j] != 'P')
				v->error->character = 1;
			if (v->map->grid[0][j] != '1' ||
			v->map->grid[v->map->height - 1][j] != '1')
				v->error->walls = 1;
			j++;
		}
		i++;
	}
}

void	path_validity(t_vars *v)
{
	char	**grid;
	int		width;
	int		height;
	int		x;
	int		y;

	grid = malloc(sizeof(char *) * v->map->height);
	if (!grid)
		return ;
	x = 0;
	while (x < v->map->height)
	{
		grid[x] = ft_strdup(v->map->grid[x]);
		x++;
	}
	width = v->map->width;
	height = v->map->height;
	x = v->p->x;
	y = v->p->y;
	if (path_finder(v, grid, x, y) == 1)
		v->error->path = 1;
	x = 0;
	while (x < v->map->height)
		free(grid[x++]);
	free(grid);
}

int	path_finder(t_vars *v, char **grid, int x, int y)
{
	if (x < 0 || x >= v->map->width || y < 0 || y >= v->map->height
		|| grid[y][x] == '1' || grid[y][x] == 'Y' || grid[y][x] == 'M')
		return (1);
	if (grid[y][x] == 'E')
		grid[y][x] = 'Y';
	else
	{
		grid[y][x] = 'Y';
		path_finder(v, grid, x - 1, y);
		path_finder(v, grid, x, y - 1);
		path_finder(v, grid, x + 1, y);
		path_finder(v, grid, x, y + 1);
	}
	y = 0;
	while (++y < v->map->height)
	{
		x = 0;
		while (++x < v->map->width - 1)
		{
			if (grid[y][x] != '1' && grid[y][x] != 'Y' && grid[y][x] != 'M'
				&& grid[y][x] != '0')
				return (1);
		}
	}
	return (0);
}
