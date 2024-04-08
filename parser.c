/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:06:32 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/08 15:35:00 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_present(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' \
				&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
			{
				write(1, "Error\nWrong element in the map\n", 31);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_way_out(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	j = mlx->assets->player_pos->x;
	i = mlx->assets->player_pos->y;
	if (map[i][j + 1] == '1')
		c++;
	if (map[i][j - 1] == '1')
		c++;
	if (map[i + 1][j] == '1')
		c++;
	if (map[i - 1][j] == '1')
		c++;
	if (c == 4)
	{
		write(1, "Error\nThere is no way out\n", 26);
		return (0);
	}
	if (is_present(mlx, map) == 0)
		return (0);
	return (1);
}

int	check_elements(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = ((c = 0, e = 0, p = 0), 0);
	while (i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (c < 1 || e < 1 || p != 1 || is_way_out(mlx, map) == 0)
		return (0);
	return (1);
}
