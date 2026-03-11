/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:06:10 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/11 18:21:09 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", RESIZE);
	if (!game->mlx)
		error_exit(game, NULL);
	mlx_close_hook(game->mlx, close_window, game);
	mlx_key_hook(game->mlx, handle_key, game);
	mlx_loop(game->mlx);
}
