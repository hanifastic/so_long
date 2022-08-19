/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:49:17 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:49:25 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_list *game)
{
	if (game->count_coin == game->coin_adder)
	{
		game->exit_status = 1;
	}
}

void	print_move(t_list *game)
{
	write(1, "Moves: ", 8);
	write(1, ft_itoa(game->count_move), ft_strlen(ft_itoa(game->count_move)));
	write (1, "\n", 1);
}

void	print_coin(t_list *game)
{
	write(1, "--------\n", 9);
	write(1, "Coin: ", 6);
	write (1, ft_itoa(game->coin_adder), ft_strlen(ft_itoa(game->coin_adder)));
	write (1, "\n", 1);
}

void	print_rules(t_list *game)
{
	print_coin(game);
	print_move(game);
	game++;
}
