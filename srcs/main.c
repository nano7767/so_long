/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:05:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/20 15:53:46 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*v;
	char	*filename;
	char	*lines;
	char	**grid;
	int	width;
	int	height;

	v = malloc(sizeof(t_vars));
	if (!v)
		return (1);
	v->map = malloc(sizeof(t_map));
	if (!v->map)
		return (1);
	v->coord = malloc(sizeof(t_player));
	if (!v->coord)
		return(1);
	if (argc == 1)
		filename = MAP_FILE;
	else
		filename = ft_strjoin("maps/", argv[1]);
	 
	lines = extract_file(filename, v);
	if (!lines)
	{
		free(v->map);
		return (1);	
	}

	ft_printf("%s\n", lines);
	grid = create_grid(v);
	fill_grid(grid, lines, v);
	ft_printf("the height is %d\n", v->map->height);
	ft_printf("the width is %d\n", v->map->width);
	ft_printf("the exit count is %d\n", v->map->exit_count);
	ft_printf("the collectible count is %d\n", v->map->collectible_count);
	ft_printf("the player count is %d\n", v->map->player_count);
	ft_printf("x = %d, y = %d\n", v->coord->x, v->coord->y);
	map_legality(v);
	width = CELL_SIZE * v->map->width;
	height = CELL_SIZE * v->map->height;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->map->width * CELL_SIZE, v->map->height * CELL_SIZE, "map");
	draw_map(v);
	free(grid);
	return (0);
}

