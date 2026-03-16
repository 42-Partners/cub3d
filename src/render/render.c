/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:06:31 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/13 18:12:23 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_frame(t_game *game)
{
	ft_memset(game->img->pixels, 0,
		game->img->width * game->img->height * sizeof(uint32_t));
}

void	render(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clear_frame(game);
	render_frame(game);
}
