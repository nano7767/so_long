/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:08:34 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/18 14:22:49 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_vars *v, int x, int y)
{
	int	new_x;
	int	new_y;
	t_map	*map;
	t_player	*coord;

	new_x = v->coord->x + x;
	printf("new_x%d\n", new_x);
	new_y = v->coord->y + y;
	printf("new_y%d\n", new_y);
	printf("collectible count:%d\n", v->map->collectible_count);
	if (v->map->collectible_count == 0)
		mlx_destroy_window(v->mlx, v->win);
	if (v->map->grid[new_y][new_x] != '1' || (v->map->grid[new_y][new_x] == 'E' && v->map->collectible_count != 0))
	{
		if (v->map->grid[new_y][new_x] == 'C')
		{
			v->map->collectible_count--;
			v->map->grid[new_y][new_x] = '0';
		}
		else if (v->map->grid[new_y][new_x] == 'E' && v->map->collectible_count == 0)
			mlx_destroy_window(v->mlx, v->win);
		else if (v->map->grid[new_y][new_x] == 'M')
			mlx_destroy_window(v->mlx, v->win);
		v->map->grid[v->coord->y][v->coord->x] = '0';
		v->coord->x = new_x;
		v->coord->y = new_y;
		v->map->grid[v->coord->y][v->coord->x] = 'P';
		//mlx_clear_window(v->mlx, v->win);
		mlx_destroy_window(v->mlx, v->win);
		map = v->map;
		coord = v->coord;
		draw_map(map, coord);
	}
}
/*
void	move_player(t_vars *v, t_map *map, t_player *coord, int x, int y)
{
	int	new_x;
	int	new_y;

	printf("%d\n", coord->x);
	new_x = coord->x + x;
	printf("%d\n", new_x);
	new_y = coord->y + y;
	printf("%d\n", new_y);
	printf("%c\n", map->grid[coord->y][coord->x]);
	if (map->collectible_count == 0)
		mlx_destroy_window(v->mlx, v->win);
	if (map->grid[new_y][new_x] != '1')
	{
		if (map->grid[new_y][new_x] == 'C')
		{
			map->collectible_count--;
			map->grid[new_y][new_x] = '0';
		}
		if (map->grid[new_y][new_x] == 'E' && map->collectible_count == 0)
			mlx_destroy_window(v->mlx, v->win);
		map->grid[coord->y][coord->x] = '0';
		coord->x = new_x;
		coord->y = new_y;
		map->grid[coord->y][coord->x] = 'P';
		mlx_clear_window(v->mlx, v->win);
		draw_map(map, coord);
	}

}
*/
