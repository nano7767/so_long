/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:41:14 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/09 12:57:17 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_legality(t_map *map, t_list *lst)
{
	if (!is_rectangular(map) || !is_surrounded_by_walls(map))
	{
		//free_map(map);
		exit(1);
	}
	else if (map->exit_count != 1 || map->collectible_count < 1 || map->player_count != 1)
	{
		//free_map(map);
		exit(1);
	}
}

int	is_rectangular(t_map *map)
{
	int	i;
	
	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) != map->width)
			return (0);
		return (1);
	}
}

int	is_surrounded_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < map->height - 1)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
}
