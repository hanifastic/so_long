/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:45:17 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:49:09 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_painting_2(t_list *game)
{
	char	*a;
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	a = game->mlx;
	ft_texture(game, a, x, y);
	ft_map_check(game, -1, -2);
}

void	enemy_random_direction(t_list *game)
{
	if (game->enemy.enemy_index % 2 == 0)
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'R';
	if (game->enemy.enemy_index % 2 != 0)
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'L';
}

void	player_assigment(t_list *game, int x, int y)
{
	game->player.count_player++;
	place(game, game->player.player_right, x, y);
	game->player.p_x = x;
	game->player.p_y = y;
}

void	map_objects(t_list *game, int x, int y, char o)
{
	if (o == 'E')
	{
		game->count_exit++;
		place(game, game->tex_exit_close, x, y);
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (o == 'P')
		player_assigment(game, x, y);
	else if (o == 'A')
	{
		place(game, game->enemy.enemy_right_1, x, y);
		enemy_random_direction(game);
		game->enemy.enemy_index++;
	}
	else if (o == 'C')
	{
		game->count_coin++;
		place(game, game->tex_coin, x, y);
	}
	else
		ft_exit(1);
}
