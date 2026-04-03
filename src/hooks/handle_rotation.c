/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:29:25 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/03 17:44:14 by gustaoli         ###   ########.fr       */
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
	game->player.rot_speed = game->mlx->delta_time * 1.4;
	if (game->input.right)
		rotate(game, game->player.rot_speed);
	if (game->input.left)
		rotate(game, -game->player.rot_speed);
	if (game->input.up && game->player.camera_height + 8 <= 400)
		game->player.camera_height += 8;
	if (game->input.down && game->player.camera_height - 8 >= -400)
		game->player.camera_height -= 8;
}

void	mouse_hook(double x, double y, void *param)
{
	t_game	*game;

	game = (t_game *)param;

	while (x-- > WIDTH / 2)
		rotate(game, game->mlx->delta_time * 0.05);
	while (x++ < WIDTH / 2)
		rotate(game, -game->mlx->delta_time * 0.05);
	if (y < HEIGHT / 2 && game->player.camera_height + 4 <= 400)
		game->player.camera_height += 4;
	if (y > HEIGHT / 2 && game->player.camera_height - 4 >= -400)
		game->player.camera_height -= 4;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
}
