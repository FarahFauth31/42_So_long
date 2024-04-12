/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:09:38 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/12 14:04:06 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_collectable_or_exit_found(t_game *game)
{
	if (game->map[game->pos_p_y][game->pos_p_x] == 'c')
	{
		game->map[game->pos_p_y][game->pos_p_x] = 'N';
		if (mlx_image_to_window(game->mlx, game->images->path, game->pos_p_x
				* 32, game->pos_p_y * 32) == ERROR)
		{
			ft_printf("Error\nDifficulties in displaying the map.\n");
			mlx_close_window(game->mlx);
		}
		game->c--;
	}
	if (game->map[game->pos_p_y][game->pos_p_x] == 'e' && game->c < 1)
		mlx_close_window(game->mlx);
}

void	change_graphics(t_game *game, int x, int y)
{
	if (game->map[game->pos_p_y + y][game->pos_p_x + x] != '1')
	{
		game->steps++;
		ft_printf("Number of steps taken: %i\n", game->steps);
		mlx_delete_image(game->mlx, game->images->player);
		game->pos_p_x = game->pos_p_x + x;
		game->pos_p_y = game->pos_p_y + y;
		game->images->player = mlx_texture_to_image(game->mlx,
				game->textures->player);
		if_collectable_or_exit_found(game);
		if (mlx_image_to_window(game->mlx, game->images->player, game->pos_p_x
				* 32 + 6, game->pos_p_y * 32) == ERROR)
		{
			ft_printf("Error\nDifficulties in displaying the map.\n");
			mlx_close_window(game->mlx);
		}
	}
}

void	move(keys_t key, t_game *game)
{
	if (key == MLX_KEY_UP)
		change_graphics(game, 0, -1);
	if (key == MLX_KEY_DOWN)
		change_graphics(game, 0, 1);
	if (key == MLX_KEY_LEFT)
		change_graphics(game, -1, 0);
	if (key == MLX_KEY_RIGHT)
		change_graphics(game, 1, 0);
}

void	key_function(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move(keydata.key, game);
}
