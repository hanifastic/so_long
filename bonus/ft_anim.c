/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:38:36 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:41:05 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_and_enemy(t_list *game)
{
	int		x;
	int		y;

	x = -1;
	y = -2;
	while (++y < game->max_y)
	{
		x = -1;
		while (++y < game->max_y)
		{
			x = -1;
			x = coin_enemy_anim_2(game, x, y);
		}
	}
	game->enemy.enemy_index = 1;
	ft_count_check(game);
}

void	set_direction_1(t_list *game)
{
	int	x;
	int	y;

	x = game->player.p_x;
	y = game->player.p_y;
	coin_and_enemy(game);
	if (game->exit_status == 1)
		place(game, game->tex_exit_open, game->exit_x, game->exit_y);
	if (game->player.p_direction == 'R')
		place(game, game->player.player_right, x, y);
	else if (game->player.p_direction == 'L')
		place(game, game->player.player_left, x, y);
	else if (game->player.p_direction == 'U')
		place(game, game->player.player_up, x, y);
	else if (game->player.p_direction == 'D')
		place(game, game->player.player_down, x, y);
	else if (game->player.p_direction == 'E')
	{
		place(game, game->player.player_right_walk_1, x, y);
		game->player.p_direction = 'R';
	}
	else
		anim_2(game, x, y, 1);
}

void	set_direction_2(t_list *game)
{
	int	x;
	int	y;

	x = game->player.p_x;
	y = game->player.p_y;
	coin_and_enemy(game);
	if (game->exit_status == 1)
		place(game, game->tex_exit_open_2, game->exit_x, game->exit_y);
	if (game->player.p_direction == 'R')
		place(game, game->player.player_right_2, x, y);
	else if (game->player.p_direction == 'L')
		place(game, game->player.player_left_2, x, y);
	else if (game->player.p_direction == 'U')
		place(game, game->player.player_up_2, x, y);
	else
		anim_2(game, x, y, 0);
}

int	ft_player_animation(t_list *game)
{
	game->player.p_anim_i++;
	if (game->player.p_anim_i == 2000)
		set_direction_1(game);
	else if (game->player.p_anim_i == 4000)
		set_direction_2(game);
	if (game->player.p_anim_i > 4000)
		game->player.p_anim_i = 0;
	return (0);
}
