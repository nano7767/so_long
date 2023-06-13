/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:05:36 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/13 16:07:56 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*
int	main(void)
{
	char	*line;
	t_map	*map;
	
	map = malloc(sizeof(t_map));
	line = extract_file(MAP_FILE, map);
	printf("the height is %d\n", map->height);
	printf("the width is %d\n", map->width);
	printf("%s", line);
}
*/

int	main(int argc, char **argv)
{
	t_map   *map;
	char	*filename;
	char	*lines;
	char	**grid;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	if (argc == 1)
		filename = MAP_FILE;
	else
		filename = argv[1];
	 
	lines = extract_file(filename, map);
	if (!lines)
	{
		free(map);
		return (1);	
	}

	printf("%s\n", lines);
	grid = create_grid(map);
	fill_grid(grid, lines, map);
	printf("the height is %d\n", map->height);
	printf("the width is %d\n", map->width);
	printf("the exit count is %d\n", map->exit_count);
	printf("the collectible count is %d\n", map->collectible_count);
	printf("the player count is %d\n", map->player_count);
	draw_map(map);
	free(grid);
	return (0);
}

