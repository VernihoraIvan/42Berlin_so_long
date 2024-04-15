/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:06:32 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/15 11:29:20 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win_condition(t_mlx *data)
{
	if (data->assets->coins == 0)
		data->assets->is_door_open = 1;
	else
		return ;
}

int	is_p(t_mlx *mlx, char **map)
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
				print_error(3);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_req(char **map)
{
	size_t	first_line_row;
	size_t	i;
	size_t	len;

	first_line_row = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if ((len != first_line_row && map[i + 1])
			|| (len != first_line_row && !map[i + 1]))
			return (print_error(1), 0);
		map[i][first_line_row - 1] = 0;
		i++;
	}
	map[0][first_line_row - 1] = 0;
	return (1);
}

int	check_elements(t_mlx *mlx, char **map, int c, int e)
{
	int	i;
	int	j;
	int	p;

	i = ((p = 0), -1);
	while (++i < mlx->assets->map_height)
	{
		j = -1;
		while (++j < mlx->assets->map_width)
		{
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'P')
				p++;
		}
	}
	if (c > 1 && e == 1 && p == 1 && is_p(mlx, map) != 0 && is_req(map))
		return (1);
	if (c < 1 || e != 1 || p != 1)
		print_error (4);
	else
		print_error(6);
	return (on_destroy(mlx), 0);
}

void	print_error(int type)
{
	ft_printf("Error\n");
	if (type == 1)
		ft_printf("The map must be rectangular.\n");
	else if (type == 2)
		ft_printf("The map must be closed/surrounded by walls.\n");
	else if (type == 3)
		ft_printf("The map must contain only valid characters.\n");
	else if (type == 4)
		ft_printf("The map must contain - 1 E, 1 P and some C.\n");
	else if (type == 5)
		ft_printf("The map is too big.\n");
	else if (type == 6)
		ft_printf("The contentent of the map is incorrect.\n");
	else if (type == 7)
		ft_printf("Wrong map format\n");
	else if (type == 8)
		ft_printf("The map must have a valid path.\n");
	else if (type == 9)
		ft_printf("Malloc error.\n");
	else if (type == 10)
		ft_printf("Empty file\n");
	else if (type == 11)
		ft_printf("Wrong path to the map\n");
}
