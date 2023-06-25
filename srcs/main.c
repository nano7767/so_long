/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:05:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/25 14:54:03 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialise(t_vars *v)
{
	int	s;

	v->map = malloc(sizeof(t_map));
	if (!v->map)
		return ;
	v->p = malloc(sizeof(t_player));
	if (!v->p)
		return ;
	v->img = malloc(sizeof(t_img));
	if (!v->img)
		return ;
	v->mlx = mlx_init();
	v->map->exit_count = 0;
	v->map->collect_count = 0;
	v->map->player_count = 0;
	v->p->move_count = 0;
	v->img->w = mlx_xpm_file_to_image(v->mlx, WALL_IMG, &s, &s);
	v->img->c = mlx_xpm_file_to_image(v->mlx, COLLECTIBLES_IMG, &s, &s);
	v->img->m = mlx_xpm_file_to_image(v->mlx, MONSTER_IMG, &s, &s);
	v->img->p = mlx_xpm_file_to_image(v->mlx, PLAYER_IMG, &s, &s);
	v->img->e = mlx_xpm_file_to_image(v->mlx, EXIT_IMG, &s, &s);
}

int	main(int argc, char **argv)
{
	t_vars	*v;
	char	*filename;
	char	*lines;
	char	**grid;

	v = malloc(sizeof(t_vars));
	if (!v)
		return (1);
	if (argc == 1)
		filename = MAP_FILE;
	else
		filename = ft_strjoin("maps/", argv[1]);
	initialise(v);
	lines = extract_file(filename, v);
	grid = create_grid(v);
	fill_grid(grid, lines, v);
	map_legality(v);
	v->win = mlx_new_window(v->mlx, v->map->width * CS, 
			v->map->height * CS, "map.c");
	draw_map(v);
	free(grid);
	return (0);
}
