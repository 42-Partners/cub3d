/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:18:39 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/27 12:36:30 by devrafaelly      ###   ########.fr       */
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
	if (game->map.map_fd != -1)
		close(game->map.map_fd);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.map)
		ft_free_arr(&game->map.map);
	if (game->map.copy)
		ft_free_arr(&game->map.copy);
	clean_gnl(game->map.map_fd);
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
		ft_fprintf(2, "Error: %s\n", msg);
	else
		ft_fprintf(2, "Error: %s\n", mlx_strerror(mlx_get_errno()));
	cleanup(game);
	exit(EXIT_FAILURE);
}

void	clean_gnl(int fd)
{
	char	*aux;

	aux = get_next_line(fd);
	while (aux)
	{
		free(aux);
		aux = get_next_line(fd);
	}
}
