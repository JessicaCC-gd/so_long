/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:04:32 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 15:43:27 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdio.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>

# define ENTITIES "10PCEV"

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
	void		*cat;
}	t_textures;

typedef struct s_r_sprites
{
	void	**u;
	void	**d;
	void	**l;
	void	**r;

}	t_r_sprites;

typedef struct s_b_sprites
{
	void	*f01;
	void	*f02;
}	t_b_sprites;

typedef struct s_c_sprites
{
	void	**frames;
}	t_c_sprites;

typedef struct s_counters
{
	int			steps;
	int			ccounter;
	int			collectibles;
}	t_counters;

typedef struct s_patrol
{
	int	pixel_height;
	int	pixel_width;
	int	map_x;
	int	map_y;
	int	counter;
}	t_patrol;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		last_move;
	char		**map;
	t_patrol	cat;
	void		*scoreboard;
	char		new_tile;
	char		prev_tile;
	t_counters	counters;
	t_player	player;
	t_r_sprites	r_spt;
	t_b_sprites	b_spt;
	t_c_sprites	c_spt;
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
int		animate(t_vars *v);
int		patrol(t_vars *v);
void	map_tester(t_vars *v);
int		invalid_map(t_vars *v);
char	**replicate_map(t_vars *v);
void	path_test(int *pec, int *p_coord, t_vars *v);
void	movement_handler(int keycode, t_vars *v);
void	finish_check(t_vars *v);
t_vars	*find_player(t_vars *v);
void	move_patrol(t_vars *v, int i);
void	print_map(t_vars *v);

#endif
