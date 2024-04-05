/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:06:32 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/05 13:46:29 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_all_elements_present(t_mlx *mlx, char **map)
{
	int i = 0;
	int j = 0;

	while(i < mlx->assets->map_height)
	{
		j = 0;
		while(j < mlx->assets->map_width)
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
			{
				printf("Error\nNot all elements are present in the map\n");
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
	int i = 0;
	int j = 0;
	int c = 0;

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
		printf("Error\nThere is no way out\n");
		return (0);
	}
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
	printf("player pos x: %d y: %d\n", mlx->assets->player_pos->x, mlx->assets->player_pos->y);
	if (c < 1 || e < 1 || p != 1 || is_all_elements_present(mlx, map) == 0 || is_way_out(mlx, map) == 0)
		return (0);
	return (1);
}
