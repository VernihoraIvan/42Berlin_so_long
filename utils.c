/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:18:38 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/03 16:58:52 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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

int	check_extention(char *map)
{
	char	**s;
	s = ft_split(map, '.');
	if(ft_strncmp(s[1],"ber", 3) != 0)
	{
		free(s);
		return(0);
	}
	free(s);
	return(1);
}

void	free_map(char **map, int i)
{
	int	j;

	j = 0;
	while (j++ < i)
		free(map[j]);
	free(map);
}
