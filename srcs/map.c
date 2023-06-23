/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:59:33 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/23 15:05:23 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*extract_file(char *filename, t_vars *v)
{
	int		fd;
	int		i;
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
	int		i;

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

	i = 0;
	while (i < v->map->height)
	{
		j = 0;
		while (j < v->map->width)
		{
			if (lines[j + (i * v->map->width)] == 'E')
				v->map->exit_count++;
			else if (lines[j + (i * v->map->width)] == 'C')
				v->map->collectibles_count++;
			else if (lines[j + (i * v->map->width)] == 'P')
			{
				v->map->player_count++;
				v->coord->x = j;
				v->coord->y = i;
			}	
			grid[i][j] = lines[j + (i * v->map->width)];
			j++;
		}
		grid[i++][j] = '\0';
	}
	v->map->grid = grid;
}

void	draw_map(t_vars *v)
{
//	t_img	img;
	int		i;
	int		j;
	int		s;
	char	*move_count_str;

	v->img->w = mlx_xpm_file_to_image(v->mlx, WALL_IMG, &s, &s);
	v->img->c = mlx_xpm_file_to_image(v->mlx, COLLECTIBLES_IMG, &s, &s);
	v->img->m = mlx_xpm_file_to_image(v->mlx, MONSTER_IMG, &s, &s);
	v->img->p = mlx_xpm_file_to_image(v->mlx, PLAYER_IMG, &s, &s);
	v->img->e = mlx_xpm_file_to_image(v->mlx, EXIT_IMG, &s, &s);
	move_count_str = ft_itoa(v->move_count);
	i = 0;
	while (i < v->map->height)
	{
		j = 0;
		while (j < v->map->width)
		{
			if (v->map->grid[i][j] == '1')
				mlx_put_image_to_window(v->mlx, v->win, v->img->w, j * CS, i * CS);
			else if (v->map->grid[i][j] == 'C')
				mlx_put_image_to_window(v->mlx, v->win, v->img->c, j * CS, i * CS);
			else if (v->map->grid[i][j] == 'M')
				mlx_put_image_to_window(v->mlx, v->win, v->img->m, j * CS, i * CS);
			else if (v->map->grid[i][j] == 'E')
				mlx_put_image_to_window(v->mlx, v->win, v->img->e, j * CS, i * CS);
			j++;
		}
		i++;
	}
	mlx_string_put(v->mlx, v->win, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(v->mlx, v->win, 60, 10, 0xFFFFFF, move_count_str);
	mlx_put_image_to_window(v->mlx, v->win, v->img->p, v->coord->x * CS, v->coord->y * CS);
	mlx_key_hook(v->win, key_hook, v);
	mlx_loop(v->mlx);
}
