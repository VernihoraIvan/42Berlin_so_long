/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:50:25 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/09 11:24:36 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_move_valid(t_relement *game, int **passed, int row, int col)
{
	return (game->map[row][col] != '1' && !passed[row][col]);
}

void	floodfill(t_relement *game, int row, int col, int **passed)
{
	if (!is_move_valid(game, passed, row, col) || passed[row][col])
		return ;
	passed[row][col] = 1;
	floodfill(game, row - 1, col, passed);
	floodfill(game, row + 1, col, passed);
	floodfill(game, row, col - 1, passed);
	floodfill(game, row, col + 1, passed);
}

void	find_player_pos(t_relement *game, int i, int *col, int *row)
{
	int	j;

	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'P')
		{
			*row = i;
			*col = j;
			break ;
		}
		j++;
	}
}

void	find_escape_position(t_relement *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_row = i;
				game->exit_col = j;
			}
			j++;
		}
		i++;
	}
}

int	is_valid_path(t_relement *game)
{
	int	i;
	int	row;
	int	col;
	int	**passed;

	passed = ft_calloc(game->map_height, sizeof(int *));
	i = 0;
	while (i < game->map_height)
	{
		passed[i] = ft_calloc(game->map_width, sizeof(int *));
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		find_player_pos(game, i, &col, &row);
		i++;
	}
	find_escape_position(game);
	floodfill(game, row, col, passed);
	i = passed[row][col] && passed[game->exit_row][game->exit_col];
	free_passed(passed, game);
	if (!i)
		return (print_error(8), 1);
	return (0);
}
