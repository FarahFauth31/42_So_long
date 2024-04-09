/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffauth-p <ffauth-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:05:19 by ffauth-p          #+#    #+#             */
/*   Updated: 2024/04/09 20:05:23 by ffauth-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_position(int x, int y, int *pos_2d)
{
	pos_2d[0] = x;
	pos_2d[1] = y;
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
