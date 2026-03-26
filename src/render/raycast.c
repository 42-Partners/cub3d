/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 02:03:11 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/26 18:03:36 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	calc_delta(t_game *game, int col);
static void	calc_step(t_game *game);
static void	launch_ray(t_game *game);
static void	calc_perp_wal_dis(t_game *game);
// temporario
// static void	temp_drawwalls(t_game *game, int col);

void	raycast(t_game *game)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
	{
		calc_delta(game, i);
		calc_step(game);
		launch_ray(game);
	}
}
// temp_drawwalls(game, i);

static void	calc_delta(t_game *game, int col)
{
	double	camera_x;

	camera_x = 2 * col / (double)WIDTH - 1.0;
	game->rc.ray_dir_x
		= game->player.dir_x + -game->player.dir_y * 0.66 * camera_x;
	game->rc.ray_dir_y
		= game->player.dir_y + game->player.dir_x * 0.66 * camera_x;
	if (fabs(game->rc.ray_dir_x) < 1e-6)
		game->rc.ray_dir_x = 1e-6;
	if (fabs(game->rc.ray_dir_y) < 1e-6)
		game->rc.ray_dir_y = 1e-6;
	game->rc.map_x = floor(game->player.pos_x);
	game->rc.map_y = floor(game->player.pos_y);
	game->rc.delta_dis_x = 1e30;
	game->rc.delta_dis_y = 1e30;
	if (game->rc.ray_dir_x != 0)
		game->rc.delta_dis_x = fabs(1 / game->rc.ray_dir_x);
	if (game->rc.ray_dir_y != 0)
		game->rc.delta_dis_y = fabs(1 / game->rc.ray_dir_y);
}

static void	calc_step(t_game *game)
{
	game->rc.step_x = 1;
	game->rc.step_y = 1;
	if (game->rc.ray_dir_x < 0)
	{
		game->rc.step_x = -1;
		game->rc.side_dis_x
			= (game->player.pos_x - game->rc.map_x) * game->rc.delta_dis_x;
	}
	else
		game->rc.side_dis_x
			= (game->rc.map_x + 1.0 - game->player.pos_x)
			* game->rc.delta_dis_x;
	if (game->rc.ray_dir_y < 0)
	{
		game->rc.step_y = -1;
		game->rc.side_dis_y
			= (game->player.pos_y - game->rc.map_y) * game->rc.delta_dis_y;
	}
	else
		game->rc.side_dis_y
			= (game->rc.map_y + 1.0 - game->player.pos_y)
			* game->rc.delta_dis_y;
}

static void	launch_ray(t_game *game)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (game->rc.side_dis_x < game->rc.side_dis_y)
		{
			game->rc.side_dis_x += game->rc.delta_dis_x;
			game->rc.map_x += game->rc.step_x;
			game->rc.side = 0;
		}
		else
		{
			game->rc.side_dis_y += game->rc.delta_dis_y;
			game->rc.map_y += game->rc.step_y;
			game->rc.side = 1;
		}
		if (game->map.map[(game->rc.map_y)][(game->rc.map_x)] == '1')
			hit = true;
	}
	calc_perp_wal_dis(game);
}

static void	calc_perp_wal_dis(t_game *game)
{
	if (game->rc.side == 0)
	{
		game->rc.perp_wall_dis
			= (game->rc.map_x - game->player.pos_x
				+ (1 - game->rc.step_x) / 2) / game->rc.ray_dir_x;
		game->rc.wall_x
			= game->player.pos_y + game->rc.perp_wall_dis * game->rc.ray_dir_y;
		if (game->rc.ray_dir_x > 0)
			game->player.facing = EA;
		else
			game->player.facing = WE;
	}
	else
	{
		game->rc.perp_wall_dis
			= (game->rc.map_y - game->player.pos_y
				+ (1 - game->rc.step_y) / 2) / game->rc.ray_dir_y;
		game->rc.wall_x
			= game->player.pos_x + game->rc.perp_wall_dis * game->rc.ray_dir_x;
		if (game->rc.ray_dir_y > 0)
			game->player.facing = SO;
		else
			game->player.facing = NO;
	}
	game->rc.wall_x -= floor(game->rc.wall_x);
}

// temporario
// static void	temp_drawwalls(t_game *game, int col)
// {
// 	int	line_height;
// 	int	draw_start;
// 	int	draw_end;
// 	int	i;

// 	line_height = HEIGHT / game->rc.perp_wall_dis;
// 	draw_start = -line_height / 2 + HEIGHT / 2 + CAMERA_HEIGHT;
// 	draw_end = line_height / 2 + HEIGHT / 2 + CAMERA_HEIGHT;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	if (draw_end >= HEIGHT)
// 		draw_end = HEIGHT - 1;
// 	i = draw_start;
// 	while (i <= draw_end)
// 	{
// 		if (game->player.facing == NO) // zul
// 			mlx_put_pixel(game->img, col, i, 0x000FFFFF);
// 		else if (game->player.facing == SO) // marelo
// 			mlx_put_pixel(game->img, col, i, 0xFFFF00FF);
// 		else if (game->player.facing == EA) // verdin
// 			mlx_put_pixel(game->img, col, i, 0x00FF00FF);
// 		else if (game->player.facing == WE) // vremeio
// 			mlx_put_pixel(game->img, col, i, 0xFF0000FF);
// 		i++;
// 	}
// }
