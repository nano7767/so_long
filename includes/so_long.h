/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:07:24 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/18 13:09:44 by svikornv         ###   ########.fr       */
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
# define COLLECTIBLES_IMG	"maps/collectibles.xpm"
# define ENEMY_IMG	"maps/enemy.xpm"
# define PLAYER_IMG	"maps/player.xpm"

typedef struct s_map
{
	int	width;
	int	height;
	char	**grid;
	int	exit_count;
	int	collectible_count;
	int	player_count;
}		t_map;

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

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
	t_map	*map;
	t_player	*coord;
}		t_vars;

//map.c
char	*extract_file(char *filename, t_map *map);
char	**create_grid(t_map *map);
void	fill_grid(char **grid, char *lines, t_map *map, t_player *coord);
void	draw_map(t_map *map, t_player *coord);

//keyhook.c
int	key_hook(int keycode, t_vars *v);

//player.c
void	move_player(t_vars *v, int x, int y);
#endif
