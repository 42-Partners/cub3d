/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_scenes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:50:34 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 02:27:08 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	apply_alpha_fade(mlx_image_t *img, uint32_t color, uint8_t alpha)
{
	uint32_t	y;
	uint32_t	x;
	uint32_t	i;
	uint8_t		rgb[3];

	rgb[0] = (uint8_t)(color >> 24);
	rgb[1] = (uint8_t)(color >> 16);
	rgb[2] = (uint8_t)(color >> 8);
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			i = (y * img->width + x) * 4;
			img->pixels[i] = (uint8_t)((rgb[0]
						* alpha + img->pixels[i] * (255 - alpha)) / 255);
			img->pixels[i + 1] = (uint8_t)((rgb[1]
						* alpha + img->pixels[i + 1] * (255 - alpha)) / 255);
			img->pixels[i + 2] = (uint8_t)((rgb[2]
						* alpha + img->pixels[i + 2] * (255 - alpha)) / 255);
			img->pixels[i + 3] = 255;
		}
	}
}

void	put_background(mlx_image_t *img, uint32_t color)
{
	int			x;
	int			y;
	uint8_t		alpha;

	alpha = color & 0xFF;
	if (alpha == 0)
		return ;
	if (alpha == 255)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
				mlx_put_pixel(img, x++, y, color);
			y++;
		}
		return ;
	}
	apply_alpha_fade(img, color, alpha);
}

void	fade_out(t_game *game, int op)
{
	uint32_t	color;

	if (op > 255)
		op = 255;
	else if (op < 0)
		op = 0;
	color = (0xFFFFFF00 | (uint8_t)op);
	put_background(game->img, color);
}

void	handle_scene(t_game *game)
{
	long	elapsed;

	elapsed = get_time() - game->start_timestamp;
	if (elapsed < 5500 && !game->start)
		return (scene00(game));
	else
		mlx_cursor_hook(game->mlx, &mouse_hook, game);
	if (!game->start)
		scene01(game);
	else
		scene02(game);
}
