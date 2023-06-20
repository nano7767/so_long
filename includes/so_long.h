/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:07:24 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/20 16:41:12 by svikornv         ###   ########.fr       */
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
# define CELL_SIZE 32
# define MAP_FILE	"maps/classic.ber"
# define WALL_IMG	"maps/wall.xpm"
# define COLLECTIBLES_IMG	"maps/collectibles.xpm"
# define MONSTER_IMG	"maps/monster.xpm"
# define PLAYER_IMG	"maps/player.xpm"
# define EXIT_IMG	"maps/exit.xpm"
# define BACKGROUND_IMG "maps/background.xpm"

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
char	*extract_file(char *filename, t_vars *v);
char	**create_grid(t_vars *v);
void	fill_grid(char **grid, char *lines, t_vars *v);
void	draw_map(t_vars *v);

//keyhook.c
int	key_hook(int keycode, t_vars *v);

//player.c
void	move_player(t_vars *v, int x, int y);

//validity.c
void	map_legality(t_vars *v);
int	is_rectangular(t_vars *v);
int	is_surrounded_by_walls(t_vars *v);

#endif
