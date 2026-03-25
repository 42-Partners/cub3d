/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:06:10 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/25 17:05:52 by devrafaelly      ###   ########.fr       */
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

void	init_player_vectors(t_game *game)
{
	char	orientation;
	
	orientation = game->player.orientation;
	if (orientation == 'N')
		game->player.dir_y = -1;
	else if (orientation == 'S')
		game->player.dir_y = 1;
	else if (orientation == 'E')
		game->player.dir_x = 1;
	else if (orientation == 'W')
		game->player.dir_x = -1;
	game->player.plane_x = -game->player.dir_y * 0.66;
	game->player.plane_y = game->player.dir_x * 0.66;
}
