/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:41:27 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/17 01:58:11 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_2(t_list *game, int x, int y, void *obje)
{
	game->count_move++;
	game->map[game->player.p_y][game->player.p_x] = '0';
	if (game->map[game->player.p_y + y][game->player.p_x + x] == 'C')
		c_add_count(game);
	if (game->map[game->player.p_y + y][game->player.p_x + x] == 'A')
		ft_exit(6);
	place(game, game->tex_gnd, game->player.p_x, game->player.p_y);
	place(game, obje, game->player.p_x + x, game->player.p_y + y);
	game->map[game->player.p_y][game->player.p_x] = '0';
	game->map[game->player.p_y + y][game->player.p_x + x] = '1';
	game->player.p_x += x;
	game->player.p_y += y;
	game->map[game->player.p_y][game->player.p_x] = 'P';
}
