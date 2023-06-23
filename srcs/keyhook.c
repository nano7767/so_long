/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:15:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/23 10:00:54 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *v)
{
	ft_printf("coord->x %d\n", v->coord->x);
	ft_printf("coord->y %d\n", v->coord->y);
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
