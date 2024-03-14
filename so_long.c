/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/14 16:44:14 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

int on_destroy(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_mlx *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

t_img add_img(t_mlx data, char *path)
{
	t_img render_img;

	render_img.img = mlx_xpm_file_to_image(data.mlx, path, &render_img.width, &render_img.height);
	return (render_img);
}

void	mlx_render_img(t_mlx *mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, x, y);
}

t_img	put_img(t_mlx mlx, char *path)
{
	t_img	ig;

	ig.img = mlx_xpm_file_to_image(mlx.mlx, path, &ig.width, &ig.height);
	return (ig);
}

// t_img render_map(char* file_path)
// {
// 	// Read the content of the file "map.ber" and process it
// 	// ...

// 	// Return the rendered image
// 	t_img render_img;
// 	// ...

// 	return render_img;
// }

int	load_img(t_mlx *mlx)
{
	mlx->assets->wall = add_img(*mlx, "../assets/wall.xpm");
	mlx->assets->coin = add_img(*mlx, "../assets/coin.xpm");
	mlx->assets->player = add_img(*mlx, "../assets/player.xpm");
	mlx->assets->door_open = add_img(*mlx, "../assets/door_open.xpm");
	mlx->assets->door_closed = add_img(*mlx, "../assets/door_closed.xpm");
	// mlx->assets->coin_count = 0;
	// mlx->assets->move_count = 0;
	return (0);
}

int	render_assets(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
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


int main(void)
{
	t_mlx data;
	t_img img_data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, data.assets->map_width,
			56 * data.assets->map_height, "so_long");
	if (!data.win)
		return (free(data.mlx), 1);

	img_data.height = HEIGHT;
	img_data.width = WIDTH;

	load_img(&data);
	render_assets(&data);




	// Register key release hook
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
