/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 04:44:00 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 02:36:55 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	reset_img(t_game *game)
{
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->fade = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || !game->fade)
		error_exit(game, NULL);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	handle_click_scene01(t_game *game)
{
	if ((game->cursor_x >= 145 && game->cursor_x <= 375)
		&& (game->cursor_y >= 400 && game->cursor_y <= 450))
		game->start = true;
	else if ((game->cursor_x >= 145 && game->cursor_x <= 375)
		&& (game->cursor_y >= 490 && game->cursor_y <= 550))
		close_window((void *)game);
}

void	handle_click_scene02(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	col = -1;
	if (((game->cursor_x >= 150 && game->cursor_x <= 320)
			&& (game->cursor_y >= 115 && game->cursor_y <= 165)))
	{
		game->start = false;
		reset_img(game);
	}
	if (game->cursor_y >= 200 && game->cursor_y <= 410)
		row = 0;
	else if (game->cursor_y >= 440 && game->cursor_y <= 650)
		row = 1;
	if (game->cursor_x >= 255 && game->cursor_x <= 455)
		col = 0;
	else if (game->cursor_x >= 505 && game->cursor_x <= 690)
		col = 1;
	else if (game->cursor_x >= 750 && game->cursor_x <= 945)
		col = 2;
	if (row != -1 && col != -1)
		load_game(game, col + (3 * row));
}

void	mouse_hook(double x, double y, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)game;
	game->cursor_x = x;
	game->cursor_y = y;
}
