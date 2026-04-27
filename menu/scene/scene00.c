/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 00:35:55 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 01:57:19 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	scene00_fade(t_game *game, long e)
{
	if (e >= 1100 && e < 1800)
		fade_out(game, ((e - 1100) * 255) / 300);
	else if (e >= 2600 && e < 3600)
		fade_out(game, ((e - 2600) * 255) / 300);
	else if (e >= 4600)
		fade_out(game, ((e - 4600) * 255) / 300);
}

void	scene00(t_game *game)
{
	long	e;
	int		px;
	int		py;

	e = get_time() - game->start_timestamp;
	px = WIDTH / 2 - 512;
	py = HEIGHT / 2 - 512;
	game->on_scene = true;
	put_background(game->img, 0xFFFFFFFF);
	if (e < 1800)
	{
		if (e < 700 || (e >= 900 && e < 1100) || e >= 1100)
			draw_image_to_image(game->img, game->images.scene00_a, px, py);
		else if (e < 900)
			draw_image_to_image(game->img, game->images.scene00_b, px, py);
	}
	else if (e < 3600)
		draw_image_to_image(game->img, game->images.scene00_c, px, py);
	else
		draw_image_to_image(game->img, game->images.scene00_d, px, py);
	scene00_fade(game, e);
}
