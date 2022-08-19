/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:48:13 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/17 01:30:22 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

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
	void	*player_right;
	void	*player_left;
	void	*player_down;
	void	*player_up;
	int		count_player;
	int		p_anim_i;
	int		p_direction;
	void	*player_right_2;
	void	*player_left_2;
	void	*player_up_2;
	void	*player_down_2;
	void	*player_right_walk_1;
	void	*player_left_walk_1;
}	t_player;

typedef struct s_enemy
{
	char	*enemy_direction;
	void	*enemy_right_1;
	void	*enemy_right_2;
	void	*enemy_left_1;
	void	*enemy_left_2;
	int		enemy_index;
}	t_enemy;

typedef struct s_list
{
	t_player	player;
	t_enemy		enemy;
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
	int			global_fps;
	int			wall_up_size;
	int			wall_down_size;
	int			first_last;
}	t_list;

int		move(int key_code, t_list *game);
int		wordcounter(const char *p, char c);
int		ft_exit(int err);
int		ft_player_animation(t_list *game);
int		enemy_right_move(t_list *game, int x, int y);
int		enemy_left_move(t_list *game, int x, int y);
int		enemy_right_move(t_list *game, int x, int y);
int		enemy_left_move(t_list *game, int x, int y);
int		enemy_right_move_2_2(t_list *game, int x, int y);
int		enemy_right_move_2_3(t_list *game, int x, int y);
int		coin_enemy_anim_2(t_list *game, int x, int y);
int		ft_close(int err);

char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);

void	place(t_list *game, void *obje, int x, int y);
void	ft_count_check(t_list *game);
void	put_wall(t_list game);
void	c_set_count(t_list *game);
void	c_add_count(t_list *game);
void	count_error(char err);
void	ft_count_check(t_list *game);
void	open_exit(t_list *game);
void	print_rules(t_list *game);
void	ft_window_size(t_list *game);
void	ft_read_map(t_list *game, char *argv);
void	put_wall(t_list game);
void	ft_map_control(t_list *game);
void	ft_error_message(int err);
void	print_values(t_list *game);
void	ft_map_check(t_list *game, int x, int y);
void	coin_and_enemy(t_list *game);
void	print_rules(t_list *game);
void	print_coin(t_list *game);
void	print_move(t_list *game);
void	map_objects(t_list *game, int x, int y, char o);
void	map_painting_2(t_list *game);
void	ft_texture(t_list *game, char *a, \
	int x, int y);
void	ft_move_2(t_list *game, int x, int y, void *obje);
void	errors_2(int err);
void	anim_2(t_list *game, int x, int y, int status);

#endif
