/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:18:39 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/17 00:29:58 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	clean_t(mlx_t *mlx, void *t, int flag)
{
	if (t)
	{
		if (flag == 1)
			mlx_delete_texture((mlx_texture_t *)t);
		else if (flag == 2)
			mlx_delete_image(mlx, (mlx_image_t *)t);
	}
}

static void	clean_scenes_tex(t_game *game)
{
	clean_t(game->mlx, game->textures.scene00_a, 1);
	clean_t(game->mlx, game->textures.scene00_b, 1);
	clean_t(game->mlx, game->textures.scene00_c, 1);
	clean_t(game->mlx, game->textures.scene00_d, 1);
	clean_t(game->mlx, game->textures.scene01_a, 1);
	clean_t(game->mlx, game->textures.scene01_b, 1);
	clean_t(game->mlx, game->textures.scene01_c, 1);
	clean_t(game->mlx, game->textures.scene01_d, 1);
	clean_t(game->mlx, game->textures.scene01_e, 1);
	clean_t(game->mlx, game->textures.scene02_a, 1);
	clean_t(game->mlx, game->textures.scene02_b, 1);
	clean_t(game->mlx, game->textures.scene02_c, 1);
	clean_t(game->mlx, game->textures.scene02_d, 1);
	clean_t(game->mlx, game->textures.scene02_e, 1);
	clean_t(game->mlx, game->textures.scene02_f, 1);
	clean_t(game->mlx, game->textures.scene02_g, 1);
	clean_t(game->mlx, game->textures.scene02_h, 1);
}

static void	clean_scenes_images(t_game *game)
{
	clean_t(game->mlx, game->images.scene00_a, 2);
	clean_t(game->mlx, game->images.scene00_b, 2);
	clean_t(game->mlx, game->images.scene00_c, 2);
	clean_t(game->mlx, game->images.scene00_d, 2);
	clean_t(game->mlx, game->images.scene01_a, 2);
	clean_t(game->mlx, game->images.scene01_b, 2);
	clean_t(game->mlx, game->images.scene01_c, 2);
	clean_t(game->mlx, game->images.scene01_d, 2);
	clean_t(game->mlx, game->images.scene01_e, 2);
	clean_t(game->mlx, game->images.scene02_a, 2);
	clean_t(game->mlx, game->images.scene02_b, 2);
	clean_t(game->mlx, game->images.scene02_c, 2);
	clean_t(game->mlx, game->images.scene02_d, 2);
	clean_t(game->mlx, game->images.scene02_e, 2);
	clean_t(game->mlx, game->images.scene02_f, 2);
	clean_t(game->mlx, game->images.scene02_g, 2);
	clean_t(game->mlx, game->images.scene02_h, 2);
}

void	cleanup(t_game *game)
{
	clean_scenes_images(game);
	clean_scenes_tex(game);
	if (game->textures.cursor_a)
		mlx_delete_texture(game->textures.cursor_a);
	if (game->textures.cursor_b)
		mlx_delete_texture(game->textures.cursor_b);
	if (game->images.cursor_a)
		mlx_delete_image(game->mlx, game->images.cursor_a);
	if (game->images.cursor_b)
		mlx_delete_image(game->mlx, game->images.cursor_b);
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->fade)
		mlx_delete_image(game->mlx, game->fade);
	if (game->mlx)
		mlx_terminate(game->mlx);
	game->mlx = NULL;
}
