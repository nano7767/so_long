/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:07:24 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/11 11:34:06 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# define CS 32
# define MAP_FILE	"maps/longnoM.ber"
# define BACKGROUND_IMG "assets/background.xpm"
# define WALL_IMG	"assets/wall.xpm"
# define COLLECTIBLES_IMG	"assets/collectibles.xpm"
# define MONSTER_IMG	"assets/monster.xpm"
# define PLAYER_IMG	"assets/player.xpm"
# define EXIT_IMG	"assets/exit.xpm"

typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
	int		exit_count;
	int		collect_count;
	int		player_count;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		move_count;
}			t_player;

typedef struct s_img
{
	void	*b;
	void	*w;
	void	*c;
	void	*m;
	void	*e;
	void	*p;
}			t_img;

typedef struct s_error
{
	int		invalid_file;
	int		file_ext;
	int		rectangular;
	int		walls;
	int		character;
	int		path;
}			t_error;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		*filename;
	t_map		*map;
	t_player	*p;
	t_img		*img;
	t_error		*error;
}			t_vars;

//map.c
char	*extract_file(t_vars *v);
char	**create_grid(t_vars *v);
void	fill_grid(char **grid, char *lines, t_vars *v);
void	player_movement(t_vars *v);
void	draw_map(t_vars *v);

//keyhook.c
int		key_hook(int keycode, t_vars *v);

//player.c
void	move_player(t_vars *v, int x, int y);

//validity.c
void	map_legality(t_vars *v);
void	file_validity(t_vars *v);
void	map_ting(t_vars *v);
void	path_validity(t_vars *v);
int		path_finder(t_vars *v, char **grid, int x, int y);

//exit.c
int		exit_program(t_vars *v);
void	red_cross(t_vars *v);
#endif
