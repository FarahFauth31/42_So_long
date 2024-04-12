/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:29:47 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/12 13:47:00 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_char_pp(char **stack)
{
	int	i;

	i = 0;
	while (stack[i] != NULL)
	{
		free(stack[i]);
		i++;
	}
	free (stack);
}

void	cleanup_textures(t_game *game)
{
	free(game->textures->player->pixels);
	free(game->textures->path->pixels);
	free(game->textures->collectable->pixels);
	free(game->textures->wall->pixels);
	free(game->textures->exit->pixels);
	free(game->textures->player);
	free(game->textures->path);
	free(game->textures->collectable);
	free(game->textures->wall);
	free(game->textures->exit);
	free(game->textures);
}

void	cleanup_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->images->player);
	mlx_delete_image(game->mlx, game->images->path);
	mlx_delete_image(game->mlx, game->images->collectable);
	mlx_delete_image(game->mlx, game->images->wall);
	mlx_delete_image(game->mlx, game->images->exit);
	free(game->images);
}

void	ft_cleanup(int error, t_game *game)
{
	if (error == ERROR_MAP)
		ft_printf("Error\nInvalid map.\n");
	if (error == ERROR_GRAPHICS)
		ft_printf("Error\nDifficulties in displaying the map.\n");
	if (game->textures != NULL)
		cleanup_textures(game);
	if (game->images != NULL)
		cleanup_images(game);
	if (game->map != NULL)
		ft_free_char_pp(game->map);
	free(game);
}
