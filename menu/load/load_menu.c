/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:31:42 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 02:27:32 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	load_menu(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		if (!game->start)
			handle_click_scene01(game);
		else
			handle_click_scene02(game);
	}
	handle_scene(game);
}
