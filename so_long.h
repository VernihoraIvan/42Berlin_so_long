/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:25:23 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/06 19:00:00 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 132
# define HEIGHT 132

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

typedef struct service_data
{
	void	*img;
	int		height;
	int		width;
}	service_data;

#endif
