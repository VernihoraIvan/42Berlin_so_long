/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/09 20:01:41 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
					(!is_open(mlx) && mlx->assets->map[i + y][j + x] == 'E'))
					return ;
				if (mlx->assets->map[i + y][j + x] == 'C' \
					&& mlx->assets->coins-- != -1)
					mlx->assets->map[i + y][j + x] = '0';
				if (is_open(mlx) && mlx->assets->map[i + y][j + x] == 'E')
					on_destroy(mlx);
				mlx->assets->map[i + y][j + x] = 'P';
				mlx->assets->map[i][j] = '0';
				return ;
			}
		}
	}
}

int	on_keypress(int keycode, t_mlx *data)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		if (keycode == 119)
			run_player(data, 0, -1);
		else if (keycode == 97)
			run_player(data, -1, 0);
		else if (keycode == 115)
			run_player(data, 0, 1);
		else if (keycode == 100)
			run_player(data, 1, 0);
	}
	if (keycode == 65307)
		on_destroy(data);
	ft_printf("Moves count: %d\n", data->assets->moves_count);
	check_win_condition(data);
	determine_player_position(data->assets);
	render_assets(data);
	return (0);
}

void	fill_map(t_mlx *data, char *mp)
{
	int	file;
	int	i;
	int	lines;

	lines = count_lines(mp);
	i = 0;
	file = open(mp, O_RDONLY);
	data->assets->map = malloc(sizeof(char *) * (size_t)(lines + 1));
	data->assets->map[0] = get_next_line(file);
	if (!data->assets->map[0])
		fail(data);
	data->assets->map_width = ft_strlen(data->assets->map[0]);
	data->assets->map_height = lines;
	while (i++ < data->assets->map_height)
		data->assets->map[i] = get_next_line(file);
	if (!data->assets->map || !check_borders(data->assets->map, data->assets))
	{
		print_error(6);
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	if (!check_elements(data, data->assets->map, 0, 0) || !is_valid_path(data) \
		|| !check_borders(data->assets->map, data->assets))
		print_error(4);
	close(file);
}

int	validate_map(char *map, t_mlx *mlx)
{
	if (!check_extention(map))
		return (0);
	if (!map)
		return (0);
	mlx->assets = (t_relement *)malloc(sizeof(t_relement));
	if (!mlx->assets)
		return (print_error(9), 0);
	mlx->assets->is_door_open = 0;
	mlx->assets->player_pos = NULL;
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	data;

	if (ac == 2)
	{
		if (!validate_map(av[1], &data))
			return (0);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (0);
		data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, \
			SCREEN_HEIGHT, "so_long");
		if (!data.win)
			return (free(data.mlx), 1);
		load_img(&data);
		fill_map(&data, av[1]);
		render_assets(&data);
		mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_keypress, &data);
		mlx_hook(data.win, DestroyNotify, StructureNotifyMask, \
			on_destroy, &data);
		mlx_loop(data.mlx);
	}
	else
		print_error(11);
	return (0);
}
