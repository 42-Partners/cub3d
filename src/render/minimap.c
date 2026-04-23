/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:38:48 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/23 08:38:32 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	render_pixel(t_game *game, int x, int y, uint32_t color)
{
	int	xr;
	int	yr;
	int	p;

	xr = -1;
	while (++xr < MINIMAP_SIZE)
	{
		yr = -1;
		while (++yr < MINIMAP_SIZE)
		{
			p = ((y + yr) * game->img->width + (x + xr)) * 4;
			game->img->pixels[p] = (color >> 24) & 0xFF;
			game->img->pixels[p + 1] = (color >> 16) & 0xFF;
			game->img->pixels[p + 2] = (color >> 8) & 0xFF;
			game->img->pixels[p + 3] = color & 0xFF;
		}
	}
}

static uint32_t	get_color(t_game *game, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = floor(game->player.pos_x) + (x / MINIMAP_SIZE) - 4;
	map_y = floor(game->player.pos_y) + (y / MINIMAP_SIZE) - 4;
	if (map_x < 0 || map_x >= game->map.cols
		|| map_y < 0 || map_y >= game->map.rows)
		return (game->celing_color);
	else if (map_x == floor(game->player.pos_x)
		&& map_y == floor(game->player.pos_y))
		return (0xFFFFFFFF);
	if (game->map.map[map_y][map_x] == '1')
		return (game->floor_color);
	return (game->celing_color);
}


void	render_minimap(t_game *game)
{
	int	pos[2];

	if (game->minimap)
	{
		pos[0] = 5;
		while (pos[0] < 5 + MINIMAP_SIZE * 11)
		{
			pos[1] = 5;
			while (pos[1] < 5 + MINIMAP_SIZE * 11)
			{
				render_pixel(game, pos[0], pos[1],
					get_color(game, pos[0] - 5 - MINIMAP_SIZE / 7,
						pos[1] - 5 - MINIMAP_SIZE / 7));
				pos[1] += MINIMAP_SIZE;
			}
			pos[0] += MINIMAP_SIZE;
		}
	}
}
