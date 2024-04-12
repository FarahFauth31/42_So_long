/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:15:41 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/11 11:40:07 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = game_init();
		if (game == NULL)
			return (EXIT_FAILURE);
		if (ft_read_map(argv[1], game) == ERROR || ft_errors(game) == ERROR)
		{
			ft_cleanup(ERROR_MAP, game);
			return (EXIT_FAILURE);
		}
		game->mlx = mlx_init(game->width * 32, game->height * 32, "So_long",
				true);
		if (display_game_on_window(game) == ERROR)
		{
			ft_cleanup(ERROR_GRAPHICS, game);
			return (EXIT_FAILURE);
		}
		mlx_key_hook(game->mlx, &key_function, game);
		mlx_resize_hook(game->mlx, &resize_function, game);
		mlx_loop(game->mlx);
		ft_cleanup(0, game);
	}
	return (EXIT_SUCCESS);
}
