/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:08:05 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:29:56 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(int err)
{
	if (err == 1 | err == 3 | err == 4 | err == 5 | err == 7)
		write(1, "ERROR\n", 6);
	if (err == 1)
		write(1, "Haritada yabancı cisim\n", 24);
	else if (err == 2)
	{
		write(1, "\n", 1);
		write(1, "************\n", 13);
		write(1, "* YOU WON! *\n", 13);
		write(1, "************\n", 13);
		write (1, "\n", 1);
	}
	else if (err == 3)
		write(1, "Lütfen harita giriniz!\n", 24);
	else if (err == 4)
		write(1, "Harita uygun değil!\n", 21);
	else if (err == 5)
		write(1, "Harita duvar ile çevrelenmemiş!\n", 33);
	else if (err == 7)
		write(1, "Harita hatalı\n", 15);
	exit(0);
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
		write(1, "Coin bulunamadı!\n", 17);
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
	else if (game->p.count_player > 1)
		count_error('+');
	else if (game->p.count_player < 1)
		count_error('-');
	else if (game->count_coin < 1)
		count_error('C');
}
