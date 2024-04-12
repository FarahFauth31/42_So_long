/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:15:56 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/12 14:05:46 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line_bonus.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR -1
# define ERROR_MAP 3
# define ERROR_GRAPHICS 4

typedef struct s_textures
{
	mlx_texture_t	*player;
	mlx_texture_t	*path;
	mlx_texture_t	*collectable;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
}			t_textures;

typedef struct s_images
{
	mlx_image_t	*player;
	mlx_image_t	*path;
	mlx_image_t	*collectable;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
}			t_images;

typedef struct s_game
{
	char		**map;
	int			width;
	int			height;

	int			p;
	int			c;
	int			e;
	int			pos_p_x;
	int			pos_p_y;
	int			reach_c;
	int			reach_e;
	int			steps;

	void		*mlx;

	t_textures	*textures;
	t_images	*images;
}			t_game;

/* Map */
int		get_width(char *map);
int		get_height(char *map);
int		safe_map(char *map, t_game *game);
int		ft_read_map(char *map, t_game *game);

/* Aid */
t_game	*game_init(void);
void	display_char_pp(char **char_pp);
void	resize_function(int32_t width, int32_t height, void *param);
int		count_characters(t_game *game, int i);

/* Errors */
int		find_invalid_characters(t_game *game, int i);
int		horizontal_limits(t_game *game);
int		vertical_limits(t_game *game);
void	ft_reach(t_game *game, int x_pos, int y_pos);
int		ft_errors(t_game *game);

/* Display */
int		create_textures(t_game *game);
int		create_images(t_game *game);
int		place_images(t_game *game, int32_t i, int32_t j);
int		display_game_on_window(t_game *game);

/* Play */
void	if_collectable_or_exit_found(t_game *game);
void	change_graphics(t_game *game, int x, int y);
void	move(keys_t key, t_game *game);
void	key_function(mlx_key_data_t keydata, void *param);

/* Clean up */
void	ft_free_char_pp(char **stack);
void	cleanup_textures(t_game *game);
void	cleanup_images(t_game *game);
void	ft_cleanup(int error, t_game *game);

#endif
