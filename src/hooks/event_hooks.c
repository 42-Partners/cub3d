/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:44:09 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/11 18:09:47 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup(game);
	exit(EXIT_SUCCESS);
}
