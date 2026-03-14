/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:05:16 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/14 07:41:07 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map(int map_fd, t_game *game)
{
	bool	player;
	bool	completed;
	char	*last_line;
	char	*line;

	(void)game;
	player = false;
	completed = false;
	line = get_next_line(map_fd);
	last_line = NULL;
	while (line)
	{
		if (!last_line)
		line = get_next_line(map_fd);
	}
	return (player && completed);
}
