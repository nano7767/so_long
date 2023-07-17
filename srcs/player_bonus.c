/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:54:37 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/11 11:05:51 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_vars *v, int x, int y)
{
	if (v->map->grid[v->p->y + y][v->p->x + x] == '1' || (v->map->grid
		[v->p->y + y][v->p->x + x] == 'E' && v->map->collect_count != 0))
		return ;
	v->p->x += x;
	v->p->y += y;
	if (v->map->grid[v->p->y][v->p->x] == 'C')
	{
		v->map->collect_count--;
		v->map->grid[v->p->y][v->p->x] = '0';
	}
	else if (v->map->grid[v->p->y][v->p->x] == 'M')
	{
		ft_printf("game over");
		exit(1);
	}
	if (v->map->grid[v->p->y][v->p->x] == 'E' && v->map->collect_count == 0)
	{
		ft_printf("you win!\n");
		exit(1);
	}
	v->map->grid[v->p->y][v->p->x] = '0';
	v->map->grid[v->p->y][v->p->x] = 'P';
	v->p->move_count++;
	mlx_clear_window(v->mlx, v->win);
	draw_map(v);
}
