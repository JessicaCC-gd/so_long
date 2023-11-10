/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:04:32 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 15:43:23 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdio.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_player
{
	int	pixel_height;
	int	pixel_width;
	int	map_x;
	int	map_y;
}				t_player;

typedef struct s_textures
{
	void		*floor;
	void		*rb;
	void		*wall;
	void		*finish;
	void		*colectible;
}	t_textures;

typedef struct s_counters
{
	int			steps;
	int			ccounter;
	int			collectibles;
}	t_counters;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	char		new_tile;
	char		prev_tile;
	t_counters	counters;
	t_player	player;
	t_textures	img;
}				t_vars;

void	assign_textures(t_vars *v);
void	draw_map(t_vars *v);
int		count_map_lines(char **map);
char	**read_map(int map_file, t_vars *v);
t_vars	vars_copy(t_vars *v);
int		kill_game(t_vars *v);
int		no_map(void);
void	finish_game(t_vars *v);
void	map_tester(t_vars *v);
int		invalid_map(t_vars *v);
char	**replicate_map(t_vars *v);
void	path_test(int *pec, int *p_coord, t_vars *v);
void	movement_handler(int keycode, t_vars *v);
void	finish_check(t_vars *v);
t_vars	*find_player(t_vars *v);
void	print_map(t_vars *v);

#endif
