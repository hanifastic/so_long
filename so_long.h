/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:33:12 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:22:50 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_UP 126

typedef struct s_player
{
	int		p_x;
	int		p_y;
	void	*p_right;
	void	*p_left;
	void	*p_down;
	void	*p_up;
	int		count_player;
	int		p_direction;
	void	*p_right_2;
	void	*p_left_2;
	void	*p_up_2;
	void	*p_down_2;
	void	*p_r_w_1;
	void	*p_l_w_1;
}	t_player;

typedef struct s_list
{
	t_player	p;
	int			x;
	int			y;
	void		*win;
	void		*mlx;
	char		**map;
	int			max_x;
	int			max_y;
	void		*win_put_wall;
	void		*tex_wall;
	void		*tex_gnd;
	void		*tex_coin;
	void		*tex_exit_close;
	void		*tex_exit_open;
	int			count_coin;
	int			count_exit;
	int			count_wall;
	int			coin_adder;
	int			exit_x;
	int			exit_y;
	int			exit_status;
	void		*tex_exit_open_2;
	int			count_move;
	void		*tex_coin_2;
	int			first_last;
	int			wall_up_size;
	int			wall_down_size;
	int			wall_i;
}t_list;

int		move(int key_code, t_list *game);
int		wordcounter(const char *p, char c);
int		ft_exit(int err);

char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);

void	ft_texture(t_list *game);
void	place(t_list *game, void *obje, int x, int y);
void	ft_count_check(t_list *game);
void	put_wall(t_list game);
void	c_set_count(t_list *game);
void	c_add_count(t_list *game);
void	count_error(char err);
void	ft_count_check(t_list *game);
void	open_exit(t_list *game);
void	ft_window_size(t_list *game);
void	ft_read_map(t_list *game, char *argv);
void	put_wall(t_list game);
void	ft_map_control(t_list *game);
void	ft_error_message(int err);
void	print_values(t_list *game);
void	ft_map_check(t_list *game, int x, int y);
void	coin_and_enemy(t_list *game);
void	print_coin(t_list *game);
void	print_move(t_list *game);
void	map_objects(t_list *game, int x, int y, char o);
void	map_painting_2(t_list *game);

#endif
