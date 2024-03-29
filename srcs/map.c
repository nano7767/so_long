/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:59:33 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/11 11:31:17 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*extract_file(t_vars *v)
{
	int		fd;
	int		i;
	char	*lines;
	char	*tmp;
	char	*next;

	lines = ft_strdup("");
	i = 0;
	fd = open(v->filename, O_RDONLY);
	while (1)
	{
		tmp = lines;
		next = get_next_line(fd);
		if (next == NULL)
			break ;
		lines = ft_strjoin(tmp, next);
		free(tmp);
		free(next);
		v->map->height++;
		if (v->map->height == 1)
			v->map->width = ft_strlen(lines);
	}
	close(fd);
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
				v->map->collect_count++;
			else if (lines[j + (i * v->map->width)] == 'P')
			{
				v->map->player_count++;
				v->p->x = j;
				v->p->y = i;
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
	int		i;
	int		j;

	i = -1;
	while (i++ < v->map->height - 1)
	{
		j = -1;
		while (j++ < v->map->width - 1)
		{
			mlx_put_image_to_window(v->mlx, v->win, v->img->b, j * CS, i * CS);
			if (v->map->grid[i][j] == '1')
				mlx_put_image_to_window(
					v->mlx, v->win, v->img->w, j * CS, i * CS);
			else if (v->map->grid[i][j] == 'C')
				mlx_put_image_to_window(
					v->mlx, v->win, v->img->c, j * CS, i * CS);
			else if (v->map->grid[i][j] == 'E')
				mlx_put_image_to_window(
					v->mlx, v->win, v->img->e, j * CS, i * CS);
		}
	}
	player_movement(v);
}

void	player_movement(t_vars *v)
{
	char	*move_count_str;
	char	*moves;

	move_count_str = ft_itoa(v->p->move_count);
	moves = ft_strjoin("Moves : ", move_count_str);
	mlx_string_put(v->mlx, v->win, 10, 10, 0xFFFFFF, moves);
	free(move_count_str);
	free(moves);
	mlx_put_image_to_window(
		v->mlx, v->win, v->img->p, v->p->x * CS, v->p->y * CS);
	mlx_key_hook(v->win, key_hook, v);
	red_cross(v);
	mlx_loop(v->mlx);
}
