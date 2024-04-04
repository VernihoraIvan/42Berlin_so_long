/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:18:38 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/04 12:57:05 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	count_lines(char *map)
{
	int		file;
	int		lines;
	char	*temp;


	// char	*line;

	lines = 0;
	file = open(map, O_RDONLY);
	temp = get_next_line(file);
	while (temp)
	{
		lines++;
		free(temp);
		temp = get_next_line(file);
	}
	close(file);
	return (lines);
}

int	check_extention(char *map)
{
	printf("1\n");
	int	len;
	int	i;
	char	*ber;

	i = 3;
	ber = "ber";

	len = ft_strlen(map);
	while (len >= 0 && i >= 0 && map[len] == ber[i])
	{
		printf("2\n");

		len--;
		i--;
	}
	printf("3\n");

	if (i == -1)
		return (1);
	return (0);
}

void	free_map(char **map, int i)
{
	int	j;

	j = 0;
	while (j++ < i)
		free(map[j]);
	free(map);
}

int	check_borders(char **map, t_relement *assets)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	// printf("diff %d\n", ft_strncmp(map[0], map[assets->map_height - 1], assets->map_width));
	if (ft_strncmp(map[0], map[assets->map_height - 1], assets->map_width) != 0)
		return (0);
	while (i < assets->map_height)
	{
		if (map[i][j] != map[i][assets->map_width - 2])
			return (0);
		i++;
	}
	return (1);
}
