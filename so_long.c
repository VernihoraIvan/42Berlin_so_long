/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/03 18:03:29 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int on_destroy(t_mlx *data)
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
	// free(data->assets->wall.img);
	// free(data->assets->coin.img);
	// free(data->assets->player.img);
	// free(data->assets->door_closed.img);
	// free(data->assets->door_open.img);
	// free(data->assets->floor.img);
	free(data->assets->player_pos);
	free(data->assets);
	free(data->mlx);
	exit(0);
	return (0);
}


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
			if (mlx->assets->map[i][j] == 'P')
			{
				if (mlx->assets->map[i + y][j + x] == '1')
					return;
				if (mlx->assets->map[i + y][j + x] == 'C')
				{
					mlx->assets->coin_count--;
					mlx->assets->map[i + y][j + x] = '0';
				}
				if (mlx->assets->is_door_open == 0 && mlx->assets->map[i + y][j + x] == 'E')
					return;
				if (mlx->assets->is_door_open == 1 && mlx->assets->map[i + y][j + x] == 'E')
					on_destroy(mlx);
				mlx->assets->map[i + y][j + x] = 'P';
				mlx->assets->map[i][j] = '0';
				mlx->assets->moves_count++;
				return;
			}
		}
	}
}
void	check_win_condition(t_mlx *data)
{
	if (data->assets->coin_count == 0)
		data->assets->is_door_open = 1;
	else
		return;
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
	if(keycode == 65307)
		on_destroy(data);
	check_win_condition(data);
	determine_player_position(data->assets);
	render_assets(data);
	return (0);
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
				game->player_pos = malloc(sizeof(t_player_pos));
				game->player_pos->x = j;
				game->player_pos->y = i;
				return;
			}
		}
		j = 0;

	}
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
				game->coin_count++;
		}

	}

}

void	fill_map(t_mlx *data, char *mp)
{
	int	file;
	int	i;
	int	lines;

	lines = count_lines(mp);
	i = 0;
	file = open(mp, O_RDWR);
	data->assets->moves_count = 0;
	data->assets->map = malloc(sizeof(char *) * (size_t)(lines + 1));
	data->assets->map[0] = get_next_line(file);
	data->assets->map_width = ft_strlen(data->assets->map[0]);
	data->assets->map_height = lines;
	while (i < data->assets->map_height)
	{
		i++;
		data->assets->map[i] = get_next_line(file);
	}
	determine_player_position(data->assets);
	count_coins(data->assets);
	if (check_borders(data->assets->map, data->assets) == 0)
	{
		free_map(data->assets->map, i);
		write(1, "Error\nInvalid map\n", 18);
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	// if (check_map(map, data->assets) == 1)
	// 	exit(EXIT_FAILURE);
	// if (valid_path(data->assets) == 1)
	// {
	// 	free_map(data->assets);
	// 	write(1, "Error\nNo valid path\n", 20);
	// 	exit(EXIT_FAILURE);
	// }
	close(file);
}

// int	validate_map(char *map, t_mlx *mlx)
// {
// 	int		i;
// 	char	**mp;

// 	if (!check_extention(map))
// 		return (0);
// 	if (!map)
// 		return (0);
// 	i = 0;
// 	mp = (char **)malloc(sizeof(char *));
// 	if (!mp)
// 		return (0);
// 	mp[i] = (char *)malloc(sizeof(char));
// 	if (!mp[i])
// 		return (free_map(mp, i), 0);
// 	// mp[i][0] = '\0';
// 	// i = read_to_map(map, &mp);
// 	// if (i < 3)
// 	// 	return (free_map(mp, i), 0);
// 	mlx->assets = (t_relement *)malloc(sizeof(t_relement));
// 	// mlx->assets->map_height = count_lines(map);
// 	// mlx->assets->map_width = ft_strlen(mp[0]);

// 	// printf("map width: %d\n", mlx->assets->map_width);
// 	// printf("map height: %d\n", mlx->assets->map_height);
// 	// printf("mp %zu", ft_strlen(mp[0]));
// 	// if (mlx->assets->map_width < 3 )
// 	// 	return (free_map(mp, i), 0);
// 	// if (mlx->assets->map_width < 3 || !check_validity(mlx, mp))
// 	// 	return (free_map(mp, i), 0);
// 	// if (!check_borders(mlx, mp) || !check_elements(mlx, mp))
// 	// 	return (free_map(mp, i), 0);
// 	// mlx->assets->map = mp;
// 	free_map(mp, i);
// 	return (1);
// }

int	validate_map(char *map, t_mlx *mlx)
{
	// int		i;
	// char	**mp;

	if (!check_extention(map))
		return (0);
	if (!map)
		return (0);
	// i = 0;
	// mp = (char **)malloc(sizeof(char *));
	// if (!mp)
	// 	return (0);
	// mp[i] = (char *)malloc(sizeof(char));
	// if (!mp[i])
	// 	return (free_map(mp, i), 0);
	// mp[i][0] = '\0';
	// i = read_to_map(map, &mp);
	// if (i < 3)
	// 	return (free_map(mp, i), 0);
	mlx->assets = (t_relement *)malloc(sizeof(t_relement));
	mlx->assets->is_door_open = 0;
	// mlx->assets->map_height = count_lines(map);
	// mlx->assets->map_width = ft_strlen(mp[0]);

	// printf("map width: %d\n", mlx->assets->map_width);
	// printf("map height: %d\n", mlx->assets->map_height);
	// printf("mp %zu", ft_strlen(mp[0]));
	// if (mlx->assets->map_width < 3 )
	// 	return (free_map(mp, i), 0);
	// if (mlx->assets->map_width < 3 || !check_validity(mlx, mp))
	// 	return (free_map(mp, i), 0);
	// if (!check_borders(mlx, mp) || !check_elements(mlx, mp))
	// 	return (free_map(mp, i), 0);
	// mlx->assets->map = mp;
	// free_map(mp, i);
	return (1);
}
//////////////////////////////////////////////////////////////////
int main(int ac, char **av)
{
	t_mlx data;
	// t_img img_data;

	data.mlx = mlx_init();
	if (ac != 2)
		return (0);
	if (!data.mlx)
		return (0);
	if (!validate_map(av[1], &data))
		return (0);
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "so_long");
	if (!data.win)
		return (free(data.mlx), 1);

	load_img(&data);
	fill_map(&data, av[1]);
	render_assets(&data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_keypress, &data);
	// Register destroy hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
