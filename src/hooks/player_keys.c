/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:46:26 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/12 19:57:05 by devrafaelly      ###   ########.fr       */
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
