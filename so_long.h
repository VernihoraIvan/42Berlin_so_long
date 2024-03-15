/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:25:23 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/15 12:02:33 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 32
# define HEIGHT 32

# include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
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
	int		map_height;
	int		map_width;
	char	**map;
}	t_relement;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	t_relement	*assets;

}	t_mlx;


#endif
