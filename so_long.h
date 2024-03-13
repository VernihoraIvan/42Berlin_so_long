/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:25:23 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/13 11:04:57 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 32
# define HEIGHT 32

# include <stdio.h>
#include <stdlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct mlx_data
{
	void *mlx;
	void *win;
} mlx_data;

typedef struct t_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

#endif
