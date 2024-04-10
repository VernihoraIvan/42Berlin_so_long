/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:25:23 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/10 16:09:30 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1000
# define WIDTH 56
# define HEIGHT 56

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"

typedef struct t_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct t_player_pos
{
	int		x;
	int		y;
}	t_player_pos;

typedef struct t_relement
{
	t_img			wall;
	t_img			coin;
	t_img			player;
	t_img			door_open;
	t_img			door_closed;
	t_img			floor;
	int				moves_count;
	int				coins;
	int				count_coins;
	int				map_height;
	int				map_width;
	int				is_door_open;
	int				e_r;
	int				e_c;
	char			**map;
	t_player_pos	*player_pos;

}	t_relement;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	t_relement	*assets;
}	t_mlx;

void	fill_map(t_mlx *data, char *mp);
int		count_lines(char *map);
int		check_extention(char *map);
void	free_map(char **map, int i);
t_img	add_img(t_mlx data, char *path);
int		load_img(t_mlx *mlx);
void	mlx_render_img(t_mlx *mlx, t_img img, int x, int y);
int		render_assets(t_mlx *mlx);
int		on_keypress(int keycode, t_mlx *data);
void	determine_player_position(t_relement *game);
void	run_player(t_mlx *mlx, int x, int y);
void	check_win_condition(t_mlx *data);
void	count_coins(t_relement *game);
int		on_destroy(t_mlx *data);
int		check_borders(char **map, t_relement *assets);
int		check_elements(t_mlx *mlx, char **map, int c, int e);
int		is_valid_path(t_mlx *data);
void	free_passed(int **passed, t_relement *game);
void	print_error(int type);
int		is_open(t_mlx *mlx);
void	fail(t_mlx *data);
int		check_map_len(char **map, t_relement *assets);
int		is_move_valid(t_relement *game, int **passed, int row, int col);
#endif
