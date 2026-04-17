/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 03:25:50 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/15 13:24:35 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	check_images(t_game *game);

void	load_images(t_game *game)
{
	t_images	*imgs;
	t_textures	*tex;

	imgs = &game->images;
	tex = &game->textures;
	imgs->cursor_a = mlx_texture_to_image(game->mlx, tex->cursor_a);
	imgs->cursor_b = mlx_texture_to_image(game->mlx, tex->cursor_b);
	imgs->scene00_a = mlx_texture_to_image(game->mlx, tex->scene00_a);
	imgs->scene00_b = mlx_texture_to_image(game->mlx, tex->scene00_b);
	imgs->scene00_c = mlx_texture_to_image(game->mlx, tex->scene00_c);
	imgs->scene00_d = mlx_texture_to_image(game->mlx, tex->scene00_d);
	imgs->scene01_a = mlx_texture_to_image(game->mlx, tex->scene01_a);
	imgs->scene01_b = mlx_texture_to_image(game->mlx, tex->scene01_b);
	imgs->scene01_c = mlx_texture_to_image(game->mlx, tex->scene01_c);
	imgs->scene01_d = mlx_texture_to_image(game->mlx, tex->scene01_d);
	imgs->scene01_e = mlx_texture_to_image(game->mlx, tex->scene01_e);
	imgs->scene02_a = mlx_texture_to_image(game->mlx, tex->scene02_a);
	imgs->scene02_b = mlx_texture_to_image(game->mlx, tex->scene02_b);
	imgs->scene02_c = mlx_texture_to_image(game->mlx, tex->scene02_c);
	imgs->scene02_d = mlx_texture_to_image(game->mlx, tex->scene02_d);
	imgs->scene02_e = mlx_texture_to_image(game->mlx, tex->scene02_e);
	imgs->scene02_f = mlx_texture_to_image(game->mlx, tex->scene02_f);
	imgs->scene02_g = mlx_texture_to_image(game->mlx, tex->scene02_g);
	imgs->scene02_h = mlx_texture_to_image(game->mlx, tex->scene02_h);
	check_images(game);
}

static void	check_images(t_game *game)
{
	if (
		!game->textures.cursor_a
		|| !game->textures.cursor_b
		|| !game->images.scene00_a
		|| !game->images.scene00_b
		|| !game->images.scene00_c
		|| !game->images.scene00_d
		|| !game->images.scene01_a
		|| !game->images.scene01_b
		|| !game->images.scene01_c
		|| !game->images.scene01_d
		|| !game->images.scene01_e
		|| !game->images.scene02_a
		|| !game->images.scene02_b
		|| !game->images.scene02_c
		|| !game->images.scene02_d
		|| !game->images.scene02_e
		|| !game->images.scene02_f
		|| !game->images.scene02_g
		|| !game->images.scene02_h
	)
		error_exit(game, "Failed loading game assets.");
}
