/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:41:14 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/25 15:53:59 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_legality(t_vars *v)
{
	if (!file_ext(v))
	{
		ft_printf("Error\n");
		ft_printf("map file does not have .ber extension");
		exit(1);
	}
	if ((!is_rectangular(v)) || (!is_surrounded_by_walls(v)))
	{
		ft_printf("Error\n");
		ft_printf("not rectangular or surrounded by walls");
		exit(1);
	}
	if (v->map->exit_count != 1 || v->map->collect_count < 1 
		|| v->map->player_count != 1)
	{
		ft_printf("Error\n");
		ft_printf("map does not meet minimum requirements");
		exit(1);
	}
}

int	file_ext(t_vars *v)
{
	char	*ext;
	int		indx;
	int		i;

	ext = v->filename;
	indx = (int)ft_strlen(v->filename) - 4;
	i = 0;
	if (!ft_strncmp((ext + indx), ".ber", 4))
		return (1);
	return (0);
}

int	is_rectangular(t_vars *v)
{
	int	i;

	i = 0;
	while (i < v->map->height)
	{
		if ((int)(ft_strlen(v->map->grid[i])) != v->map->width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_vars *v)
{
	int	i;

	i = 0;
	while (i < v->map->width - 1)
	{
		if (v->map->grid[0][i] != '1' || 
			v->map->grid[v->map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < v->map->height)
	{
		if (v->map->grid[i][0] != '1' || 
			v->map->grid[i][v->map->width - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}
