/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:32:00 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:22:50 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_assigment(t_list *game, int x, int y)
{
	game->p.count_player++;
	place(game, game->p.p_right, x, y);
	game->p.p_x = x;
	game->p.p_y = y;
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
	else if (o == 'C')
	{
		game->count_coin++;
		place(game, game->tex_coin, x, y);
	}
	else
		ft_exit(1);
}
