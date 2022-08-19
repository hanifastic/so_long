/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:22:36 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:38:00 by hsisman          ###   ########.tr       */
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
	char	*a;

	write(1, "Moves: ", 8);
	a = ft_itoa(game->count_move);
	write(1, a, ft_strlen(a));
	write (1, "\n", 1);
	free(a);
}
