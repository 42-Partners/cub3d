/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 15:34:05 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/16 17:24:38 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		error_exit(game, NULL);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->fade = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || !game->fade)
		error_exit(game, NULL);
	mlx_key_hook(game->mlx, handle_key, game);
	load_textures(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	game->on_scene = false;
	mlx_loop_hook(game->mlx, load_menu, game);
	game->start_timestamp = get_time();
	game->start = false;
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	game->cursor_x = 0;
	game->cursor_y = 0;
}
