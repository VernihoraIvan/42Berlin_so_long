/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:25:23 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/20 17:23:49 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1000
# define WIDTH 56
# define HEIGHT 56


# include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"








typedef struct t_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct t_relement
{
	t_img	wall;
	t_img	coin;
	t_img	player;
	t_img	door_open;
	t_img	door_closed;
	int		moves_count;
	int		coin_count;
	int		move_count;
	int		map_height;
	int		map_width;
	int		test;
	char	**map;
	int		player_x;
	int		player_y;
}	t_relement;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	int			test;
	t_relement	*assets;
}	t_mlx;

int		count_lines(char *map);
int		check_extention(char *map);
void	free_map(char **map, int i);
t_img	add_img(t_mlx data, char *path);
int		load_img(t_mlx *mlx);
void	mlx_render_img(t_mlx *mlx, t_img img, int x, int y);
int		render_assets(t_mlx *mlx);
int		on_keypress(int keycode, t_mlx *data);




#endif
