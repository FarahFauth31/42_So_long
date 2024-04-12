/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:19:50 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/12 13:18:45 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_invalid_characters(t_game *game, int i)
{
	int	j;

	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (!(game->map[i][j] == 'C') && !(game->map[i][j] == 'P')
				&& !(game->map[i][j] == 'E') && !(game->map[i][j] == '1')
				&& !(game->map[i][j] == '0'))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	horizontal_limits(t_game *game)
{
	char	*top_wall;
	char	*bottom_wall;
	int		i;

	top_wall = game->map[0];
	bottom_wall = game->map[game->height - 1];
	i = 0;
	while (top_wall[i] == '1')
		i++;
	if (top_wall[i] != '\n' && top_wall[i] != '\0')
		return (ERROR);
	i = 0;
	while (bottom_wall[i] == '1')
		i++;
	if (bottom_wall[i] != '\n' && bottom_wall[i] != '\0')
		return (ERROR);
	return (EXIT_SUCCESS);
}

int	vertical_limits(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][game->width - 1] != '1')
			return (ERROR);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_reach(t_game *game, int x_pos, int y_pos)
{
	if (game->map[y_pos][x_pos] == '1' || y_pos < 0 || y_pos > game->height
		|| x_pos < 0 || x_pos > game->width || game->map[y_pos][x_pos] == 'N'
		|| game->map[y_pos][x_pos] == 'p' || game->map[y_pos][x_pos] == 'c'
		|| game->map[y_pos][x_pos] == 'e')
		return ;
	if (game->map[y_pos][x_pos] == 'C')
	{
		game->reach_c = 1;
		game->map[y_pos][x_pos] = 'c';
	}
	if (game->map[y_pos][x_pos] == 'E')
	{
		game->reach_e = 1;
		game->map[y_pos][x_pos] = 'e';
	}
	if (game->map[y_pos][x_pos] == '0')
		game->map[y_pos][x_pos] = 'N';
	if (game->map[y_pos][x_pos] == 'P')
		game->map[y_pos][x_pos] = 'p';
	ft_reach(game, x_pos - 1, y_pos);
	ft_reach(game, x_pos + 1, y_pos);
	ft_reach(game, x_pos, y_pos - 1);
	ft_reach(game, x_pos, y_pos + 1);
}

int	ft_errors(t_game *game)
{
	if (game->width == game->height || game->width < 3 || game->height < 3)
		return (ERROR);
	if (count_characters(game, 0) == ERROR || find_invalid_characters(game,
			0) == ERROR)
		return (ERROR);
	if (!(game->p == 1) || game->c < 1 || !(game->e == 1))
		return (ERROR);
	if (horizontal_limits(game) == ERROR || vertical_limits(game) == ERROR)
		return (ERROR);
	ft_reach(game, game->pos_p_x, game->pos_p_y);
	if (game->reach_c == 0 || game->reach_e == 0)
		return (ERROR);
	return (EXIT_SUCCESS);
}
