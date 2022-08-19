/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:38:15 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/17 02:33:22 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int err)
{
	err++;
	write(1, "Program sonlandırıldı\n", 25);
	exit(0);
	return (0);
}

int	ft_exit(int err)
{
	if (err == 0)
		exit(0);
	else if (err == 1)
	{
		write(1, "ERROR\n", 6);
		write(1, "Haritada yabancı cisim\n", 24);
	}
	else if (err == 2)
	{
		write(1, "\n", 1);
		write(1, "************\n", 13);
		write(1, "* YOU WON! *\n", 13);
		write(1, "************\n", 13);
		write (1, "\n", 1);
	}
	else
		errors_2(err);
	exit (0);
	return (0);
}

void	ft_error_message(int err)
{
	if (err == 1)
		write(1, "Haritada yabancı cisim\n", 24);
	else if (err == 2)
	{
		write(1, "\n", 1);
		write(1, "\n************\n", 13);
		write(1, "* YOU WON! *\n", 12);
		write(1, "************\n", 12);
		write (1, "\n", 1);
	}
	if (err == 3)
		write(1, "Lütfen harita giriniz!\n", 24);
	else if (err == 4)
		write(1, "Harita uygun değil!\n", 21);
	else if (err == 5)
		write(1, "Harita duvar ile çevrelenmemiş!\n", 33);
}

void	count_error(char err)
{
	write(1, "ERROR\n", 6);
	if (err == 'E')
		write(1, "Çıkış bulunamadı!\n", 23);
	else if (err == '+')
		write(1, "Çok fazla oyuncu mevcut!\n", 26);
	else if (err == '-')
		write(1, "Oyuncu bulunamadı!\n", 19);
	else if (err == 'C')
	{
		write(1, "Coin bulunamadı!\n", 17);
		ft_exit(0);
	}
	else if (err == 'R')
		write(1, "Çok fazla çıkış mevcut!\n", 28);
	ft_exit(0);
}

void	ft_count_check(t_list *game)
{
	if (game->count_exit < 1)
		count_error('E');
	else if (game->count_exit > 1)
		count_error('R');
	else if (game->player.count_player > 1)
		count_error('+');
	else if (game->player.count_player < 1)
		count_error('-');
	else if (game->count_coin < 1)
		count_error('C');
	else if (game->enemy.enemy_index < 1)
		count_error('A');
}
