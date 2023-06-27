/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:21:23 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/27 12:26:52 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
	return (0);
}

void	red_cross(t_vars *v)
{
	mlx_hook(v->win, 17, 0, exit_program, v);
}
