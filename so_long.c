/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/03/13 11:27:34 by iverniho         ###   ########.fr       */
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
	void *win;
} t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
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

t_img add_img(mlx_data data, char *path)
{
	t_img render_img;

	render_img.img = mlx_xpm_file_to_image(data.mlx, path, &render_img.width, &render_img.height);
	return (render_img);
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

	int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

	 mlx_put_image_to_window(data.mlx, data.win,img_data.img,0,0);
	 mlx_put_image_to_window(data.mlx, data.win,img_data.img,WIDTH,HEIGHT);
	 mlx_put_image_to_window(data.mlx, data.win,img_data.img,WIDTH*2,HEIGHT*2);




	// Register key release hook
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
