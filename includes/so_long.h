/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:07:24 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/13 16:55:52 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft.h"
# define MAP_FILE	"maps/classic.ber"
# define WALL_IMG	"maps/wall.xpm"
typedef struct s_map
{
	int	width;
	int	height;
	char	**grid;
	int	exit_count;
	int	collectible_count;
	int	player_count;
}		t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

char	*extract_file(char *filename, t_map *map);
char	**create_grid(t_map *map);
void	fill_grid(char **grid, char *lines, t_map *map);
void	draw_map(t_map *map);

#endif
