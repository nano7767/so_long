/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:05:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/17 14:10:33 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_malloc(t_vars *v)
{
	v->map = malloc(sizeof(t_map));
	if (!v->map)
		return ;
	v->p = malloc(sizeof(t_player));
	if (!v->p)
		return ;
	v->img = malloc(sizeof(t_img));
	if (!v->img)
		return ;
	v->error = malloc(sizeof(t_error));
	if (!v->error)
		return ;
}

void	initialise(t_vars *v)
{
	int	s;

	v->mlx = mlx_init();
	v->map->exit_count = 0;
	v->map->collect_count = 0;
	v->map->player_count = 0;
	v->map->height = 0;
	v->p->move_count = 0;
	v->error->invalid_file = 0;
	v->error->file_ext = 0;
	v->error->rectangular = 0;
	v->error->walls = 0;
	v->error->character = 0;
	v->error->path = 0;
	v->img->b = mlx_xpm_file_to_image(v->mlx, BACKGROUND_IMG, &s, &s);
	v->img->w = mlx_xpm_file_to_image(v->mlx, WALL_IMG, &s, &s);
	v->img->c = mlx_xpm_file_to_image(v->mlx, COLLECTIBLES_IMG, &s, &s);
	v->img->m = mlx_xpm_file_to_image(v->mlx, MONSTER_IMG, &s, &s);
	v->img->p = mlx_xpm_file_to_image(v->mlx, PLAYER_IMG, &s, &s);
	v->img->e = mlx_xpm_file_to_image(v->mlx, EXIT_IMG, &s, &s);
}

int	main(int argc, char **argv)
{
	t_vars	*v;
	char	*lines;
	char	**grid;

	v = malloc(sizeof(t_vars));
	if (!v)
		return (1);
	if (argc == 1)
	{
		ft_printf("empty parameter\n");
		return (1);
	}
	else
		v->filename = argv[1];
	init_malloc(v);
	initialise(v);
	lines = extract_file(v);
	grid = create_grid(v);
	fill_grid(grid, lines, v);
	map_legality(v);
	v->win = mlx_new_window(v->mlx, (v->map->width * CS) - 33,
			v->map->height * CS, "map.c");
	draw_map(v);
	return (0);
}
