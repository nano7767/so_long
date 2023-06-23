/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:05:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/23 15:07:05 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialise(t_vars *v)
{
//	int	s;
//	v->mlx = mlx_init();
//	v->win = mlx_new_window(v->mlx, v->map->width * CS, v->map->height * CS, "");
	v->map->exit_count = 0;
	v->map->collectibles_count = 0;
	v->map->player_count = 0;
	v->move_count = 0;
	/*v->img->w = mlx_xpm_file_to_image(v->mlx, WALL_IMG, &s, &s);
	v->img->c = mlx_xpm_file_to_image(v->mlx, COLLECTIBLES_IMG, &s, &s);
	v->img->m = mlx_xpm_file_to_image(v->mlx, MONSTER_IMG, &s, &s);
	v->img->p = mlx_xpm_file_to_image(v->mlx, EXIT_IMG, &s, &s);*/
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
	v->map = malloc(sizeof(t_map));
	if (!v->map)
		return (1);
	v->coord = malloc(sizeof(t_player));
	if (!v->coord)
		return (1);
	v->img = malloc(sizeof(t_img));
	if (!v->img)
		return (1);
	if (argc == 1)
		filename = MAP_FILE;
	else
		filename = ft_strjoin("maps/", argv[1]);
	initialise(v);
	lines = extract_file(filename, v);
	ft_printf("%s\n", lines);
	grid = create_grid(v);
	fill_grid(grid, lines, v);
	ft_printf("the height is %d\n", v->map->height);
	ft_printf("the width is %d\n", v->map->width);
	ft_printf("the exit count is %d\n", v->map->exit_count);
	ft_printf("the collectibles count is %d\n", v->map->collectibles_count);
	ft_printf("the player count is %d\n", v->map->player_count);
	map_legality(v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->map->width * CS, v->map->height * CS, "map");
	draw_map(v);
	free(grid);
	return (0);
}

