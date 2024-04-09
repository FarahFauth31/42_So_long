/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:15:41 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/09 20:08:44 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = (t_game *) malloc (sizeof(t_game));
		ft_read_map(argv[1], game);
		if (ft_errors(game) == ERROR)
			ft_printf("Error in map.\n");
		
		//display_char_pp(game->map);
	}
	return (EXIT_SUCCESS);
}
