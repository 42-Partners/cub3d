/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:06:10 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/22 00:01:49 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_loop_hook(game->mlx, render, game);
}
