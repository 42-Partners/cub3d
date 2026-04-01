/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:03:36 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/01 16:12:31 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				render_wall_pixel(t_game *game,
							mlx_texture_t *tex, int col, int y);
static mlx_texture_t	*select_texture(t_game *game);
static uint32_t			convert_color(uint32_t color);

void	render_background(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < (HEIGHT / 2) + CAMERA_HEIGHT)
			mlx_put_pixel(game->img, x, y++, game->celing_color);
		while (y < HEIGHT)
			mlx_put_pixel(game->img, x, y++, game->floor_color);
		x++;
	}
}

void	render_col(t_game *game, int col)
{
	int	y;

	game->rc.line_height = HEIGHT / game->rc.perp_wall_dis;
	game->rc.draw_start
		= -game->rc.line_height / 2 + HEIGHT / 2 + CAMERA_HEIGHT;
	game->rc.draw_end = game->rc.line_height / 2 + HEIGHT / 2 + CAMERA_HEIGHT;
	if (game->rc.draw_start < 0)
		game->rc.draw_start = 0;
	if (game->rc.draw_end >= HEIGHT)
		game->rc.draw_end = HEIGHT - 1;
	y = game->rc.draw_start;
	while (y <= game->rc.draw_end)
	{
		render_wall_pixel(game, select_texture(game), col, y);
		y++;
	}
}

static void	render_wall_pixel(t_game *game, mlx_texture_t *tex, int col, int y)
{
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	uint32_t		color;

	tex_pos = (double)(y - game->rc.draw_start) / game->rc.line_height;
	if (tex_pos < 0)
		tex_pos = 0;
	if (tex_pos > 1)
		tex_pos = 1;
	tex_y = (int)(tex_pos * tex->height);
	if (tex_y >= (int)tex->height)
		tex_y = tex->height - 1;
	tex_x = (int)(game->rc.wall_x * tex->width);
	if (tex_x >= (int)tex->width)
		tex_x = tex->width - 1;
	if (tex == game->textures.so || tex == game->textures.we)
		tex_x = tex->width - tex_x - 1;
	color
		= convert_color(((uint32_t *)tex->pixels)[tex_y * tex->width + tex_x]);
	mlx_put_pixel(game->img, col, y, color);
}

static mlx_texture_t	*select_texture(t_game *game)
{
	if (game->player.facing == NO)
		return (game->textures.no);
	else if (game->player.facing == SO)
		return (game->textures.so);
	else if (game->player.facing == EA)
		return (game->textures.ea);
	else if (game->player.facing == WE)
		return (game->textures.we);
}

static uint32_t	convert_color(uint32_t color)
{
	return (((color & 0x000000FF) << 24)
		| ((color & 0x0000FF00) << 8)
		| ((color & 0x00FF0000) >> 8)
		| ((color & 0xFF000000) >> 24));
}
