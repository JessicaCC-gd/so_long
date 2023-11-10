/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:46:52 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 17:32:46 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_mem(t_vars *v)
{
	int	i;

	i = -1;
	while (v->map[++i])
		free(v->map[i]);
	free(v->map);
	mlx_destroy_image(v->mlx, v->img.floor);
	mlx_destroy_image(v->mlx, v->img.rb);
	mlx_destroy_image(v->mlx, v->img.wall);
	mlx_destroy_image(v->mlx, v->img.finish);
	mlx_destroy_image(v->mlx, v->img.colectible);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free(v->mlx);
}

int	kill_game(t_vars *v)
{
	free_mem(v);
	ft_printf("Quitting game\n");
	exit(0);
}

void	finish_game(t_vars *v)
{
	ft_printf("colected: %d\n", v->counters.ccounter);
	ft_printf("You did it!!\n");
	kill_game(v);
}

int	press_event_handler(int keycode, t_vars *v)
{
	if (keycode == 65307)
		kill_game(v);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		movement_handler(keycode, v);
	return (0);
}

int	main(int argc, char **argv)
{
	int		map_file;
	char	**map;
	t_vars	v;

	if (argc != 2)
		no_map();
	ft_bzero(&v, sizeof(t_vars));
	map_file = open (argv[1], O_RDONLY);
	if (map_file == -1)
		no_map();
	v.map = read_map (map_file, &v);
	map = v.map;
	v.mlx = mlx_init();
	v.win = mlx_new_window (v.mlx, (ft_strlen(*map) - 1) * 64,
			count_map_lines(map) * 64, "It Sucks");
	assign_textures (&v);
	draw_map (&v);
	mlx_hook (v.win, 3, 1L << 1, press_event_handler, &v);
	mlx_hook (v.win, 17, 1L << 19, kill_game, &v);
	mlx_loop (v.mlx);
	return (0);
}
