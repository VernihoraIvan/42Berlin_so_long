/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:36:00 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/21 19:10:57 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_img add_img(t_mlx data, char *path)
{
	t_img render_img;
	render_img.width = WIDTH;
	render_img.height = HEIGHT;

	render_img.img = mlx_xpm_file_to_image(data.mlx, path, &render_img.width, &render_img.height);
	return (render_img);
}

int	load_img(t_mlx *mlx)
{
	mlx->assets->coin_count = 0;
	mlx->assets->move_count = 0;
	mlx->assets->floor = add_img(*mlx, "assets/bg.xpm");
	mlx->assets->wall = add_img(*mlx, "assets/wall.xpm");
	mlx->assets->coin = add_img(*mlx, "assets/coin.xpm");
	mlx->assets->player = add_img(*mlx, "assets/player.xpm");
	mlx->assets->door_open = add_img(*mlx, "assets/door_open.xpm");
	mlx->assets->door_closed = add_img(*mlx, "assets/door_closed.xpm");

	return (0);
}

void	mlx_render_img(t_mlx *mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, x, y);
}

int	render_assets(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	// printf("map width: %d\n", mlx->assets->map_width);
	// printf("map height: %d\n", mlx->assets->map_height);
	while (++i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			// printf("map: %c\n", mlx->assets->map[i][j]);
			if (mlx->assets->map[i][j] == '1')
				mlx_render_img(mlx, mlx->assets->wall, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == 'C')
				mlx_render_img(mlx, mlx->assets->coin, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == 'P')
				mlx_render_img(mlx, mlx->assets->player, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == '0')
				mlx_render_img(mlx, mlx->assets->floor, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == 'E')
			{
				if(mlx->assets->is_door_open == 0)
				{
					mlx_render_img(mlx, mlx->assets->door_closed, j * WIDTH, i * HEIGHT);
					printf("door closed\n");
				}
				else if(mlx->assets->is_door_open == 1)
				{
					// mlx_destroy_image(mlx->mlx, mlx->assets->door_closed.img);
					mlx_render_img(mlx, mlx->assets->door_open, j * WIDTH, i * HEIGHT);
					printf("door open\n");
				}
			}
			j++;
		}
	}
	return (0);
}
