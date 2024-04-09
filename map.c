/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:17:21 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/09 18:18:48 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(char *map)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	i = 0;
	line = get_next_line(fd);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	close(fd);
	return (i);
}

int	get_height(char *map)
{
	int	i;
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

int	safe_map(char *map, t_game *game)
{
	int	i;
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	i = 0;
	game->map[i] = get_next_line(fd);
	while (game->map[i] != NULL)
	{
		i++;
		game->map[i] = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_read_map(char *map, t_game *game)
{
	game->width = get_width(map);
	game->height = get_height(map);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	game->map[game->height] = NULL;
	if (safe_map(map, game) == ERROR || game->width == ERROR
		|| game->height == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
