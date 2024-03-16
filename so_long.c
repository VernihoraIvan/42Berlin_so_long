/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/16 17:35:15 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

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



// void	*ft_realloc(void *ptr, size_t size)
// {
// 	void	*new;

// 	new = malloc(size);
// 	if (new == NULL)
// 		return (NULL);
// 	if (ptr)
// 	{
// 		ft_memcpy(new, ptr, size);
// 		free(ptr);
// 	}
// 	return (new);
// }

// char	*ft_addchar(char *str, char c)
// {
// 	char	*new;
// 	int		i;

// 	i = 0;
// 	if (str)
// 		while (str[i])
// 			i++;
// 	new = malloc(sizeof(char) * (i + 2));
// 	i = 0;
// 	if (str)
// 	{
// 		while (str[i])
// 		{
// 			new[i] = str[i];
// 			i++;
// 		}
// 	}
// 	new[i] = c;
// 	new[i + 1] = '\0';
// 	free(str);
// 	return (new);
// }

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

void	mlx_render_img(t_mlx *mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, x, y);
}

int	render_assets(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	printf("map width: %d\n", mlx->assets->map_width);
	printf("map height: %d\n", mlx->assets->map_height);
	while (++i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			printf("map: %c\n", mlx->assets->map[i][j]);
			if (mlx->assets->map[i][j] == '1')
				mlx_render_img(mlx, mlx->assets->wall, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'C')
				mlx_render_img(mlx, mlx->assets->coin, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'P')
				mlx_render_img(mlx, mlx->assets->player, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'O')
				mlx_render_img(mlx, mlx->assets->door_open, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'E')
				mlx_render_img(mlx, mlx->assets->door_closed, j * 56, i * 56);
			j++;
		}
	}
	return (0);
}

void	fill_map(t_relement *game, int lines, char *map)
{
	int	file;
	int	i;

	i = 0;
	file = open(map, O_RDWR);
	// game->moves = 0;
	// game->player_position = 0;
	game->map = malloc(sizeof(char *) * (size_t)(lines + 1));
	game->map[0] = get_next_line(file);
	while (i < lines)
	{
		i++;
		game->map[i] = get_next_line(file);
		printf("map: %s\n", game->map[i]);
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

int	count_lines(char *map)
{
	int		file;
	int		lines;
	// char	*line;

	lines = 0;
	file = open(map, O_RDONLY);
	while (get_next_line(file))
		lines++;
	close(file);
	return (lines);
}

t_img add_img(t_mlx data, char *path)
{
	t_img render_img;
	render_img.width = 20;
	render_img.height = 20;

	render_img.img = mlx_xpm_file_to_image(data.mlx, path, &render_img.width, &render_img.height);
	return (render_img);
}

int	load_img(t_mlx *mlx)
{
	mlx->assets->coin_count = 0;
	mlx->assets->move_count = 0;
	mlx->assets->wall = add_img(*mlx, "assets/wall.xpm");
	mlx->assets->coin = add_img(*mlx, "assets/coin.xpm");
	mlx->assets->player = add_img(*mlx, "assets/player.xpm");
	mlx->assets->door_open = add_img(*mlx, "assets/door_open.xpm");
	mlx->assets->door_closed = add_img(*mlx, "assets/door_closed.xpm");
	return (0);
}


//////////////////////////////////////////////////////////////////////
int	validate_map(char *map, t_mlx *mlx)
{
	int		i;
	char	**mp;

	// if (!check_extention(map))
	// 	return (0);
	if (!map)
		return (0);
	i = 0;
	mp = (char **)malloc(sizeof(char *));
	if (!mp)
		return (0);
	mp[i] = (char *)malloc(sizeof(char));
	// if (!mp[i])
	// 	return (free_map(mp, i), 0);
	mp[i][0] = '\0';
	// i = read_to_map(map, &mp);
	// if (i < 3)
	// 	return (free_map(mp, i), 0);
	mlx->assets = (t_relement *)malloc(sizeof(t_relement));
	mlx->assets->map_height = 10;
	mlx->assets->map_width = 36;
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
	if (ac == 12 && av == NULL)
		return (1);
	if (!data.mlx)
		return (1);
	if (!validate_map(av[1], &data))
		return (0);
	data.win = mlx_new_window(data.mlx, 1600, 1600, "so_long");
	if (!data.win)
		return (free(data.mlx), 1);
	// img_data.height = HEIGHT;
	// img_data.width = WIDTH;
	load_img(&data);

	int lines = count_lines(av[1]);
	data.assets->map_height = lines;
	printf("lines: %d\n", data.assets->map_height);
	fill_map(data.assets, lines, av[1]);

	render_assets(&data);

	// printf("lines: %d\n", lines);

	// printf("height: %d\n", data.assets->map_height);
	// printf("width: %d\n", data.assets->map_width);
	// printf("num: %s\n", *data.assets->map);




	// Register key release hook
	// mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	// mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
