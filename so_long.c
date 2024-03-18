/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/18 18:37:49 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// int on_destroy(t_mlx *data)
// {
// 	mlx_destroy_window(data->mlx, data->win);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	exit(0);
// 	return (0);
// }

// int on_keypress(int keysym, t_mlx *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }





// t_img	put_img(t_mlx mlx, char *path)
// {
// 	t_img	ig;

// 	ig.img = mlx_xpm_file_to_image(mlx.mlx, path, &ig.width, &ig.height);
// 	return (ig);
// }

// // t_img render_map(char* file_path)
// // {
// // 	// Read the content of the file "map.ber" and process it
// // 	// ...

// // 	// Return the rendered image
// // 	t_img render_img;
// // 	// ...

// // 	return render_img;
// // }


// int	read_to_map(char *map, char ***mp)
// {
// 	int		fd;
// 	char	tmp;
// 	int		i;

// 	fd = ((i = 0), open(map, O_RDONLY));
// 	if (fd == -1)
// 		return (0);
// 	while (read(fd, &tmp, 1) > 0)
// 	{
// 		if (tmp == '\n')
// 		{
// 			i++;
// 			*mp = (char **)ft_realloc(*mp, sizeof(char *) * (i + 1));
// 			if (!*mp)
// 				return (0);
// 			(*mp)[i] = (char *)malloc(sizeof(char));
// 			if (!(*mp)[i])
// 				return (0);
// 			(*mp)[i][0] = '\0';
// 		}
// 		else
// 			(*mp)[i] = ft_addchar((*mp)[i], tmp);
// 	}
// 	i++;
// 	return ((close(fd), i));
// }

// int	validate_map(char *map, t_mlx *mlx)
// {
// 	int		i, j;
// 	char	**mp;

// 	// if (!check_extention(map))
// 	// 	return (0);
// 	i = 0;
// 	j = 0;
// 	mp = (char **)malloc(sizeof(char *) * ft_strlen(mp[i]));
// 	if (!mp)
// 		return (0);
// 	mp[i][j] = (char *)malloc(sizeof(char) * ft_strlen(mp[i]));
// 	// if (!mp[i])
// 	// 	return (free_map(mp, i), 0);
// 	mp[i][0] = '\0';
// 	i = read_to_map(map, &mp);
// 	// if (i < 3)
// 	// 	return (free_map(mp, i), 0);
// 	mlx->assets = (t_relement *)malloc(sizeof(t_relement));
// 	mlx->assets->map_height = i;
// 	mlx->assets->map_width = ft_strlen(mp[0]);
// 	// if (mlx->assets->map_width < 3 || !check_validity(mlx, mp))
// 	// 	return (free_map(mp, i), 0);
// 	// if (!check_borders(mlx, mp) || !check_elements(mlx, mp))
// 	// 	return (free_map(mp, i), 0);
// 	mlx->assets->map = mp;
// 	return (1);
// }





void	fill_map(t_relement *game, char *mp)
{
	int	file;
	int	i;
	int	lines;

	lines = count_lines(mp);
	i = 0;
	file = open(mp, O_RDWR);
	game->moves_count = 0;
	// game->player_position = 0;
	printf("map height: %d\n", game->map_height);

	game->map = malloc(sizeof(char *) * (size_t)(lines + 1));
	game->map[0] = get_next_line(file);
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = lines;
	printf("file: %d\n", file);
	while (i < game->map_height)
	{
		i++;
		game->map[i] = get_next_line(file);
	}

	// if (check_map(map, game) == 1)
	// 	exit(EXIT_FAILURE);
	// if (valid_path(game) == 1)
	// {
	// 	free_map(game);
	// 	write(1, "Error\nNo valid path\n", 20);
	// 	exit(EXIT_FAILURE);
	// }
	close(file);
}






//////////////////////////////////////////////////////////////////////


int	validate_map(char *map, t_mlx *mlx)
{
	int		i;
	char	**mp;

	if (!check_extention(map))
		return (0);
	if (!map)
		return (0);
	i = 0;
	mp = (char **)malloc(sizeof(char *));
	if (!mp)
		return (0);
	mp[i] = (char *)malloc(sizeof(char));
	if (!mp[i])
		return (free_map(mp, i), 0);
	// mp[i][0] = '\0';
	// i = read_to_map(map, &mp);
	// if (i < 3)
	// 	return (free_map(mp, i), 0);
	mlx->assets = (t_relement *)malloc(sizeof(t_relement));
	// mlx->assets->map_height = count_lines(map);
	// mlx->assets->map_width = ft_strlen(mp[0]);

	// printf("map width: %d\n", mlx->assets->map_width);
	// printf("map height: %d\n", mlx->assets->map_height);
	// printf("mp %zu", ft_strlen(mp[0]));
	// if (mlx->assets->map_width < 3 || !check_validity(mlx, mp))
	// 	return (free_map(mp, i), 0);
	// if (!check_borders(mlx, mp) || !check_elements(mlx, mp))
	// 	return (free_map(mp, i), 0);
	// mlx->assets->map = mp;
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
	// img_data.height = HEIGHT;
	// img_data.width = WIDTH;
	load_img(&data);

	// int lines = count_lines(av[1]);
	// data.assets->map_height = count_lines(av[1]);
	fill_map(data.assets, av[1]);

	printf("map width: %d\n", data.assets->map_width);
	printf("map height: %d\n", data.assets->map_height);
	render_assets(&data);




	// Register key release hook
	// mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	// mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
