/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:25:26 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/10 13:26:03 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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
