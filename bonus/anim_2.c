/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:36:47 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:39:23 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_2(t_list *game, int x, int y, int status)
{
	if (status == 0)
	{
		if (game->player.p_direction == 'D')
			place(game, game->player.player_down_2, x, y);
		else if (game->player.p_direction == 'E')
		{
			place(game, game->player.player_right_walk_1, x, y);
			game->player.p_direction = 'R';
		}
		else if (game->player.p_direction == 'Q')
		{
			place(game, game->player.player_left_walk_1, x, y);
			game->player.p_direction = 'L';
		}
	}
	else
	{
		if (game->player.p_direction == 'Q')
		{
			place(game, game->player.player_left_walk_1, x, y);
			game->player.p_direction = 'L';
		}
	}
}

int	coin_enemy_anim_2(t_list *game, int x, int y)
{
	while (++x < game->max_x)
	{
		if (game->map[y][x] == 'C')
		{
			if (game->player.p_anim_i == 2000)
				place(game, game->tex_coin_2, \
					x, y);
			else
				place(game, game->tex_coin, \
					x, y);
		}
		if (game->map[y][x] == 'A')
		{
			if (game->enemy.enemy_direction \
				[game->enemy.enemy_index] == 'R')
				x = enemy_right_move(game, x, y);
			if (game->enemy.enemy_direction \
				[game->enemy.enemy_index] == 'L')
				x = enemy_left_move(game, x, y);
			game->enemy.enemy_index++;
		}
	}
	return (x);
}
