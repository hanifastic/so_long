/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:38:00 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:40:57 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors_2(int err)
{
	if (err != 6)
		write(1, "ERROR\n", 6);
	if (err == 3)
		write(1, "Lütfen harita giriniz!\n", 24);
	else if (err == 4)
		write(1, "Harita uygun değil!\n", 21);
	else if (err == 5)
		write(1, "Harita duvar ile çevrelenmemiş!\n", 33);
	else if (err == 6)
	{
		write(1, "\n", 1);
		write(1, "*************\n", 14);
		write(1, "* YOU DIED! *\n", 14);
		write(1, "*************\n", 14);
		write (1, "\n", 1);
	}
	else if (err == 7)
		write(1, "Harita hatalı\n", 15);
}
