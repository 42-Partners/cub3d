/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:05:16 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/11 19:14:33 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <fcntl.h>

int	validate_map(t_game *game, char *filename)
{
	int	map_fd;

	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		error_exit(game, "Could not open the file.");
	return (map_fd);
}
