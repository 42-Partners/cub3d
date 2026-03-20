/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:18:39 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/20 01:37:59 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdlib.h>

void	cleanup(t_game *game)
{
	if (game->textures.so)
		mlx_delete_texture(game->textures.so);
	if (game->textures.no)
		mlx_delete_texture(game->textures.no);
	if (game->textures.we)
		mlx_delete_texture(game->textures.we);
	if (game->textures.ea)
		mlx_delete_texture(game->textures.ea);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game->map);
}

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup(game);
	exit(EXIT_SUCCESS);
}

void	error_exit(t_game *game, char *msg)
{
	if (msg)
		printf("Error: %s\n", msg);
	else
		printf("Error: %s\n", mlx_strerror(mlx_get_errno()));
	cleanup(game);
	exit(EXIT_FAILURE);
}
