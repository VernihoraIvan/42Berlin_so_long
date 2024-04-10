/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:29:07 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/10 14:45:25 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_mlx *data)
{
	mlx_destroy_image(data->mlx, data->assets->player.img);
	mlx_destroy_image(data->mlx, data->assets->coin.img);
	mlx_destroy_image(data->mlx, data->assets->wall.img);
	mlx_destroy_image(data->mlx, data->assets->door_closed.img);
	mlx_destroy_image(data->mlx, data->assets->door_open.img);
	mlx_destroy_image(data->mlx, data->assets->floor.img);
	mlx_destroy_window(data->mlx, data->win);
	while (data->assets->map_height--)
		free(data->assets->map[data->assets->map_height]);
	mlx_destroy_display(data->mlx);
	free(data->assets->map);
	free(data->assets->player_pos);
	free(data->assets);
	free(data->mlx);
	exit(0);
	return (0);
}

void	count_coins(t_relement *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->map_height)
	{
		j = 0;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'C')
				game->coins++;
		}
	}
}

void	determine_player_position(t_relement *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < game->map_height)
	{
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				if (game->player_pos)
					free(game->player_pos);
				game->player_pos = malloc(sizeof(t_player_pos));
				if (!game->player_pos)
					return (print_error(9));
				if (!game->player_pos)
					return ;
				game->player_pos->x = j;
				game->player_pos->y = i;
				return ;
			}
		}
		j = 0;
	}
}

int	is_open(t_mlx *mlx)
{
	if (mlx->assets->is_door_open == 0)
		return (0);
	return (1);
}

void	fail(t_mlx *data)
{
	data->assets->map_width = 0;
	data->assets->map_height = 0;
	print_error(10);
	on_destroy(data);
	exit(EXIT_FAILURE);
}
