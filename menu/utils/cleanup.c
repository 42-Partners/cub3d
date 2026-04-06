/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:18:39 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/05 21:37:08 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

#include <stdlib.h>

static void	cleanup(t_game *game)
{
	(void)game;
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
