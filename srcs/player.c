/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:08:34 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/23 14:58:24 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_vars *v, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = v->coord->x + x;
	new_y = v->coord->y + y;
	ft_printf("collectibles count:%d\n", v->map->collectibles_count);
	if (v->map->grid[new_y][new_x] != '1' && v->map->grid[new_y][new_x] != 'E')
	{
		if (v->map->grid[new_y][new_x] == 'C')
		{
			v->map->collectibles_count--;
			v->map->grid[new_y][new_x] = '0';
		}
		else if (v->map->grid[new_y][new_x] == 'M')
		{
			ft_printf("game over");	
			exit(1);
		}
		v->move_count++;
		v->coord->x = new_x;
		v->coord->y = new_y;
		v->map->grid[v->coord->y][v->coord->x] = 'P';
		mlx_clear_window(v->mlx, v->win);
		draw_map(v);
	}
	else if (v->map->grid[new_y][new_x] == 'E' && v->map->collectibles_count == 0)
	{
		ft_printf("you win!\n");
		exit(1);
	}
}
