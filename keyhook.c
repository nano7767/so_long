/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:15:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/18 13:25:05 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;
*/
int	key_hook(int keycode, t_vars *v)
{
	printf("the coord->x %d\n", v->coord->x);
	printf("the coord->y %d\n", v->coord->y);
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
/*
int	main(void)
{
	t_vars	v;

	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, 640, 480, "window.exe");
	mlx_key_hook(v.win, key_hook, &v);
	mlx_loop(v.mlx);
}*/
