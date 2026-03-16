/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:03:36 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/13 18:24:03 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *game)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	color = 0xFF9A56FF;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
			mlx_put_pixel(game->img, x, y++, color);
		x++;
	}
}
