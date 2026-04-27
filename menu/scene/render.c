/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 05:43:22 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 02:26:52 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	draw_pixel_into_img(mlx_image_t *dst,
				mlx_image_t *src, int *pos, int *draw)
{
	uint32_t	src_idx;
	uint32_t	dst_idx;

	src_idx = (pos[1] * src->width + pos[0]) * 4;
	dst_idx = (draw[1] * dst->width + draw[0]) * 4;
	if (src->pixels[src_idx + 3] > 0)
	{
		dst->pixels[dst_idx] = src->pixels[src_idx];
		dst->pixels[dst_idx + 1] = src->pixels[src_idx + 1];
		dst->pixels[dst_idx + 2] = src->pixels[src_idx + 2];
		dst->pixels[dst_idx + 3] = src->pixels[src_idx + 3];
	}
}

void	draw_image_to_image(mlx_image_t *dst,
				mlx_image_t *src, int pos_x, int pos_y)
{
	uint32_t	pos[2];
	int			draw[2];

	pos[1] = 0;
	if (pos_y < 0)
		pos[1] = (uint32_t) - pos_y;
	while (pos[1] < src->height)
	{
		draw[1] = pos_y + pos[1];
		if (draw[1] >= (int)dst->height)
			break ;
		pos[0] = 0;
		if (pos_x < 0)
			pos[0] = (uint32_t) - pos_x;
		while (pos[0] < src->width)
		{
			draw[0] = pos_x + pos[0];
			if (draw[0] >= (int)dst->width)
				break ;
			draw_pixel_into_img(dst, src, (int *)pos, draw);
			pos[0]++;
		}
		pos[1]++;
	}
}

void	draw_frame(t_game *game, int frame, int pos_x, int pos_y)
{
	int	pos[2];
	int	draw[2];
	int	f_y;

	f_y = frame * 400;
	pos[1] = f_y - 1;
	if (pos_y < 0)
		pos[1] -= pos_y;
	while (++pos[1] < f_y + 400)
	{
		draw[1] = pos_y + (pos[1] - f_y);
		if (draw[1] >= HEIGHT)
			break ;
		pos[0] = -1;
		if (pos_x < 0)
			pos[0] -= pos_x;
		while (++pos[0] < 400)
		{
			draw[0] = pos_x + pos[0];
			if (draw[0] >= WIDTH)
				break ;
			draw_pixel_into_img(game->img, game->images.scene01_a, pos, draw);
		}
	}
}

void	render_cursor(t_game *game, mlx_image_t *cursor)
{
	draw_image_to_image(game->img, cursor, game->cursor_x, game->cursor_y);
}

void	run_background(t_game *game, long e)
{
	int	pos[2];
	int	offset;

	pos[1] = -250;
	offset = 0;
	put_background(game->img, 0x000000FF);
	while (pos[1] < HEIGHT)
	{
		pos[0] = -200 - ((offset++) * 150);
		while (pos[0] < WIDTH)
		{
			if (offset % 2 == 0)
				draw_frame(game, ((e * 12) / 1000) % 23, pos[0], pos[1]);
			else
				draw_frame(game,
					(((e + 1000) * 12) / 1000) % 23, pos[0], pos[1]);
			pos[0] += 300;
		}
		pos[1] += 300;
	}
}
