/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 00:40:46 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 01:58:54 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	scene01(t_game *game)
{
	long	e;

	e = get_time() - game->start_timestamp;
	run_background(game, e);
	draw_image_to_image(game->img, game->images.scene01_b,
		WIDTH * 0.08, HEIGHT * 0.35);
	draw_image_to_image(game->img, game->images.scene01_c,
		WIDTH * 0.08, HEIGHT * 0.35);
	draw_image_to_image(game->img, game->images.scene01_d,
		WIDTH * 0.08, HEIGHT * 0.35);
	draw_image_to_image(game->img, game->images.scene01_e,
		WIDTH * 0.065, HEIGHT * 0.08);
	if (((game->cursor_x >= 150 && game->cursor_x <= 375)
			&& (game->cursor_y >= 400 && game->cursor_y <= 450))
		|| ((game->cursor_x >= 150 && game->cursor_x <= 375)
			&& (game->cursor_y >= 490 && game->cursor_y <= 550)))
		render_cursor(game, game->images.cursor_b);
	else
		render_cursor(game, game->images.cursor_a);
}
