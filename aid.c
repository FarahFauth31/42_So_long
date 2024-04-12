/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:05:19 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/12 13:16:06 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*game_init(void)
{
	t_game	*game;

	game = (t_game *) malloc (sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->reach_c = 0;
	game->reach_e = 0;
	game->steps = 0;
	game->mlx = NULL;
	game->textures = NULL;
	game->images = NULL;
	return (game);
}

void	display_char_pp(char **char_pp)
{
	int	i;

	i = 0;
	while (char_pp[i] != NULL)
	{
		ft_printf("map: %s", char_pp[i]);
		i++;
	}
}

void	resize_function(int32_t width, int32_t height, void *param)
{
	(void) width;
	(void) height;
	(void) param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

int	count_characters(t_game *game, int i)
{
	int	j;

	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				game->c++;
			if (game->map[i][j] == 'P')
			{
				game->pos_p_x = j;
				game->pos_p_y = i;
				game->p++;
			}
			if (game->map[i][j] == 'E')
				game->e++;
			j++;
		}
		if (j != game->width)
			return (ERROR);
		i++;
	}
	return (EXIT_SUCCESS);
}
