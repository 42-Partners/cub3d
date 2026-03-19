/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:03:36 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/19 04:43:21 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *game)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	color = game->floor_color;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
			mlx_put_pixel(game->img, x, y++, color);
		x++;
	}
}
