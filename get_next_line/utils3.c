/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:49:30 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/10 16:51:42 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "../src/so_long.h"

void	run_player(t_mlx *mlx, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->assets->map_height)
	{
		j = -1;
		while (++j < mlx->assets->map_width)
		{
			if (mlx->assets->map[i][j] == 'P' && mlx->assets->moves_count++)
			{
				if ((mlx->assets->map[i + y][j + x] == '1') || \
					(!is_open(mlx) && mlx->assets->map[i + y][j + x] == 'E' && \
						mlx->assets->map[i + (y * 2)][j + (2 * x)] == '1'))
					return ;
				if (mlx->assets->map[i + y][j + x] == 'C' \
					&& mlx->assets->coins-- != -1)
					mlx->assets->map[i + y][j + x] = '0';
				if (is_open(mlx) && mlx->assets->map[i + y][j + x] == 'E')
					on_destroy(mlx);
				if (!is_open(mlx) && mlx->assets->map[i + y][j + x] == 'E' \
					&& mlx->assets->map[i + (y * 2)][j + (2 * x)] != '1')
				{
					if (mlx->assets->map[i + (y * 2)][j + (2 * x)] == 'C')
						mlx->assets->coins--;
					mlx->assets->map[i + 2 * y][j + 2 * x] = 'P';
					mlx->assets->map[i][j] = '0';
					return ;
				}
				mlx->assets->map[i + y][j + x] = 'P';
				mlx->assets->map[i][j] = '0';
				return ;
			}
		}
	}
}
