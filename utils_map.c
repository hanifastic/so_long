/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:23:44 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:24:02 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_list *game)
{
	game->max_x = ft_strlen(game->map[0]);
	game->win = mlx_new_window(game->mlx, \
	32 * game->max_x, 32 * game->max_y, "so_long");
}

void	ft_read_map(t_list *game, char *argv)
{
	int		fd;
	char	*line;
	char	*map;

	map = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit(7);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	game->map = ft_split(map, '\n');
	game->max_y = wordcounter(map, '\n');
	free(map);
}

void	put_wall(t_list game)
{
	game.win_put_wall = mlx_xpm_file_to_image((game).mlx, \
	"./img/wall_3.xpm", &(game).x, &game.y);
}

void	ft_map_check_2(t_list *game)
{
	if (game->first_last != game->max_y)
		ft_exit(4);
	if (game->wall_up_size != game->wall_down_size \
	|| game->wall_down_size != game->max_x \
	|| game->wall_up_size != game->max_x)
		ft_exit(4);
}

void	ft_map_check(t_list *game, int x, int y)
{
	x = -1;
	y = -1;
	while (++y < game->max_y)
	{
		x = -1;
		while (game->map[y][++x] != '\0')
		{
			if (game->map[y][x] == '1')
			{
				if (y == 0 && game->map[0][x] == '1')
					game->wall_up_size++;
				if (y == game->max_y - 1 \
				&& game->map[game->max_y - 1][x] == '1')
					game->wall_down_size++;
				if (game->map[y][0] == '1' \
				&& game->map[y][game->max_x - 1] == '1' && (x == 0))
					game->first_last++;
			}
		}
		if (x != game->max_x)
			ft_exit(4);
	}
	ft_map_check_2(game);
}
