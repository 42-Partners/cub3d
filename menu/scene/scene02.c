/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 06:15:39 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 02:36:26 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "libft.h"

static void	write_mlx(mlx_t *mlx, char *str, int x, int y)
{
	static int	on = 0;

	if (on < 6)
	{
		mlx_put_string(mlx, str, x, y);
		on++;
	}
}

void	draw_card(t_game *game, mlx_image_t *img, char *str, int *pos)
{
	int			x;
	int			y;
	uint32_t	*px;

	y = pos[1] - 4;
	while (++y < (int)(pos[1] + img->height + 26))
	{
		x = pos[0] - 4;
		while (++x < (int)(pos[0] + img->width + 4))
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			{
				px = (uint32_t *)&game->img->pixels[(y * WIDTH + x) * 4];
				*px = 0x000000FF;
			}
		}
	}
	draw_image_to_image(game->img, img, pos[0], pos[1]);
	write_mlx(game->mlx, str, pos[0], pos[1] + img->height + 5);
}

void	put_cards(t_game *game)
{
	int	pos[2];

	pos[0] = WIDTH * 0.22;
	pos[1] = HEIGHT * 0.25;
	draw_card(game, game->images.scene02_c, "Iron Maiden", pos);
	pos[0] = WIDTH / 2 - game->images.scene02_d->width / 2;
	draw_card(game, game->images.scene02_d, "Retr0", pos);
	pos[0] = WIDTH - (WIDTH * 0.22) - game->images.scene02_e->width;
	draw_card(game, game->images.scene02_e, "Donut", pos);
	pos[0] = WIDTH * 0.22;
	pos[1] = HEIGHT * 0.55;
	draw_card(game, game->images.scene02_f, "Mosh pit", pos);
	pos[0] = WIDTH / 2 - game->images.scene02_d->width / 2;
	draw_card(game, game->images.scene02_g, "Whale", pos);
	pos[0] = WIDTH - (WIDTH * 0.22) - game->images.scene02_e->width;
	draw_card(game, game->images.scene02_h, "Horror maze", pos);
}

void	scene02(t_game *game)
{
	run_background(game, get_time() - game->start_timestamp);
	draw_image_to_image(game->img, game->images.scene02_a,
		WIDTH / 2 - game->images.scene02_a->width / 2,
		HEIGHT / 2 - game->images.scene02_a->height / 2 + 50);
	put_cards(game);
	draw_image_to_image(game->img, game->images.scene02_b,
		WIDTH * 0.12, HEIGHT * 0.06);
	if (((game->cursor_x >= 155 && game->cursor_x <= 320)
			&& (game->cursor_y >= 115 && game->cursor_y <= 165))
		|| (((game->cursor_x >= 255 && game->cursor_x <= 445)
				|| (game->cursor_x >= 505 && game->cursor_x <= 690)
				|| (game->cursor_x >= 750 && game->cursor_x <= 945))
			&& ((game->cursor_y >= 200 && game->cursor_y <= 410)
				|| (game->cursor_y >= 440 && game->cursor_y <= 650))))
		render_cursor(game, game->images.cursor_b);
	else
		render_cursor(game, game->images.cursor_a);
}
