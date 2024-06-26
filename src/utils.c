/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:18:38 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/15 13:26:36 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *map)
{
	int		file;
	int		lines;
	char	*temp;

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
	int	i;

	i = 0;
	if (ft_strchr(map, '.') == 0)
		return (print_error(11), 0);
	while (map[i])
	{
		if (map[i] == '.')
		{
			if (!(map[i + 1] == 'b' && map[i + 2] == 'e' \
			&& map[i + 3] == 'r' && !(map[i + 4])))
				return (print_error(7), 0);
			else
				return (1);
		}
		i++;
	}
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

void	free_passed(int **passed, t_relement *game)
{
	int	i;

	i = 0;
	determine_player_position(game);
	while (i < game->map_height)
	{
		free(passed[i]);
		i++;
	}
	free(passed);
}

int	check_borders(char **map, t_relement *assets)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strncmp(map[0], map[assets->map_height - 1], assets->map_width) \
		!= 0 || check_map_len(map, assets) == 0)
		return (0);
	while (i < assets->map_height)
	{
		if (map[i][0] == '\n' && map[i--][j++] != '1')
			return (0);
		if (map[i][j] != map[i][assets->map_width - 2])
			return (print_error(2), 0);
		i++;
	}
	assets->moves_count = 0;
	return (1);
}
