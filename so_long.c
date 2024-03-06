/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/06 18:45:23 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
	void *mlx;
	void *win_ptr;
} t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win_ptr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(void)
{
	mlx_data data;
	t_img img;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx), 1);

	img.height = HEIGHT;
	img.width = WIDTH;
	img.img = mlx_xpm_file_to_image(data.mlx, "assets/wall.xpm", &img.width, &img.height);
	// int mlx_put_image_to_window(void *mlx, void *win_ptr, void *img_ptr, int x, int y);
	// mlx_put_image_to_window(data.mlx, data.win_ptr)
	// mlx_put_image_to_window(game->mlx, game->window, game->textures.wall, 0 + i * 32, 0 + (index * 32));
	// void	mlx_img_put(mlx_data *mlx, t_img img, int img.width, int img.height)

	// void	mlx_img_put(t_mlx *mlx, t_img img, int x, int y)
// {
	mlx_put_image_to_window(data.mlx, data.win_ptr, img.img, img.width, img.height);
// }


	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
