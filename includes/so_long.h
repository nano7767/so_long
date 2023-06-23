/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:07:24 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/23 14:57:25 by svikornv         ###   ########.fr       */
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
# define CS 32
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
	int	collectibles_count;
	int	player_count;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
}
			t_player;

typedef struct s_img
{
	void	*w;
	void	*c;
	void	*m;
	void	*e;
	void	*p;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int	move_count;
	t_map	*map;
	t_player	*coord;
	t_img	*img;
}			t_vars;

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
