/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:52:33 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/12 19:55:31 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		handle_movement(t_game *game);
void		handle_rotation(t_game *game);
static void	handle_keypress(mlx_key_data_t keydata, t_game *game);
static void	handle_keyrelease(mlx_key_data_t keydata, t_game *game);
static void	handle_keyrepeat(t_game *game);

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
		handle_keypress(keydata, game);
	else if (keydata.action == MLX_RELEASE)
		handle_keyrelease(keydata, game);
	else if (keydata.action == MLX_REPEAT)
		handle_keyrepeat(game);
}

static void	handle_keypress(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		close_window((void *)game);
	else if (keydata.key == MLX_KEY_A)
		game->input.a = true;
	else if (keydata.key == MLX_KEY_D)
		game->input.d = true;
	else if (keydata.key == MLX_KEY_S)
		game->input.s = true;
	else if (keydata.key == MLX_KEY_W)
		game->input.w = true;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->input.right = true;
	else if (keydata.key == MLX_KEY_LEFT)
		game->input.left = true;
}

static void	handle_keyrelease(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_A)
		game->input.a = false;
	else if (keydata.key == MLX_KEY_D)
		game->input.d = false;
	else if (keydata.key == MLX_KEY_S)
		game->input.s = false;
	else if (keydata.key == MLX_KEY_W)
		game->input.w = false;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->input.right = false;
	else if (keydata.key == MLX_KEY_LEFT)
		game->input.left = false;
}

static void	handle_keyrepeat(t_game *game)
{
	handle_movement(game);
	handle_rotation(game);
}
