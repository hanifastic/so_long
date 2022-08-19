/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:45:37 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:48:43 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	definition(t_list game, int i, int x, int y)
{
	if (i == 1)
		mlx_put_image_to_window(game.mlx, game.win, \
			game.tex_wall, 32 * x, 32 * y);
}

void	place(t_list *game, void *obje, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->tex_gnd, 32 * x, 32 * y);
	mlx_put_image_to_window(game->mlx, game->win, obje, 32 * x, 32 * y);
}

void	ft_map_painting(t_list *game, int x, int y)
{
	map_painting_2(game);
	while (++y < game->max_y)
	{
		x = -1;
		while (++y < game->max_y)
		{
			x = -1;
			while (++x < game->max_x)
			{
				if (game->map[y][x] == '1')
					definition(*game, 1, x, y);
				else if (game->map[y][x] == '0')
					mlx_put_image_to_window(game->mlx, game->win, \
						game->tex_gnd, 32 * x, 32 * y);
				else
					map_objects(game, x, y, game->map[y][x]);
			}
		}
	}
	ft_count_check(game);
}

int	main(int argc, char **argv)
{
	t_list	game;

	c_set_count(&game);
	if (argc == 2)
	{
		game.mlx = mlx_init();
		ft_read_map(&game, argv[1]);
		ft_window_size(&game);
		ft_map_painting(&game, -1, -2);
		mlx_hook(game.win, 2, 1L << 0, move, &game);
		mlx_string_put(game.mlx, game.win, 0, 10, 0xFFFF00, "Coin:  0");
		mlx_string_put(game.mlx, game.win, 0, 20, 0xFFFF00, "Moves: 0");
		mlx_loop_hook(game.mlx, ft_player_animation, &game);
		mlx_hook(game.win, 17, (0L), ft_close, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_exit(3);
	return (0);
}
//xpm dosyalarımız 32x32 olduğu için img'yi ekrana koyduğumuz kısım. 26
//y dikey x yatay
//57 oyunun sıfırlandıgı alan
//60 grafik işleme ile gerekenleri mlx'e atıyor.
//61 .ber dosyasının içeriğini okur
//62 üst-alt ve sağ-sol ölçülerine göre oyunun boyunu ayarlar
//63 ekrana img'leri basan fonksiyon
//64 basılan tuşları kontrol eden MLX_HOOK
//67 animasyon için ayrı bir döngü açan fonksyion
//68 kırmızı çarpıya basınca oyunu kapatmak için gerekli MLX_HOOK
//70 main'in sonsuz döngüde çalışmasını sağlayan fonksiyon
