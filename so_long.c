/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/13 12:00:36 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

int on_destroy(mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, mlx_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

t_img add_img(mlx_data data, char *path)
{
	t_img render_img;

	render_img.img = mlx_xpm_file_to_image(data.mlx, path, &render_img.width, &render_img.height);
	return (render_img);
}

void	mlx_render_img(mlx_data *mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, x, y);
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

int	load_assets(mlx_data *mlx)
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


int main(void)
{
	mlx_data data;
	t_img img_data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 600, 400, "so_long");
	if (!data.win)
		return (free(data.mlx), 1);

	img_data.height = HEIGHT;
	img_data.width = WIDTH;

	img_data.img = mlx_xpm_file_to_image(data.mlx, "assets/wall.xpm", &img_data.width, &img_data.height);

	// int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

	//  mlx_put_image_to_window(data.mlx, data.win,img_data.img,0,0);
	//  mlx_put_image_to_window(data.mlx, data.win,img_data.img,WIDTH,HEIGHT);
	//  mlx_put_image_to_window(data.mlx, data.win,img_data.img,WIDTH*2,HEIGHT*2);




	// Register key release hook
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
