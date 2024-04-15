/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/15 11:28:12 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_len(char **map, t_relement *assets)
{
	int	len;
	int	height;

	len = ft_strlen(map[0]) - 1;
	height = assets->map_height;
	if (len > SCREEN_WIDTH / WIDTH || height > SCREEN_HEIGHT / HEIGHT)
		return (print_error(5), 0);
	return (1);
}

int	on_keypress(int keycode, t_mlx *data)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100 \
		|| keycode == 65362 || keycode == 65361 || keycode == 65364 \
		|| keycode == 65363)
	{
		if (keycode == 119 || keycode == 65362)
			run_player(data, 0, -1);
		else if (keycode == 97 || keycode == 65361)
			run_player(data, -1, 0);
		else if (keycode == 115 || keycode == 65364)
			run_player(data, 0, 1);
		else if (keycode == 100 || keycode == 65363)
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
