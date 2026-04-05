/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:06:10 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/05 13:59:55 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		error_exit(game, NULL);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		error_exit(game, NULL);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_close_hook(game->mlx, close_window, game);
	mlx_key_hook(game->mlx, handle_key, game);
	mlx_cursor_hook(game->mlx, &mouse_hook, game);
	mlx_loop_hook(game->mlx, render, game);
}

void	init_player_vectors(t_game *game)
{
	char	orientation;

	orientation = game->player.orientation;
	if (orientation == 'N')
		game->player.angle = -M_PI / 2;
	else if (orientation == 'S')
		game->player.angle = M_PI / 2;
	else if (orientation == 'E')
		game->player.angle = 0;
	else if (orientation == 'W')
		game->player.angle = M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->player.plane_x = -game->player.dir_y * 0.66;
	game->player.plane_y = game->player.dir_x * 0.66;
}
