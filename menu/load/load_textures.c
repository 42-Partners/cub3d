/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:50:54 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/15 13:00:23 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	check_textures(t_game *game);

void	load_textures(t_game *game)
{
	t_textures	*tex;

	tex = &game->textures;
	tex->cursor_a = mlx_load_png("textures/assets/cursor-1.png");
	tex->cursor_b = mlx_load_png("textures/assets/cursor-2.png");
	tex->scene00_a = mlx_load_png("textures/assets/intro-01.png");
	tex->scene00_b = mlx_load_png("textures/assets/intro-02.png");
	tex->scene00_c = mlx_load_png("textures/assets/42-partners.png");
	tex->scene00_d = mlx_load_png("textures/assets/42.png");
	tex->scene01_a = mlx_load_png("textures/assets/cub3d.png");
	tex->scene01_b = mlx_load_png("textures/assets/menu-bc.png");
	tex->scene01_c = mlx_load_png("textures/assets/start-btn.png");
	tex->scene01_d = mlx_load_png("textures/assets/exit-btn.png");
	tex->scene01_e = mlx_load_png("textures/assets/cub3d-logo.png");
	tex->scene02_a = mlx_load_png("textures/assets/maps-bc.png");
	tex->scene02_b = mlx_load_png("textures/assets/back-btn.png");
	tex->scene02_c = mlx_load_png("textures/assets/map01.png");
	tex->scene02_d = mlx_load_png("textures/assets/map02.png");
	tex->scene02_e = mlx_load_png("textures/assets/map03.png");
	tex->scene02_f = mlx_load_png("textures/assets/map04.png");
	tex->scene02_g = mlx_load_png("textures/assets/map05.png");
	tex->scene02_h = mlx_load_png("textures/assets/map06.png");
	check_textures(game);
	load_images(game);
}

static void	check_textures(t_game *game)
{
	if (
		!game->textures.cursor_a
		|| !game->textures.cursor_b
		|| !game->textures.scene00_a
		|| !game->textures.scene00_b
		|| !game->textures.scene00_c
		|| !game->textures.scene00_d
		|| !game->textures.scene01_a
		|| !game->textures.scene01_b
		|| !game->textures.scene01_c
		|| !game->textures.scene01_d
		|| !game->textures.scene01_e
		|| !game->textures.scene02_a
	)
		error_exit(game, "Failed loading game assets.");
}
