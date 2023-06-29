/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:41:14 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/29 15:09:41 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_legality(t_vars *v)
{
	file_validity(v);
	map_ting(v);
	if (v->error->invalid_file == 1 || v->error->file_ext == 1)
	{
		ft_printf("Error, invalid file\n");
		ft_printf("file unreadable or file does not have .ber extension");
		exit(1);
	}
	if (v->error->rectangular == 1 || v->error->walls == 1
		|| v->error->character == 1)
	{
		ft_printf("Error, invalid map\n");
		ft_printf("map is not rectangular/surrounded by walls");
		ft_printf("or map contains external characters");
		exit(1);
	}
	if (v->map->exit_count != 1 || v->map->collect_count < 1
		|| v->map->player_count != 1)
	{
		ft_printf("Error\n");
		ft_printf("map needs an exit, a player and at least 1 collectibles");
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
		if ((int)ft_strlen(v->map->grid[i]) != v->map->width)
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
