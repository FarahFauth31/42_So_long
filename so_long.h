/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:15:56 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/09 20:07:37 by ffauth-p         ###   ########.fr       */
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

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		P;
	int		C;
	int		E;
	int		pos_P[2];
	int		reach_C;
	int		reach_E;
}			t_game;

/* Map */
int	get_width(char *map);
int	get_height(char *map);
int	safe_map(char *map, t_game *game);
int	ft_read_map(char *map, t_game *game);

/* Aid */
void	fill_position(int x, int y, int *pos_2d);
void	display_char_pp(char **char_pp);

/* Errors */
void	count_characters(t_game *game);
int		horizontal_limits(t_game *game);
int		vertical_limits(t_game *game);
void	ft_reach(t_game *game, int x_pos, int y_pos);
int		ft_errors(t_game *game);


#endif