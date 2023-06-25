/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:15:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/25 14:56:40 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *v)
{
	ft_printf("collectible count: %d\n", v->map->collect_count);
	if (keycode == 53)
		mlx_destroy_window(v->mlx, v->win);
	if (keycode == 13)
		move_player(v, 0, -1);
	else if (keycode == 0)
		move_player(v, -1, 0);
	else if (keycode == 1)
		move_player(v, 0, 1);
	else if (keycode == 2)
		move_player(v, 1, 0);
	return (0);
}
