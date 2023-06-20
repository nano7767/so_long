/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:08:34 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/20 15:52:25 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_vars *v, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = v->coord->x + x;
	ft_printf("new_x%d\n", new_x);
	new_y = v->coord->y + y;
	ft_printf("new_y%d\n", new_y);
	ft_printf("collectible count:%d\n", v->map->collectible_count);
	if (v->map->collectible_count == 0)
		exit(1);
	if (v->map->grid[new_y][new_x] != '1' || (v->map->grid[new_y][new_x] == 'E' && v->map->collectible_count != 0))
	{
		if (v->map->grid[new_y][new_x] == 'C')
		{
			v->map->collectible_count--;
			v->map->grid[new_y][new_x] = '0';
		}
		else if (v->map->grid[new_y][new_x] == 'E' && v->map->collectible_count == 0)
			exit(1);
		else if (v->map->grid[new_y][new_x] == 'M')
		{
			ft_printf("game over");	
			exit(1);
		}
		v->map->grid[v->coord->y][v->coord->x] = '0';
		v->coord->x = new_x;
		v->coord->y = new_y;
		v->map->grid[v->coord->y][v->coord->x] = 'P';
		mlx_clear_window(v->mlx, v->win);
		draw_map(v);
	}
}
