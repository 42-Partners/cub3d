/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:46:26 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/01 16:16:33 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_movement(t_game *game)
{
	if (game->input.a)
		return ;
	else if (game->input.d)
		return ;
	else if (game->input.s)
		return ;
	else if (game->input.w)
		return ;
}

void	handle_rotation(t_game *game)
{
	if (game->input.right)
		return ;
	else if (game->input.left)
		return ;
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	
	new_x = game->player.pos_x + game->player.dir_x * move_speed;
	new_y = game->player.pos_y + game->player.dir_y * move_speed;
}
