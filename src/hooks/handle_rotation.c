/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:29:25 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/01 17:41:05 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

static void	rotate(t_game *game, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x
		= game->player.dir_x * cos(speed) - game->player.dir_y * sin(speed);
	game->player.dir_y
		= old_dir_x * sin(speed) + game->player.dir_y * cos(speed);
	game->player.plane_x
		= game->player.plane_x * cos(speed) - game->player.plane_y * sin(speed);
	game->player.plane_y
		= old_plane_x * sin(speed) + game->player.plane_y * cos(speed);
}

void	handle_rotation(t_game *game)
{
	game->player.rot_speed = game->mlx->delta_time * 1.1;
	if (game->input.right)
		rotate(game, game->player.rot_speed);
	else if (game->input.left)
		rotate(game, -game->player.rot_speed);
}
