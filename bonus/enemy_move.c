/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:42 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:39:46 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_right_move(t_list *game, int x, int y)
{
	if (game->map[y][x + 1] == '1' && game->map[y][x - 1] == '1')
	{
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'L';
		if (game->player.p_anim_i == 2000)
			place(game, game->enemy.enemy_right_1, x, y);
		else
			place(game, game->enemy.enemy_right_2, x, y);
	}
	else if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'C' \
		&& game->map[y][x + 1] != 'E')
		x = enemy_right_move_2_2(game, x, y);
	else
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'L';
	return (x);
}

int	enemy_left_move(t_list *game, int x, int y)
{
	if (game->map[y][x + 1] == '1' && game->map[y][x - 1] == '1')
	{
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'R';
		if (game->player.p_anim_i == 2000)
			place(game, game->enemy.enemy_left_1, x, y);
		else
			place(game, game->enemy.enemy_left_2, x, y);
	}
	else if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'C' \
		&& game->map[y][x - 1] != 'E')
		x = enemy_right_move_2_3(game, x, y);
	else
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'R';
	return (x);
}
