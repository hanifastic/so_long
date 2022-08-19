/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:26:24 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:37:37 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_texture_2(t_list *game, char *a, int x, int y)
{
	game->p.p_down_2 = mlx_xpm_file_to_image \
		(a, "./img/player_down_3.xpm", &x, &y);
	game->tex_exit_open_2 = mlx_xpm_file_to_image \
		(a, "./img/exit_open_3.xpm", &x, &y);
	game->tex_coin_2 = mlx_xpm_file_to_image(a, "./img/coin_1_2.xpm", &x, &y);
	game->p.p_up_2 = mlx_xpm_file_to_image \
		(a, "./img/player_up_3.xpm", &x, &y);
	game->p.p_right_2 = mlx_xpm_file_to_image \
		(a, "./img/player_right_3.xpm", &x, &y);
	game->p.p_left_2 = mlx_xpm_file_to_image \
		(a, "./img/player_left_3.xpm", &x, &y);
}

void	ft_texture(t_list *game)
{
	char	*a;
	int		x;
	int		y;

	a = game->mlx;
	x = game->x;
	y = game->y;
	game->tex_wall = mlx_xpm_file_to_image(a, "./img/wall_2.xpm", &x, &y);
	game->tex_gnd = mlx_xpm_file_to_image(a, "./img/ground_2.xpm", &x, &y);
	game->tex_coin = mlx_xpm_file_to_image(a, "./img/coin_2.xpm", &x, &y);
	game->tex_exit_close = mlx_xpm_file_to_image \
		(a, "./img/exit_close_2.xpm", &x, &y);
	game->tex_exit_open = mlx_xpm_file_to_image \
		(a, "./img/exit_open_2.xpm", &x, &y);
	game->p.p_right = mlx_xpm_file_to_image \
		(a, "./img/player_right_2.xpm", &x, &y);
	game->p.p_left = mlx_xpm_file_to_image \
		(a, "./img/player_left_2.xpm", &x, &y);
	game->p.p_up = mlx_xpm_file_to_image \
		(a, "./img/player_up_2.xpm", &x, &y);
	game->p.p_down = mlx_xpm_file_to_image \
		(a, "./img/player_down_2.xpm", &x, &y);
	ft_texture_2(game, a, x, y);
}

void	c_set_count(t_list *game)
{
	game->first_last = 0;
	game->wall_up_size = 0;
	game->wall_down_size = 0;
	game->count_coin = 0;
	game->count_exit = 0;
	game->p.count_player = 0;
	game->count_wall = 0;
	game->coin_adder = 0;
	game->exit_status = 0;
	game->count_move = 1;
	game->p.p_direction = 'R';
}

void	c_add_count(t_list *game)
{
	game->coin_adder++;
	open_exit(game);
}

void	print_values(t_list *game)
{
	char	*a;

	mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, 32 * 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, 32 * 1, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, 32 * 2, 0);
	mlx_string_put(game->mlx, game->win, 0, 10, 0xFFFF00, "Coin: ");
	a = ft_itoa(game->coin_adder);
	mlx_string_put(game->mlx, game->win, 50, 10, 0xFFFF00, a);
	free(a);
	mlx_string_put(game->mlx, game->win, 0, 20, 0xFFFF00, "Moves:");
	a = ft_itoa(game->count_move);
	mlx_string_put(game->mlx, game->win, 50, 20, 0xFFFF00, a);
	free(a);
	print_move(game);
}
