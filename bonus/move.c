/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:44:29 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/17 01:50:59 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(t_list *game)
{
	int	y;

	y = 0;
	while (y < game->max_y)
	{
		y++;
	}
}

void	ft_move(t_list *game, int x, int y, void *obje)
{
	char	*str;

	str = NULL;
	if (game->map[game->player.p_y + y][game->player.p_x + x] != '1' \
		&& game->map[game->player.p_y + y][game->player.p_x + x] != 'E')
		ft_move_2(game, x, y, obje);
	else if (game->map[game->player.p_y + y][game->player.p_x + x] != '1' \
		&& game->map[game->player.p_y + y][game->player.p_x + x] == 'E')
	{
		game->count_move++;
		if (game->exit_status == 1)
		{
			place(game, game->tex_gnd, game->player.p_x, game->player.p_y);
			place(game, obje, game->player.p_x + x, game->player.p_y + y);
			game->map[game->player.p_y][game->player.p_x] = '0';
			game->map[game->player.p_y + y][game->player.p_x + x] = '1';
			game->player.p_x += x;
			game->player.p_y += y;
			ft_exit(2);
		}
	}
	print_values(game);
}

static void	move_1_2(int key_code, t_list *game)
{
	if (key_code == KEY_S || key_code == KEY_DOWN)
	{
		game->player.p_direction = 'D';
		ft_move(game, 0, 1, game->player.player_down);
	}
	else if (key_code == KEY_W || key_code == KEY_UP)
	{
		game->player.p_direction = 'U';
		ft_move(game, 0, -1, game->player.player_up);
	}
}

int	move(int key_code, t_list *game)
{
	if (key_code == KEY_ESC)
	{
		ft_exit(0);
		return (0);
	}
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
	{
		game->player.p_direction = 'E';
		ft_move(game, 1, 0, game->player.player_right);
	}
	else if (key_code == KEY_A || key_code == KEY_LEFT)
	{
		game->player.p_direction = 'Q';
		ft_move(game, -1, 0, game->player.player_left);
	}
	else
		move_1_2(key_code, game);
	return (0);
}
//printmap(game);
